/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:34:43 by marina            #+#    #+#             */
/*   Updated: 2020/11/27 19:38:20 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_pixel	skin_pixel(t_cub3d *cub3d, double ray, double y)
{
	double	ang;
	double	x;

	ang = atan2(cub3d->sprite->data.p.y - cub3d->player.p.y,
	cub3d->sprite->data.p.x - cub3d->player.p.x);
	x = (tan(ang - dtor(ray)) * cub3d->sprite->data.dist);
	if (x < 0)
		x = 0.5 + x;
	else
		x += 0.5;
	if (x > 1 || x < 0)
		return (pixel(0));
	return (cub3d->sprite->image->draw[((int)(y * cub3d->sprite->image->height)
	* cub3d->sprite->image->width + (int)(x * cub3d->sprite->image->width))]);
}


void	draw_or_not(double rad, t_cub3d *cub3d, int i , double ray)
{
	int			j;
	double		h;

	h = (cub3d->height / 2) - ((cub3d->width / 2 - cub3d->fov / 2) /
	(cub3d->sprite->data.dist));
	if ((sin(rad) * cub3d->sprite->data.dist <= 0.5) &&
	(sin(rad) * cub3d->sprite->data.dist >= -0.5))
	{
		cub3d->distances[i] = cub3d->sprite->data.dist;
		j = h;
		while (j < cub3d->height - h)
		{
			draw_pixel(i, j, skin_pixel(cub3d, ray,
			(double)(j - h) / ((double)cub3d->height - 2 * h)), cub3d);
			j++;
		}
	}
}

void	draw_sprites(t_cub3d *cub3d, double ray, int i)
{
	double		rad;
	t_sprite	*bin;

	rad = atan2(cub3d->sprite->data.p.y - cub3d->player.p.y,
	cub3d->sprite->data.p.x - cub3d->player.p.x) - dtor(ray);
	cub3d->sprite->data.dist = cub3d->sprite->data.dist / cos(rad);
	draw_or_not(rad, cub3d, i, ray);
	bin = cub3d->sprite;
	cub3d->sprite = cub3d->sprite->closer;
	my_free(bin);
	if (cub3d->sprite)
		draw_sprites(cub3d, ray, i);
}
