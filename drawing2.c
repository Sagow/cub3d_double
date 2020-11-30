/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:10:42 by marina            #+#    #+#             */
/*   Updated: 2020/11/27 13:13:10 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_pixel	texture(t_case wall, double y, t_text *text)
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
	return (text->draw[((int)(y * text->height) * text->width +
	(int)(x * text->width))]);
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

	h = (cub3d->height / 2) - ((cub3d->width / 2 - cub3d->fov / 2) / (wall.dist
	* cos(dtor(((double)(i * cub3d->fov) / cub3d->width) - cub3d->fov / 2))));
	t = get_text(wall, cub3d);
	j = 0;
	while (j < h)
	{
		draw_pixel(i, j, cub3d->ceiling, cub3d);
		j++;
	}
	while (j < cub3d->height - h && j < cub3d->height)
	{
		draw_pixel(i, j, texture(wall, (double)(j - h) /
		((double)cub3d->height - 2 * h), t), cub3d);
		j++;
	}
	while (j < cub3d->height)
	{
		draw_pixel(i, j, cub3d->floor, cub3d);
		j++;
	}
}

t_text 	*get_text(t_case wall, t_cub3d *cub3d)
{
	if (wall.wall == 'N')
		return (&cub3d->north);
	else if (wall.wall == 'W')
		return (&cub3d->west);
	else if (wall.wall == 'S')
		return (&cub3d->south);
	else
		return (&cub3d->east);
}
