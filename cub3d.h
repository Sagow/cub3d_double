/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:52:50 by marina            #+#    #+#             */
/*   Updated: 2020/10/18 04:58:29 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
#include "mlx.h"
#include "mlx_int.h"
# ifndef M_PI
#  define M_PI 3.14
# endif
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
	int				fov;
	t_obj			player;
	t_sprite		*sprite;
	t_skin			*skins;
	char			**map;
	int				map_x;
	int				map_y;
}					t_cub3d;

void				draw_pixel(int x, int y, t_pixel colour, t_cub3d *cub3d);
void				aerial(t_cub3d *cub3d);
t_line				fill_t_line(double a, double b, double c, double d);

void				mapping(int fd, t_cub3d *cub3d);
void				my_free(void *pointer);

t_case				reaching_obstacle(double ray, t_cub3d *cub3d);
void				intersect(t_case *spot, t_line beam, t_line wall);

double				simplifier(double angle);
double				dtor(double angle);
double				rtod(double	rad);

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

void				fp_map(t_cub3d *cub3d, int fd, char *line, int i);

void				check_processed(t_cub3d *cub3d);
void				ft_error(char *message, char *place);

t_pixel				pixel(unsigned int color);
//void test_verif_sprite(t_cub3d *cub3d);


#endif