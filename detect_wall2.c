/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:29:34 by marina            #+#    #+#             */
/*   Updated: 2020/11/24 12:58:02 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	translate_letter(char wall)
{
	if (wall % 4 == 0)
		return ('E');
	if (wall % 4 == 1)
		return ('N');
	if (wall % 4 == 2)
		return ('W');
	return ('S');
}

char	right_wall(double ray, t_case spot, t_cub3d *cub3d)
{
	double	x_base;
	double	y_base;

	x_base = spot.p.x - cub3d->player.p.x;
	y_base = spot.p.y - cub3d->player.p.y;
	if (cub3d->player.dir == 'E')
		return (ray <= rtod(atan2(y_base + 1, x_base + 1)) ? 'E' : 'N');
	if (cub3d->player.dir == 'N')
		return (ray <= rtod(atan2(y_base + 1, x_base)) ? 'N' : 'W');
	if (cub3d->player.dir == 'W')
		return (ray <= rtod(atan2(y_base, x_base)) ? 'W' : 'S');
	if (cub3d->player.dir == 'S')
		return (ray <= rtod(atan2(y_base, x_base + 1)) ? 'S' : 'E');
	return ('E');
}

char	opposite_wall(char wall)
{
	if (wall == 'W')
		return ('E');
	if (wall == 'S')
		return ('N');
	if (wall == 'E')
		return ('W');
	if (wall == 'N')
		return ('S');
	return (0);
}
