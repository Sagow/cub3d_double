/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:52:29 by marina            #+#    #+#             */
/*   Updated: 2020/11/30 14:19:36 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		click(t_cub3d *cub3d)
{
	cub3d->fov = 0;
	my_exit(cub3d);
	return (0);
}

void	my_exit(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map && cub3d->map[i])
	{
		my_free(cub3d->map[i]);
		i++;
	}
	my_free(cub3d->map);
	free_sprite(cub3d->sprite);
	my_free(cub3d->distances);
	i = mlx_destroy_image(cub3d->mlx, cub3d->skins->skin.ptr);
	my_free(cub3d->skins);
	exit(0);
}