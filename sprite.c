/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:02:17 by marina            #+#    #+#             */
/*   Updated: 2020/10/10 05:48:21 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprite(t_sprite *link)
{
	printf("free\n");
	
	if (link)
	{
		if (link->closer)
			free_sprite(link->closer);
		free(link);
		link = NULL;
	}
}

/*
**tenter de passer par adresse !
*/
t_text	get_skin(t_cub3d *cub3d, char type)
{
	printf("get\n");

	while (cub3d->skins->type && cub3d->skins->type != type)
		cub3d->skins++;
	return (cub3d->skins->skin);
}

void	add_sprite(t_cub3d *cub3d, t_case spot, char type, double ray)
{
	t_sprite	*new;
	t_line		beam;
	t_line		sprite;

	printf("add\n");
	if (!(new = malloc(sizeof(t_sprite))))
		return ;
	new->closer = cub3d->sprite;
	new->data.p.x = (int)spot.p.x + 0.5;
	new->data.p.y = (int)spot.p.y + 0.5;
	new->data.dist = hypot(spot.p.x - cub3d->player.p.x, spot.p.y - cub3d->player.p.y);
	new->data.wall = type;
	new->image = get_skin(cub3d, type);
	cub3d->sprite = new;
}