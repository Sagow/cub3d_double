/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aerial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:17:36 by marina            #+#    #+#             */
/*   Updated: 2020/10/07 23:39:45 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define COLOR_EMPTY 0xFF000000
#define COLOR_WALL 0xFFA0A0A0
#define COLOR_BEAM 0xFFFFFFFF
#define COLOR_ERROR 0xFFFF0000

void	draw_map(t_cub3d *cub3d, double factor)
{
	int	x;
	int	y;
	char	c;

	x = 0;
	//printf("factor = %ld, x max = %d, y max = %d\n", factor, (int)(strlen(cub3d->my_map->map[0]) * factor), (int)((cub3d->my_map->max_line + 1) * factor));
	//printf("l 1 map = %s, strlen = %d\n", cub3d->my_map->map[0], strlen(cub3d->my_map->map[0]));
	while (x < (cub3d->map_x * factor) && x < cub3d->width)
	{
		y = 0;
		while (y < (int)(cub3d->map_y * factor) && y < cub3d->height)
		{
			c = cub3d->map[(int)(y / factor)][(int)(x / factor)];
			//printf("%d:%d  c = %c\n",(int)(y / factor / S_CUB), (int)(x / factor / S_CUB), c);
			if (c == '0')
				draw_pixel(x, y, COLOR_EMPTY, cub3d);
			else if (c == '1')
				draw_pixel(x, y, COLOR_WALL, cub3d);
			else
				draw_pixel(x, y, COLOR_ERROR, cub3d);
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
		draw_pixel((int)(p.p1.x + dx * i), (int)(p.p1.y + dy * i), color, cub3d);
}

void	draw_beams(t_cub3d *cub3d, double factor)
{
	t_case		spot;
	double		mx;
	double		my;
	double		x;
	double		y;
	double		ray;
	t_line		p;

	ray = simplifier(cub3d->player.ang);
	//while (ray != (simplifier(cub3d->cur->eye->deg + cub3d->fov / 2)))
	//{
		//printf("boucle\n");
		spot = reaching_obstacle(ray, cub3d);
		p.p1.x = (cub3d->player.p.x) * factor;
		p.p1.y = ((cub3d->map_y) - (cub3d->player.p.y)) * factor;
		p.p2.x = (p.p1.x / factor + cos(dtor(-ray)) * 2000) * factor;
		p.p2.y = (p.p1.y / factor + sin(dtor(-ray)) * 2000) * factor;
		draw_line(p, 0xFF0000, cub3d);
		p.p2.x = spot.p.x * factor;
		p.p2.y = (cub3d->map_y - spot.p.y) * factor;
		draw_line(p, 0xFFFFFF, cub3d);
		ray = simplifier(ray + ((double)1/8));
	//}
}

void	aerial(t_cub3d *cub3d)
{
	double factor;

	factor = (double)cub3d->width / ((double)cub3d->map_x);
	factor /= 1.2;
	//printf("factor = %lf, strlen * S_cub = %lu, width = %d\n", factor, strlen(cub3d->my_map->map[0]) * S_CUB, cub3d->width);
	if ((double)cub3d->height / ((double)(cub3d->map_y)) < factor)
		factor = (double)cub3d->height / ((double)(cub3d->map_y));
	//printf("factor = %lf, nb lines * S_CUB = %lu, height = %d\n", factor, (cub3d->my_map->max_line + 1) * S_CUB, cub3d->height);
	draw_map(cub3d, factor);
	draw_beams(cub3d, factor);
}