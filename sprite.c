/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:02:17 by marina            #+#    #+#             */
/*   Updated: 2020/11/24 12:35:36 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_sprite(t_sprite *link)
{
	if (link)
	{
		if (link->closer)
			free_sprite(link->closer);
		free(link);
		link = NULL;
	}
}

void	get_skin(t_cub3d *cub3d, t_sprite *new, char type)
{
	int	i;

	i = 0;
	while (cub3d->skins[i].type && cub3d->skins[i].type != type)
		i++;
	if (cub3d->skins[i].type)
		new->image = &cub3d->skins[i].skin;
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
	get_skin(cub3d, new, type);
	cub3d->sprite = new;
}
