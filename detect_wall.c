/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:02:24 by marina            #+#    #+#             */
/*   Updated: 2020/10/08 00:11:42 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ang_cal(int opp1, int opp2, int adj1, int adj2)
{
	double	opp;
	double	adj;

	//return (atan2(adj))
	opp = (opp1 > opp2) ? opp1 - opp2 : opp2 - opp1;
	adj = (adj1 > adj2) ? adj1 - adj2 : adj2 - adj1;
	return (180 * atan(opp / adj) / M_PI);
}

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

double	rtod(double	rad)
{
	return (simplifier(rad * 180 /M_PI));
}

/*
**travail du jour = remplacer la fonction en dessous par un truc avec atan2 ou DDA
*/
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

/*
** right_wall indique sur lequel des 4 murs d'un bloc on va taper
*/
/*
char	right_wall(t_manip *cur, t_case spot)
{
	char	wall;
	double	x;
	double	y;

	wall = 0;
	x = spot.x * S_CUB;
	y = spot.y * S_CUB;
	if (ray >= ang_cal(cur->eye->p[1] + cur->eye->c[1] * S_CUB, S_CUB - 1 + y,
	cur->eye->p[0] + cur->eye->c[0] * S_CUB, S_CUB - 1 + x))
		wall++;
	if (ray >= 90 + ang_cal(cur->eye->p[0] + cur->eye->c[0] * S_CUB, 0 + x,
	cur->eye->p[1] + cur->eye->c[1] * S_CUB, S_CUB - 1 + y))
		wall++;
	if (ray >= 180 + ang_cal(cur->eye->p[1] + cur->eye->c[1] * S_CUB, 0 + y,
	cur->eye->p[0] + cur->eye->c[0] * S_CUB, 0 + x))
		wall++;
	if (ray >= 270 + ang_cal(cur->eye->p[0] + cur->eye->c[0] * S_CUB, S_CUB - 1 + x,
	cur->eye->p[1] + cur->eye->c[1] * S_CUB, 0 + y))
		wall++;
	wall = translate_letter(wall);
	return (wall);
}
*/
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

double		dtor(double angle)
{
	return (angle * M_PI / 180);
}

t_line		fill_t_line(double a, double b, double c, double d)
{
	t_line	line;

	line.p1.x = a;
	line.p1.y = b;
	line.p2.x = c;
	line.p2.y = d;
	return (line);
}

double		fmod(double number, double div)
{
	while (number >= (div - 0.1))
		number -= div;
	return (number);
}

void		intersect(t_case *spot, t_line beam, t_line wall)
{
	double	denom;

	denom = (beam.p1.x - beam.p2.x) * (wall.p1.y - wall.p2.y) - (beam.p1.y - beam.p2.y) *
	(wall.p1.x - wall.p2.x);
	//		printf("denom = %lf, num1 = %lf, num2 = %lf\n", denom, (beam.p1.x * beam.p2.y - beam.p1.y * beam.p2.x) * (wall.p2.x - wall.p2.x) -
	//		(beam.p1.x - beam.p2.x) * (wall.p1.x * wall.p2.y - wall.p1.y * wall.p2.x), (beam.p1.x * beam.p2.y - beam.p1.y * beam.p2.x) * (wall.p2.y - wall.p2.y) -
	//		(beam.p1.y - beam.p2.y) * (wall.p1.x * wall.p2.y - wall.p1.y * wall.p2.x));
	spot->p.x = ((beam.p1.x * beam.p2.y - beam.p1.y * beam.p2.x) * (wall.p1.x - wall.p2.x) -
	(beam.p1.x - beam.p2.x) * (wall.p1.x * wall.p2.y - wall.p1.y * wall.p2.x)) / denom;
	spot->p.y = ((beam.p1.x * beam.p2.y - beam.p1.y * beam.p2.x) * (wall.p1.y - wall.p2.y) -
	(beam.p1.y - beam.p2.y) * (wall.p1.x * wall.p2.y - wall.p1.y * wall.p2.x)) / denom;
	//printf("wall 1 = %lf : %lf, wall 2 = %lf : %lf, %lf %lf\n", wall.p1.x, wall.p1.y, wall.p2.x, wall.p1.y, spot->px, spot->py);
	//printf("beam 1 = %lf : %lf, beam 2 = %lf : %lf, %lf %lf\n", beam.p1.x, beam.p1.y, beam.p2.x, beam.p1.y, spot->px, spot->py);
}

void		get_distance(t_case *spot, double ray, t_cub3d *cub3d)
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
		wall = fill_t_line(spot->p.x + 1, spot->p.y, spot->p.x + 1, spot->p.y + 1);
	else if (spot->wall == 'N')
		wall = fill_t_line(spot->p.x + 1, spot->p.y + 1, spot->p.x, spot->p.y + 1);
	//printf("Beam = %lf;%lf - %lf;%lf\nWall = %lf;%lf - %lf;%lf\n", beam.p1.x, beam.p1.y, beam.p2.x, beam.p2.y, wall.p1.x, wall.p1.y, wall.p2.x, wall.p2.y);
	intersect(spot, beam, wall);
	//printf("%f\n", ray);
	spot->dist = hypot(cub3d->player.p.x - spot->p.x, cub3d->player.p.y - spot->p.y);
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

/*
** avance le rayon, jusqu'à atteindre un mur. Renvoie les coordonnées dudit mur
*/
t_case	reaching_obstacle(double ray, t_cub3d *cub3d)
{
	char	obs;
	char	wall;
	t_case	spot;

	//printf("1\n");
	obs = 0;
	spot.p.x = (int)cub3d->player.p.x;
	spot.p.y = (int)cub3d->player.p.y;
	spot.wall = 0;
	cub3d->player.dir = get_first_wall(ray);
	while (obs != '1')
	{
		//printf("2\n");
		wall = right_wall(ray, spot, cub3d);
		if (wall == 'E' || wall == 'W')
			spot.p.x = spot.p.x + (wall == 'E' ? 1 : -1);
		if (wall == 'N' || wall == 'S')
			spot.p.y = spot.p.y + (wall == 'N' ? 1 : -1);
		//printf("****%d ; %d\n", spot.x, spot.y);
		spot.wall = opposite_wall(wall);
		//printf("%d %d\n", cub3d->map_y - (int)spot.p.y, (int)spot.p.x);
		obs = cub3d->map[cub3d->map_y - 1 - (int)spot.p.y][(int)spot.p.x];
		//printf("%c", wall);
	}
	//printf("\n");
	get_distance(&spot, ray, cub3d);
	//printf("wall = %c\n", spot.wall);
	return (spot);
}
