/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:02:24 by marina            #+#    #+#             */
/*   Updated: 2020/11/24 12:57:25 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_line	fill_t_line(double a, double b, double c, double d)
{
	t_line	line;

	line.p1.x = a;
	line.p1.y = b;
	line.p2.x = c;
	line.p2.y = d;
	return (line);
}

void	intersect(t_case *spot, t_line beam, t_line wall)
{
	double	denom;

	denom = (beam.p1.x - beam.p2.x) * (wall.p1.y - wall.p2.y) - (beam.p1.y -
	beam.p2.y) * (wall.p1.x - wall.p2.x);
	spot->p.x = ((beam.p1.x * beam.p2.y - beam.p1.y * beam.p2.x) *
	(wall.p1.x - wall.p2.x) - (beam.p1.x - beam.p2.x) * (wall.p1.x * wall.p2.y
	- wall.p1.y * wall.p2.x)) / denom;
	spot->p.y = ((beam.p1.x * beam.p2.y - beam.p1.y * beam.p2.x) * (wall.p1.y -
	wall.p2.y) - (beam.p1.y - beam.p2.y) * (wall.p1.x * wall.p2.y - wall.p1.y *
	wall.p2.x)) / denom;
}

void	get_distance(t_case *spot, double ray, t_cub3d *cub3d)
{
	t_line		beam;
	t_line		wall;

	beam = fill_t_line(cub3d->player.p.x, cub3d->player.p.y,
	cub3d->player.p.x + cos(dtor(ray)), cub3d->player.p.y + sin(dtor(ray)));
	if (spot->wall == 'W')
		wall = fill_t_line(spot->p.x, spot->p.y + 1, spot->p.x, spot->p.y);
	else if (spot->wall == 'S')
		wall = fill_t_line(spot->p.x, spot->p.y, spot->p.x + 1, spot->p.y);
	else if (spot->wall == 'E')
		wall = fill_t_line(spot->p.x + 1, spot->p.y, spot->p.x + 1,
		spot->p.y + 1);
	else
		wall = fill_t_line(spot->p.x + 1, spot->p.y + 1, spot->p.x,
		spot->p.y + 1);
	intersect(spot, beam, wall);
	spot->dist = hypot(cub3d->player.p.x - spot->p.x,
	cub3d->player.p.y - spot->p.y);
}

char	get_first_wall(double ray)
{
	if (ray >= 0 && ray < 90)
		return ('E');
	if (ray >= 90 && ray < 180)
		return ('N');
	if (ray >= 180 && ray < 270)
		return ('W');
	return ('S');
}

t_case	reaching_obstacle(double ray, t_cub3d *cub3d)
{
	char	obs;
	char	wall;
	t_case	spot;

	obs = 0;
	spot.p.x = (int)cub3d->player.p.x;
	spot.p.y = (int)cub3d->player.p.y;
	spot.wall = 0;
	cub3d->player.dir = get_first_wall(ray);
	while (obs != '1')
	{
		wall = right_wall(ray, spot, cub3d);
		if (wall == 'E' || wall == 'W')
			spot.p.x = spot.p.x + (wall == 'E' ? 1 : -1);
		if (wall == 'N' || wall == 'S')
			spot.p.y = spot.p.y + (wall == 'N' ? 1 : -1);
		spot.wall = opposite_wall(wall);
		obs = cub3d->map[cub3d->map_y - 1 - (int)spot.p.y][(int)spot.p.x];
		if (obs != '0' && obs != '1')
			add_sprite(cub3d, spot, obs);
	}
	get_distance(&spot, ray, cub3d);
	return (spot);
}
