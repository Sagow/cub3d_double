/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:38:41 by marina            #+#    #+#             */
/*   Updated: 2020/12/01 15:23:36 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->win = NULL;
	cub3d->img = NULL;
	cub3d->draw = NULL;
	cub3d->distances = NULL;
	cub3d->sprite = NULL;
	cub3d->skin.ptr = NULL;
	cub3d->map = NULL;
	cub3d->width = 0;
	cub3d->height = 0;
	cub3d->floor.a = 0;
	cub3d->ceiling.a = 0;
	cub3d->east.ptr = NULL;
	cub3d->north.ptr = NULL;
	cub3d->south.ptr = NULL;
	cub3d->west.ptr = NULL;
	cub3d->player.p.x = -1;
	cub3d->player.p.y = -1;
	cub3d->fov = 60;
	cub3d->show_map = 0;
}