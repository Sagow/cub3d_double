/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 01:50:56 by marina            #+#    #+#             */
/*   Updated: 2020/10/17 05:20:09 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	i = 0;
	while (link)
	{
		cub3d->map[i] = link->line;
		if (strlen(link->line) > cub3d->map_x)
			cub3d->map_x = strlen(link->line);
		bin = link;
		link = link->next;
		my_free(bin);
	printf("|%s|uu\n", cub3d->map[i]);
		i++;
	}
	printf("i = %d\n", i);
	cub3d->map[i] = NULL;
}

void	fp_map(t_cub3d *cub3d, int fd, char *line, int i)
{
	t_fp_map	*begins;
	t_fp_map	*map;
	int			gnl;
	int			size;

	check_processed(cub3d);
	printf("check\n");
	size = 1;
	if (!(map = malloc(sizeof(t_fp_map))))
		ft_error(MALLOC_FAIL, "mapping");
	begins = map;
	map->line = line;
	printf("f%s\n", map->line);
	line = NULL;
	gnl = 1;
	while (gnl > 0)
	{
		if ((gnl = get_next_line(fd, &line)) < 0)
			ft_error(DESC_GNL, "mapping");
		if (!(map->next = malloc(sizeof(t_fp_map *))))
			ft_error(MALLOC_FAIL, "mapping");
		map = map->next;
		map->line = line;
	printf("%s\n", map->line);
		line = NULL;
		size++;
	}
	map->next = NULL;
	printf("Derriere\n");
	map = begins;
	while (map)
	{
		printf("+%s\n", map->line);
		map = map->next;
	}
	printf("%d\n", size);
	chain_to_map(cub3d, &begins, size + 1);
	printf("|%p|dfgdf\n", cub3d->map[0]);
}