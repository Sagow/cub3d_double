/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:54:43 by marina            #+#    #+#             */
/*   Updated: 2020/11/30 13:14:52 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		my_free(void *pointer)
{
	if (pointer)
	{
		free(pointer);
		pointer = NULL;
	}
}

int			space(char *line, int i)
{
	if (!line)
		return (-2);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i])
		return (i);
	return (-1);
}

void		check_processed(t_cub3d *cub3d)
{
	if (!cub3d->width || !cub3d->height)
		ft_error(DESC_MISSING, "resolution", cub3d);
	if (!cub3d->ceiling.a)
		ft_error(DESC_MISSING, "ceiling", cub3d);
	if (!cub3d->floor.a)
		ft_error(DESC_MISSING, "floor", cub3d);
	if (!cub3d->skins)
		ft_error(DESC_MISSING, "sprite", cub3d);
	if (!cub3d->east.ptr)
		ft_error(DESC_MISSING, "east texture", cub3d);
	if (!cub3d->north.ptr)
		ft_error(DESC_MISSING, "north texture", cub3d);
	if (!cub3d->south.ptr)
		ft_error(DESC_MISSING, "south texture", cub3d);
	if (!cub3d->west.ptr)
		ft_error(DESC_MISSING, "west texture", cub3d);
}

void		init_cub3d(t_cub3d *cub3d)
{
	cub3d->width = 0;
	cub3d->height = 0;
	cub3d->floor.a = 0;
	cub3d->ceiling.a = 0;
	cub3d->skins = NULL;
	cub3d->east.ptr = NULL;
	cub3d->north.ptr = NULL;
	cub3d->south.ptr = NULL;
	cub3d->west.ptr = NULL;
	cub3d->map = NULL;
	cub3d->player.p.x = -1;
	cub3d->player.p.y = -1;
}
