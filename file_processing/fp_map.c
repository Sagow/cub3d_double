/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 01:50:56 by marina            #+#    #+#             */
/*   Updated: 2020/11/30 13:54:12 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

char	*copy_comp(t_fp_map *link, int size, t_cub3d *cub3d)
{
	char		*map;
	int			i;

	if (!(map = malloc(sizeof(char) * (size + 1))))
		ft_error(MALLOC_FAIL, "mapping1", cub3d);
	i = 0;
	while (i < size && link->line[i])
	{
		if (!belongs(link->line[i], " 012384NSEW"))
			ft_error(DESC_WRONG_CHAR, "mapping2", cub3d);
		map[i] = link->line[i];
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
	int			i;

	cub3d->map_x = 0;
	cub3d->map_y = size - 1;
	if (!(cub3d->map = malloc(sizeof(char *) * (size))))
		ft_error(MALLOC_FAIL, "mapping", cub3d);
	link = *begins;
	while (link)
	{
		if ((int)ft_strlen(link->line) > cub3d->map_x)
			cub3d->map_x = ft_strlen(link->line);
		link = link->next;
	}
	link = *begins;
	i = 0;
	while (link)
	{
		cub3d->map[i] = copy_comp(link, cub3d->map_x, cub3d);
		i++;
		link = link->next;
	}
	cub3d->map[i] = NULL;
}

void	fp_map(t_cub3d *cub3d, int fd, char *line)
{
	t_fp_map	**begins;
	t_fp_map	*map;
	int			size;

	check_processed(cub3d);
	if (!(map = malloc(sizeof(t_fp_map))))
		ft_error(MALLOC_FAIL, "mapping", cub3d);
	begins = &map;
	size = gnl_to_chain(fd, begins, line, cub3d);
	chain_to_map(cub3d, begins, size + 1);
	check_holes(cub3d);
	get_player(cub3d);
	while (*begins)
	{
		my_free((*begins)->line);
		map = *begins;
		begins = &map->next;
		my_free(map);
	}
}
