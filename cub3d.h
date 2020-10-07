/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:52:50 by marina            #+#    #+#             */
/*   Updated: 2020/10/08 00:14:21 by marina           ###   ########.fr       */
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
# ifndef M_PI
#  define M_PI 3.14
# endif
/*
**angle's range [0;360[
*/

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_obj
{
	t_pos		p;
	double		ang;
	char		dir;
}				t_obj;

typedef struct	s_case
{
	char		wall;
	double		dist;
	t_pos		p;
}				t_case;

typedef struct	s_line
{
	t_pos		p1;
	t_pos		p2;
}				t_line;

typedef struct		s_text
{
	void			*ptr;
	unsigned int	*draw;
	int				width;
	int				height;
}					t_text;

typedef struct		s_cub3d
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*draw;
	t_text			*north;
	t_text			*west;
	t_text			*south;
	t_text			*east;
	unsigned int	floor;
	unsigned int	ceiling;
	int				width;
	int				height;
	int				fov;
	t_obj			player;
	char			**map;
	int				map_x;
	int				map_y;
}					t_cub3d;

void		draw_pixel(int x, int y, unsigned int colour, t_cub3d *cub3d);
void		aerial(t_cub3d *cub3d);
t_line		fill_t_line(double a, double b, double c, double d);

void		mapping(int fd, t_cub3d *cub3d);
void		my_free(void *pointer);

t_case		reaching_obstacle(double ray, 
t_cub3d *cub3d);

double		simplifier(double angle);
double		dtor(double angle);

#endif