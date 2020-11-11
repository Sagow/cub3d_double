/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 06:20:43 by marina            #+#    #+#             */
/*   Updated: 2020/11/11 06:40:48 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	move_forward(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->map_y -
	(cub3d->player.p.y + sin(dtor(cub3d->player.ang)) / SPEED))]
	[(int)(cub3d->player.p.x - cos(dtor(cub3d->player.ang)) / SPEED)] == '0')
	{
		cub3d->player.p.x += cos(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y += sin(dtor(cub3d->player.ang)) / SPEED;
	}
}

void	move_backward(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->map_y -
	(cub3d->player.p.y - sin(dtor(cub3d->player.ang)) / SPEED))]
	[(int)(cub3d->player.p.x - cos(dtor(cub3d->player.ang)) / SPEED)] == '0')
	{
		cub3d->player.p.x -= cos(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y -= sin(dtor(cub3d->player.ang)) / SPEED;
	}
}

void	move_left(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->map_y -
	(cub3d->player.p.y + cos(dtor(cub3d->player.ang)) / SPEED))]
	[(int)(cub3d->player.p.x - sin(dtor(cub3d->player.ang)) / SPEED)] == '0')
	{
		cub3d->player.p.x -= sin(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y += cos(dtor(cub3d->player.ang)) / SPEED;
	}
}

void	move_right(t_cub3d *cub3d)
{
	if (cub3d->map[(int)(cub3d->map_y -
	(cub3d->player.p.y - cos(dtor(cub3d->player.ang)) / SPEED))]
	[(int)(cub3d->player.p.x + sin(dtor(cub3d->player.ang)) / SPEED)] == '0')
	{
		cub3d->player.p.x += sin(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y -= cos(dtor(cub3d->player.ang)) / SPEED;
	}
}
