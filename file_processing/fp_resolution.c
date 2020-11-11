/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:45:43 by marina            #+#    #+#             */
/*   Updated: 2020/11/11 06:38:45 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			get_value(char *line, int *i, int value)
{
	int test;

	test = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		test = test * 10 + (int)(line[*i] - '0');
		*i = *i + 1;
	}
	if (test > value)
		return (value);
	return (test);
}

void		fp_resolution(t_cub3d *cub3d, char *line, int i)
{
	int		w;
	int		h;

	if (cub3d->width || cub3d->height)
		ft_error(DESC_ALREADY, "resolution");
	mlx_get_screen_size(cub3d->mlx, &w, &h);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "resolution");
	w = get_value(line, &i, w);
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "resolution");
	h = get_value(line, &i, h);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "resolution");
	cub3d->width = w;
	cub3d->height = h;
}
