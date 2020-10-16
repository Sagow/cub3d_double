/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:10:17 by marina            #+#    #+#             */
/*   Updated: 2020/10/16 07:23:45 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		fp_east(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->east.ptr)
		error(DESC_ALREADY, "east texture");
	if (line[i] != 'A')
		error(DESC_WRONG_CHAR, "east texture");
	if ((i = space(line, ++i)) == -1)
		error(DESC_INCOMPLETE, "east texture");
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		error(MALLOC_FAIL, "east texture");
	size = 0;
	while (line[i] && line[i] != ' ')
	{
		path[size] = line[i];
		i++;
		size++;
	}
	path[size] = '\0';
	if ((i = space(line, i)) != -1)
		error(DESC_WRONG_CHAR, "east texture");
	if (!(cub3d->east.ptr = mlx_xpm_file_to_image(cub3d->mlx, path, &cub3d->east.width, &cub3d->east.height)))
		error(DESC_PATH, "east texture");
	cub3d->east.draw = (unsigned int *)mlx_get_data_addr(cub3d->east.ptr, &trash, &trash, &trash);
	my_free(path);
}

void		fp_north(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->north.ptr)
		error(DESC_ALREADY, "north texture");
	if (line[i] != 'O')
		error(DESC_WRONG_CHAR, "north texture");
	if ((i = space(line, ++i)) == -1)
		error(DESC_INCOMPLETE, "north texture");
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		error(MALLOC_FAIL, "north texture");
	size = 0;
	while (line[i] && line[i] != ' ')
	{
		path[size] = line[i];
		i++;
		size++;
	}
	path[size] = '\0';
	if ((i = space(line, i)) != -1)
		error(DESC_WRONG_CHAR, "north texture");
	if (!(cub3d->north.ptr = mlx_xpm_file_to_image(cub3d->mlx, path, &cub3d->north.width, &cub3d->north.height)))
		error(DESC_PATH, "north texture");
	cub3d->north.draw = (unsigned int *)mlx_get_data_addr(cub3d->north.ptr, &trash, &trash, &trash);
	my_free(path);
}

void		fp_south(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->south.ptr)
		error(DESC_ALREADY, "south texture");
	if (line[i] != 'O')
		error(DESC_WRONG_CHAR, "south texture");
	if ((i = space(line, ++i)) == -1)
		error(DESC_INCOMPLETE, "south texture");
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		error(MALLOC_FAIL, "south texture");
	size = 0;
	while (line[i] && line[i] != ' ')
	{
		path[size] = line[i];
		i++;
		size++;
	}
	path[size] = '\0';
	if ((i = space(line, i)) != -1)
		error(DESC_WRONG_CHAR, "south texture");
	if (!(cub3d->south.ptr = mlx_xpm_file_to_image(cub3d->mlx, path, &cub3d->south.width, &cub3d->south.height)))
		error(DESC_PATH, "south texture");
	cub3d->south.draw = (unsigned int *)mlx_get_data_addr(cub3d->south.ptr, &trash, &trash, &trash);
	my_free(path);
}

void		fp_west(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->west.ptr)
		error(DESC_ALREADY, "west texture");
	if (line[i] != 'E')
		error(DESC_WRONG_CHAR, "west texture");
	if ((i = space(line, ++i)) == -1)
		error(DESC_INCOMPLETE, "west texture");
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		error(MALLOC_FAIL, "west texture");
	size = 0;
	while (line[i] && line[i] != ' ')
	{
		path[size] = line[i];
		i++;
		size++;
	}
	path[size] = '\0';
	if ((i = space(line, i)) != -1)
		error(DESC_WRONG_CHAR, "west texture");
	if (!(cub3d->west.ptr = mlx_xpm_file_to_image(cub3d->mlx, path, &cub3d->west.width, &cub3d->west.height)))
		error(DESC_PATH, "west texture");
	cub3d->west.draw = (unsigned int *)mlx_get_data_addr(cub3d->west.ptr, &trash, &trash, &trash);
	my_free(path);
}
