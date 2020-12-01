/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:02:17 by marina            #+#    #+#             */
/*   Updated: 2020/12/01 16:07:24 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_sprite(t_sprite *link)
{
	if (link)
	{
		if (link->closer)
			free_sprite(link->closer);
		//my_free(link->image);
		free(link);
		link = NULL;
	}
}

void	add_sprite(t_cub3d *cub3d, t_case spot, char type)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return ;
	new->closer = cub3d->sprite;
	new->data.p.x = (int)spot.p.x + 0.5;
	new->data.p.y = (int)spot.p.y + 0.5;
	new->data.dist = hypot(new->data.p.x - cub3d->player.p.x,
	new->data.p.y - cub3d->player.p.y);
	new->data.wall = type;
	new->image = &(cub3d->skin);
	cub3d->sprite = new;
}
