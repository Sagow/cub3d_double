/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:13:04 by marina            #+#    #+#             */
/*   Updated: 2020/11/30 13:28:01 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			get_color(char *line, int *i, unsigned char *value, t_cub3d
*cub3d)
{
	int color;

	color = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		color = color * 10 + (int)(line[*i] - '0');
		*i = *i + 1;
	}
	if (color > 255)
		ft_error(DESC_COLOR, "floor or ceiling", cub3d);
	*value = (char)color;
}

void			fp_ceiling(t_cub3d *cub3d, char *line, int i)
{
	if (cub3d->ceiling.a)
		ft_error(DESC_ALREADY, "ceiling", cub3d);
	cub3d->ceiling.a = 255;
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMP, "ceiling", cub3d);
	get_color(line, &i, &cub3d->ceiling.r, cub3d);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMP, "ceiling", cub3d);
	if (line[i] != ',')
		ft_error(DESC_COLOR, "ceiling", cub3d);
	i = space(line, ++i);
	get_color(line, &i, &cub3d->ceiling.g, cub3d);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMP, "ceiling", cub3d);
	if (line[i] != ',')
		ft_error(DESC_COLOR, "ceiling", cub3d);
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMP, "ceiling", cub3d);
	get_color(line, &i, &cub3d->ceiling.b, cub3d);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "ceiling", cub3d);
}

void			fp_floor(t_cub3d *cub3d, char *line, int i)
{
	if (cub3d->floor.a)
		ft_error(DESC_ALREADY, "floor", cub3d);
	cub3d->floor.a = 255;
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMP, "floor", cub3d);
	get_color(line, &i, &cub3d->floor.r, cub3d);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMP, "floor", cub3d);
	if (line[i] != ',')
		ft_error(DESC_COLOR, "floor", cub3d);
	i = space(line, ++i);
	get_color(line, &i, &cub3d->floor.g, cub3d);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMP, "floor", cub3d);
	if (line[i] != ',')
		ft_error(DESC_COLOR, "floor", cub3d);
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMP, "floor", cub3d);
	get_color(line, &i, &cub3d->floor.b, cub3d);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "floor", cub3d);
}
