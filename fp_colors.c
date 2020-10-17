/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:13:04 by marina            #+#    #+#             */
/*   Updated: 2020/10/17 01:19:37 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	get_color(char *line, int *i, unsigned char *value)
{
	int color;

	color = 0;
	while(line[*i] >= '0' && line[*i] <= '9')
	{
		color = color * 10 + (int)(line[*i] - '0');
		*i = *i + 1;
	}
	if (color > 255)
		ft_error(DESC_COLOR, "floor or ceiling");
	*value = (char)color;
}

void			fp_ceiling(t_cub3d *cub3d, char *line, int i)
{
	if (cub3d->ceiling.a)
		ft_error(DESC_ALREADY, "ceiling");
	cub3d->ceiling.a = 255;
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "ceiling");
	get_color(line, &i, &cub3d->ceiling.r);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "ceiling");
	if (line[i] != ',')
		ft_error(DESC_COLOR, "ceiling");
	i = space(line, ++i);
	get_color(line, &i, &cub3d->ceiling.g);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "ceiling");
	if (line[i] != ',')
		ft_error(DESC_COLOR, "ceiling");
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMPLETE, "ceiling");
	get_color(line, &i, &cub3d->ceiling.b);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "ceiling");
}

void			fp_floor(t_cub3d *cub3d, char *line, int i)
{
	if (cub3d->floor.a)
		ft_error(DESC_ALREADY, "floor");
	cub3d->floor.a = 255;
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "floor");
	get_color(line, &i, &cub3d->floor.r);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "floor");
	if (line[i] != ',')
		ft_error(DESC_COLOR, "floor");
	i = space(line, ++i);
	get_color(line, &i, &cub3d->floor.g);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "floor");
	if (line[i] != ',')
		ft_error(DESC_COLOR, "floor");
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMPLETE, "floor");
	get_color(line, &i, &cub3d->floor.b);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "floor");
}
