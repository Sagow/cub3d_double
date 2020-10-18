/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aerial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:17:36 by marina            #+#    #+#             */
/*   Updated: 2020/10/18 02:02:11 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define COLOR_EMPTY 0xFF000000
#define COLOR_WALL 0xFFA0A0A0
#define COLOR_BEAM 0xFFFFFFFF
#define COLOR_ERROR 0xFFFF0000

t_pixel	pixel(unsigned int color)
{
	t_pixel		res;

	res.b = color % 256;
	res.g = color / 256 % 256;
	res.r = color / 256 / 256 % 256;
	res.a = color / 256 / 256 / 256 % 256;
	return (res);
}

void	draw_map(t_cub3d *cub3d, double factor)
{
	int	x;
	int	y;
	char	c;

	x = 0;
	while (x < (cub3d->map_x * factor) && x < cub3d->width)
	{
		y = 0;
		while (y < (int)(cub3d->map_y * factor) && y < cub3d->height)
		{
			c = cub3d->map[(int)(y / factor)][(int)(x / factor)];
			if (c == '0')
				draw_pixel(cub3d->width - x, y, pixel(COLOR_EMPTY), cub3d);
			else if (c == '1')
				draw_pixel(cub3d->width - x, y, pixel(COLOR_WALL), cub3d);
			else
				draw_pixel(cub3d->width - x, y, pixel(COLOR_ERROR), cub3d);
			y++;
		}
		x++;
	}
}

void	draw_line(t_line p, unsigned int color, t_cub3d *cub3d)
{
	double	dx;
	double	dy;
	double	steps;
	int		i;

	dx = p.p2.x - p.p1.x;
	dy = p.p2.y - p.p1.y;
	steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= steps;
	dy /= steps;
	i = -1;
	while (++i < (int)steps)
		draw_pixel(cub3d->width - (int)(p.p1.x + dx * i), (int)(p.p1.y + dy * i), pixel(color), cub3d);
}

void	draw_beams(t_cub3d *cub3d, double factor)
{
	double		ray;
	t_line		p;
	int			i;
	
	i = 0;
	while (i < cub3d->width)
	{
		ray = (double)i * (double)cub3d->fov / (double)cub3d->width;
		ray -= cub3d->fov / 2;
		ray = simplifier(ray + cub3d->player.ang);
		p.p1.x = (cub3d->player.p.x) * factor;
		p.p1.y = ((cub3d->map_y) - (cub3d->player.p.y)) * factor;
		p.p2.x = (p.p1.x / factor + cos(dtor(-ray)) * cub3d->distances[i]) * factor;
		p.p2.y = (p.p1.y / factor + sin(dtor(-ray)) * cub3d->distances[i]) * factor;
		draw_line(p, 0xAFFFFFFE, cub3d);
		i++;
	}
}

void	aerial(t_cub3d *cub3d)
{
	double factor;

	factor = (double)cub3d->width / ((double)cub3d->map_x);
	factor /= 1.2;
	if ((double)cub3d->height / ((double)(cub3d->map_y)) < factor)
		factor = (double)cub3d->height / ((double)(cub3d->map_y));
	draw_map(cub3d, factor);
	draw_beams(cub3d, factor);
}