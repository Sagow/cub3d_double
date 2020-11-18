/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:34:43 by marina            #+#    #+#             */
/*   Updated: 2020/11/16 16:37:02 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_pixel	texture(t_case	wall, double y, t_text *text)
{
	double	x;

	if (wall.wall == 'W')
		x = 1 - (wall.p.y - (double)(int)wall.p.y);
	if (wall.wall == 'S')
		x = wall.p.x - (double)(int)wall.p.x;
	if (wall.wall == 'E')
		x = (wall.p.y - (double)(int)wall.p.y);
	if (wall.wall == 'N')
		x = 1 - (wall.p.x - (double)(int)wall.p.x);
	return (text->draw[((int)(y * text->height) * text->width + (int)(x * text->width))]);
}

void	draw_pixel(int x, int y, t_pixel colour, t_cub3d *cub3d)
{
	if (x >= 0 && x < cub3d->width && y >= 0 && y < cub3d->height && colour.a)
		cub3d->draw[y * cub3d->width + (cub3d->width - 1 - x)] = colour;
}

void	draw_col(t_cub3d *cub3d, t_case wall, int i)
{
	double	h;
	int		j;
	t_text	*t;

	h = (cub3d->height / 2) - ((cub3d->width / 2 - cub3d->fov / 2) / (wall.dist * cos(dtor(((double)(i * cub3d->fov) / cub3d->width) - cub3d->fov / 2))));
	if (wall.wall == 'N')
		t = &cub3d->north;
	else if (wall.wall == 'W')
		t = &cub3d->west;
	else if (wall.wall == 'S')
		t = &cub3d->south;
	else
		t = &cub3d->east;
	j = 0;
	while (j < h)
	{
		draw_pixel(i, j, cub3d->ceiling, cub3d);
		j++;
	}
	while (j < cub3d->height - h && j < cub3d->height)
	{
		draw_pixel(i, j, texture(wall, (double)(j - h) / ((double)cub3d->height - 2 * h), t), cub3d);
		j++;
	}
	while (j < cub3d->height)
	{
		draw_pixel(i, j, cub3d->floor, cub3d);
		j++;
	}
}

t_pixel	skin_pixel(t_cub3d *cub3d, double ray, double y)
{
	double	ang;
	double	x;

	ang = atan2(cub3d->sprite->data.p.y - cub3d->player.p.y, cub3d->sprite->data.p.x - cub3d->player.p.x);	
	x = (tan(ang - dtor(ray)) * cub3d->sprite->data.dist);
	if (x < 0)
		x = 0.5 + x;
	else
		x += 0.5;

	if (x > 1 || x < 0)
		return (pixel(0));
	return (cub3d->sprite->image->draw[((int)(y * cub3d->sprite->image->height) * cub3d->sprite->image->width + (int)(x * cub3d->sprite->image->width))]);
}

void	draw_sprites(t_cub3d *cub3d, double ray, int i)
{
	int		j;
	double	h;
	double	rad;
	t_sprite	*bin;

	rad = atan2(cub3d->sprite->data.p.y - cub3d->player.p.y, cub3d->sprite->data.p.x - cub3d->player.p.x) - dtor(ray);
	cub3d->sprite->data.dist = cub3d->sprite->data.dist / cos(rad);
	h = (cub3d->height / 2) - ((cub3d->width / 2 - cub3d->fov / 2) / (cub3d->sprite->data.dist));
	if ((sin(rad) * cub3d->sprite->data.dist <= 0.5) && (sin(rad) * cub3d->sprite->data.dist >= -0.5))
	{
		cub3d->distances[i] = cub3d->sprite->data.dist;
		j = h;
		while (j < cub3d->height - h)
		{
			draw_pixel(i, j, skin_pixel(cub3d, ray, (double)(j - h) / ((double)cub3d->height - 2 * h)), cub3d);
			j++;
		}
	}
	bin = cub3d->sprite;
	cub3d->sprite = cub3d->sprite->closer;
	my_free(bin);
	if (cub3d->sprite)
		draw_sprites(cub3d, ray, i);
}
