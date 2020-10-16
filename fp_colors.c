/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:13:04 by marina            #+#    #+#             */
/*   Updated: 2020/10/16 06:42:07 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


unsigned int	get_color(char *line, int *i, unsigned int color, unsigned int cmp)
{
	while(line[*i] >= '0' && line[*i] <= '9')
	{
		color = color * 10 + (unsigned int)(line[*i] - '0');
		*i = *i + 1;
	}
	if (color > cmp)
		error(DESC_COLOR, "floor or ceiling");
	return (color);
}

void			fp_ceiling(t_cub3d *cub3d, char *line, int i)
{
	unsigned int	color;

	if (cub3d->floor)
		error(DESC_ALREADY, "ceiling");
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "ceiling");
	color = get_color(line, &i, color, 0x0000FF);
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "ceiling");
	if (line[i] != ',')
		error(DESC_COLOR, "ceiling");
	i = space(line, i);
	color = get_color(line, &i, color, 0x00FFFF);
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "ceiling");
	if (line[i] != ',')
		error(DESC_COLOR, "ceiling");
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "ceiling");
	color = get_color(line, &i, color, 0xFFFFFF);
	if ((i = space(line, i)) != -1)
		error(DESC_WRONG_CHAR, "ceiling");
	cub3d->ceiling = color;
}

void			fp_floor(t_cub3d *cub3d, char *line, int i)
{
	unsigned int	color;

	if (cub3d->floor)
		error(DESC_ALREADY, "floor");
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "floor");
	color = get_color(line, &i, color, 0x0000FF);
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "floor");
	if (line[i] != ',')
		error(DESC_COLOR, "floor");
	i = space(line, i);
	color = get_color(line, &i, color, 0x00FFFF);
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "floor");
	if (line[i] != ',')
		error(DESC_COLOR, "floor");
	if ((i = space(line, i)) == -1)
		error(DESC_INCOMPLETE, "floor");
	color = get_color(line, &i, color, 0xFFFFFF);
	if ((i = space(line, i)) != -1)
		error(DESC_WRONG_CHAR, "floor");
	cub3d->floor = color;
}
