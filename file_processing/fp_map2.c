/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:22:30 by marina            #+#    #+#             */
/*   Updated: 2020/11/30 13:29:11 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		belongs(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset && charset[i] && c != charset[i])
		i++;
	if (!charset || !charset[i])
		return (0);
	return (1);
}

void	assign_player(t_cub3d *cub3d, int x, int y)
{
	cub3d->player.p.x = (double)x + 0.5;
	cub3d->player.p.y = (double)(cub3d->map_y - 1 - y) + 0.5;
	if (cub3d->map[y][x] == 'E')
		cub3d->player.ang = 0;
	if (cub3d->map[y][x] == 'N')
		cub3d->player.ang = 90;
	if (cub3d->map[y][x] == 'W')
		cub3d->player.ang = 180;
	if (cub3d->map[y][x] == 'S')
		cub3d->player.ang = 270;
	cub3d->map[y][x] = '0';
}

void	get_player(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub3d->map_y)
	{
		x = 0;
		while (x < cub3d->map_x)
		{
			if (belongs(cub3d->map[y][x], "NSEW"))
			{
				if (cub3d->player.p.x < 0)
					assign_player(cub3d, x, y);
				else
					ft_error(MAP_SVRL_PLAYERS, "need of correction !", cub3d);
			}
			x++;
		}
		y++;
	}
	if (cub3d->player.p.x < 0)
		ft_error(MAP_NO_PLAYER, "need of correction !", cub3d);
}

void	hole(t_cub3d *cub3d, int x, int y)
{
	if (x == 0 || y == 0 || x == cub3d->map_x - 1 || y == cub3d->map_y - 1)
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y - 1][x - 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y][x - 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y + 1][x - 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y - 1][x], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y + 1][x], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y - 1][x + 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y][x + 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
	if (!belongs(cub3d->map[y + 1][x + 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !", cub3d);
}

int		gnl_to_chain(int fd, t_fp_map **begins, char *line, t_cub3d *cub3d)
{
	int			gnl;
	int			size;
	t_fp_map	*map;
	
	map = *begins;
	size = 1;
	map->line = ft_strdup(line);
	line = NULL;
	gnl = 1;
	while (gnl > 0)
	{
		if ((gnl = get_next_line(fd, &line)) < 0)
			ft_error(DESC_GNL, "mapping", cub3d);
		if (!(map->next = malloc(sizeof(t_fp_map))))
			ft_error(MALLOC_FAIL, "mapping", cub3d);
		map->next->line = ft_strdup(line);
		map = map->next;
		my_free(line);
		size++;
	}
	map->next = NULL;
	return (size);
}
