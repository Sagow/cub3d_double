/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:52:50 by marina            #+#    #+#             */
/*   Updated: 2020/11/23 21:33:11 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"
# include "../libftprintf/printf.h"
# include <sys/stat.h> 
# include <fcntl.h>
# include "mlx.h"
# include "mlx_int.h"
# ifndef M_PI
#  define M_PI 3.1415
# endif
# define OPEN_FAIL "The .cub couldn't be open, please check the spelling."
# define ARG_FEW "No descriptive file in the call."
# define ARG_MANY "Too many arguments given."
# define ARG_SAVE "The second argument seems odd, did you mean --save ?"
# define ARG_CUB "The descriptive file's name doesn't end with \".cub\"."
# define MAP_OPEN "The map is not closed with walls."
# define MAP_NO_PLAYER "No player detected in the map."
# define MAP_WRONG_CHAR "Unexpected character in the map."
# define MAP_SVRL_PLAYERS "A second player has been detected in the map"
# define DESC_WRONG_CHAR "Unexpected character in the description."
# define DESC_INCOMPLETE "The description of one of the parameters is incomplete."
# define DESC_ALREADY "This parameter has already been initialized."
# define DESC_PATH "Wrong path."
# define DESC_COLOR "The description of the color seems wrong."
# define DESC_MISSING "At least one parameter is missing."
# define DESC_GNL "There has been a problem in get_next_line."
# define MALLOC_FAIL "There has been a problem during memory allocation."
# define FILE_CREATION "The file couldn't be created to save the picture."
# define DEPARTX 2
# define DEPARTY 2
# define PIC_WIDTH 500
# define PLAYER_SCREEN 200
# define UNITY 128
# define KEY_Z 119
# define KEY_Q 97
# define KEY_S 115
# define KEY_D 100
# define KEY_M 59
# define SPEED 10
/*
**angle's range [0;360[
*/

typedef struct		s_fp_map
{
	struct s_fp_map	*next;
	char			*line;
}					t_fp_map;

typedef struct		s_pixel
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_pixel;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_obj
{
	t_pos			p;
	double			ang;
	char			dir;
}					t_obj;

typedef struct		s_case
{
	char			wall;
	double			dist;
	t_pos			p;
}					t_case;

typedef struct		s_line
{
	t_pos			p1;
	t_pos			p2;
}					t_line;

typedef struct		s_text
{
	void			*ptr;
	t_pixel			*draw;
	int				width;
	int				height;
}					t_text;

typedef struct		s_sprite
{
	struct s_sprite	*closer;
	t_text			*image;
	t_case			data;
}					t_sprite;

typedef struct		s_skin
{
	char			type;
	t_text			skin;
}					t_skin;

typedef struct		s_cub3d
{
	void			*mlx;
	void			*win;
	void			*img;
	t_pixel			*draw;
	t_text			north;
	t_text			west;
	t_text			south;
	t_text			east;
	t_pixel			floor;
	t_pixel			ceiling;
	int				width;
	int				height;
	double			*distances;
	double			fov;
	t_obj			player;
	t_sprite		*sprite;
	t_skin			*skins;
	char			show_map;
	char			**map;
	int				map_x;
	int				map_y;
	char			save;
}					t_cub3d;

void				draw_pixel(int x, int y, t_pixel colour, t_cub3d *cub3d);
void				aerial(t_cub3d *cub3d);
t_line				fill_t_line(double a, double b, double c, double d);

void				mapping(int fd, t_cub3d *cub3d);
void				my_free(void *pointer);

t_case				reaching_obstacle(double ray, t_cub3d *cub3d);
void				intersect(t_case *spot, t_line beam, t_line wall);

void				free_sprite(t_sprite *link);
void				add_sprite(t_cub3d *cub3d, t_case spot, char type);

int					space(char *line, int i);

void				file_processing(int fd, t_cub3d *cub3d);

void				fp_resolution(t_cub3d *cub3d, char *line, int i);

void				fp_east(t_cub3d *cub3d, char *line, int i);
void				fp_north(t_cub3d *cub3d, char *line, int i);
void				fp_west(t_cub3d *cub3d, char *line, int i);
void				fp_south(t_cub3d *cub3d, char *line, int i);

void				fp_floor(t_cub3d *cub3d, char *line, int i);
void				fp_ceiling(t_cub3d *cub3d, char *line, int i);

void				fp_sprite(t_cub3d *cub3d, char *line, int i);

void				fp_map(t_cub3d *cub3d, int fd, char *line);

void				check_processed(t_cub3d *cub3d);
void				ft_error(char *message, char *place);

t_pixel				pixel(unsigned int color);

/*
** functions used by key_pressed to move (move.c)
*/
void				move_forward(t_cub3d *cub3d);
void				move_backward(t_cub3d *cub3d);
void				move_left(t_cub3d *cub3d);
void				move_right(t_cub3d *cub3d);

/*
** (detect_wall2.c)
*/
char				translate_letter(char wall);
char				right_wall(double ray, t_case spot, t_cub3d *cub3d);
char				opposite_wall(char wall);

/*
** (drawing.c)
*/
t_pixel				texture(t_case	wall, double y, t_text *text);
void				draw_pixel(int x, int y, t_pixel colour, t_cub3d *cub3d);
void				draw_col(t_cub3d *cub3d, t_case wall, int i);
t_pixel				skin_pixel(t_cub3d *cub3d, double ray, double y);
void				draw_sprites(t_cub3d *cub3d, double ray, int i);

/*
** (mathematics.c)
*/
double				simplifier(double angle);
double				dtor(double angle);
double				rtod(double	rad);
double				fmod(double number, double div);
double				ang_cal(int opp1, int opp2, int adj1, int adj2);

/*
** (fp_map2.c)
*/
void				hole(t_cub3d *cub3d, int x, int y);
void				get_player(t_cub3d *cub3d);
void				assign_player(t_cub3d *cub3d, int x, int y);
int					belongs(char c, char *charset);

void				save(t_cub3d *cub3d);
#endif