/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 04:02:17 by marina            #+#    #+#             */
/*   Updated: 2020/11/11 06:40:56 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_sprite(t_sprite *link)
{
	//printf("free\n");
	
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
void	get_skin(t_cub3d *cub3d, t_sprite *new, char type)
{
	int i;
	//printf("get\n");

	i = 0;
	while (cub3d->skins[i].type && cub3d->skins[i].type != type)
		i++;
	//printf("test\n");
		
	if (cub3d->skins[i].type)
	{
		//printf("1\n");
		new->image = &cub3d->skins[i].skin;
	}
	/*else
		printf("texture non trouvee ! %c _ %c i = %d\n", type, cub3d->skins[i].type, i);
	printf("fin get\n");*/
	
}

void	add_sprite(t_cub3d *cub3d, t_case spot, char type)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return ;
	new->closer = cub3d->sprite;
	new->data.p.x = (int)spot.p.x + 0.5;
	new->data.p.y = (int)spot.p.y + 0.5;
	new->data.dist = hypot(new->data.p.x - cub3d->player.p.x, new->data.p.y - cub3d->player.p.y);
	new->data.wall = type;
	get_skin(cub3d, new, type);
	cub3d->sprite = new;
	//printf("done\n");
}
/*
void test_verif_sprite(t_cub3d *cub3d)
{
	t_sprite	*next;

	next = cub3d->sprite;
	while (next)
	{
		printf("sprite en %lf, %lf, à %lf\n", next->data.p.x, next->data.p.y, next->data.dist);
		next = next->closer;
	}
}*/