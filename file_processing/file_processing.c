/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:19:48 by marina            #+#    #+#             */
/*   Updated: 2020/12/01 14:44:28 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	if_extension(t_cub3d *cub3d, char *line, int i, int fd)
{
	if (i >= 0 && line[i] == 'C')
		fp_ceiling(cub3d, line, ++i);
	else if (i >= 0 && line[i] == 'E')
		fp_east(cub3d, line, ++i);
	else if (i >= 0 && line[i] == 'F')
		fp_floor(cub3d, line, ++i);
	else if (i >= 0 && line[i] == 'N')
		fp_north(cub3d, line, ++i);
	else if (i >= 0 && line[i] == 'R')
		fp_resolution(cub3d, line, ++i);
	else if (i >= 0 && line[i] == 'S')
	{
		if (line[i + 1] == 'O')
			fp_south(cub3d, line, ++i);
		else
			fp_sprite(cub3d, line, ++i);
	}
	else if (i >= 0 && line[i] == 'W')
		fp_west(cub3d, line, ++i);
	else if (i >= 0 && line[i] == '1')
		fp_map(cub3d, fd, line);
	else if (i >= 0 && line[i])
		ft_error(DESC_WRONG_CHAR, line, cub3d);
}

void		file_processing(int fd, t_cub3d *cub3d)
{
	int		gnl;
	char	*line;
	int		i;

	line = NULL;
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		i = 0;
		i = space(line, i);
		if_extension(cub3d, line, i, fd);
		my_free(line);
		gnl = get_next_line(fd, &line);
	}	
	if (gnl < 0)
		ft_error(DESC_GNL, "file processing", cub3d);
}
