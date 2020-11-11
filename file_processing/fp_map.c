/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 01:50:56 by marina            #+#    #+#             */
/*   Updated: 2020/11/11 06:44:55 by marina           ###   ########.fr       */
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
					ft_error(MAP_SVRL_PLAYERS, "need of correction !");
			}
			x++;
		}
		y++;
	}
	if (cub3d->player.p.x < 0)
		ft_error(MAP_NO_PLAYER, "need of correction !");
}

void	hole(t_cub3d *cub3d, int x, int y)
{
	if (x == 0 || y == 0 || x == cub3d->map_x - 1 || y == cub3d->map_y - 1)
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y - 1][x - 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y][x - 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y + 1][x - 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y - 1][x], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y + 1][x], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y - 1][x + 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y][x + 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
	if (!belongs(cub3d->map[y + 1][x + 1], "012348NSEW"))
		ft_error(MAP_OPEN, "need of correction !");
}

void	check_holes(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub3d->map_y)
	{
		x = 0;
		while (x < cub3d->map_x)
		{
			if (belongs(cub3d->map[y][x], "02NSEW"))
				hole(cub3d, x, y);
			x++;
		}
		y++;
	}
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*copy;

	size = 0;
	while (s1[size] != '\0')
		size++;
	if (!(copy = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (size >= 0)
	{
		copy[size] = s1[size];
		size--;
	}
	return (copy);
}

char	*copy_comp(char *line, int size)
{
	char	*map;
	int		i;

	if (!(map = malloc(sizeof(char) * (size + 1))))
		ft_error(MALLOC_FAIL, "mapping1");
	i = 0;
	while (line[i])
	{
		if (!belongs(line[i], " 012384NSEW"))
			ft_error(DESC_WRONG_CHAR, "mapping2");
		map[i] = line[i];
		i++;
	}
	while (i < size)
	{
		map[i] = ' ';
		i++;
	}
	map[i] = '\0';
	return (map);
}

void	chain_to_map(t_cub3d *cub3d, t_fp_map **begins, int size)
{
	t_fp_map	*link;
	t_fp_map	*bin;
	int			i;

	cub3d->map_x = 0;
	cub3d->map_y = size - 1;
	if (!(cub3d->map = malloc(sizeof(char *) * (size))))
		ft_error(MALLOC_FAIL, "mapping");
	link = *begins;
	while (link)
	{
		if ((int)strlen(link->line) > cub3d->map_x)
			cub3d->map_x = strlen(link->line);
		link = link->next;
	}
	link = *begins;
	i = 0;
	while (link)
	{
		cub3d->map[i] = copy_comp(link->line, cub3d->map_x);
		bin = link;
		link = link->next;
		my_free(bin->line);
		my_free(bin);
		i++;
	}
	cub3d->map[i] = NULL;
}

void	fp_map(t_cub3d *cub3d, int fd, char *line)
{
	t_fp_map	*begins;
	t_fp_map	*map;
	int			gnl;
	int			size;

	check_processed(cub3d);
	size = 1;
	if (!(map = malloc(sizeof(t_fp_map))))
		ft_error(MALLOC_FAIL, "mapping");
	begins = map;
	map->line = ft_strdup(line);
	line = NULL;
	//free(line);
	//my_free(line);
	gnl = 1;
	while (gnl > 0)
	{
		if ((gnl = get_next_line(fd, &line)) < 0)
			ft_error(DESC_GNL, "mapping");
		if (!(map->next = malloc(sizeof(t_fp_map *))))
			ft_error(MALLOC_FAIL, "mapping");
		map = map->next;
		map->line = ft_strdup(line);
		my_free(line);
		size++;
	}
	map->next = NULL;
	chain_to_map(cub3d, &begins, size + 1);
	check_holes(cub3d);
	get_player(cub3d);
}