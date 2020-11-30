/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:10:17 by marina            #+#    #+#             */
/*   Updated: 2020/11/30 13:21:28 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		fp_east(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->east.ptr)
		ft_error(DESC_ALREADY, "east texture", cub3d);
	if (line[i] != 'A')
		ft_error(DESC_WRONG_CHAR, "east texture", cub3d);
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMP, "east texture", cub3d);
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		ft_error(MALLOC_FAIL, "east texture", cub3d);
	get_path(path, &i, line, size + 2);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "east texture", cub3d);
	if (!(cub3d->east.ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
	&cub3d->east.width, &cub3d->east.height)))
		ft_error(DESC_PATH, "east texture", cub3d);
	cub3d->east.draw = (t_pixel *)mlx_get_data_addr(cub3d->east.ptr, &trash,
	&trash, &trash);
	my_free(path);
}

void		fp_north(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->north.ptr)
		ft_error(DESC_ALREADY, "north texture", cub3d);
	if (line[i] != 'O')
		ft_error(DESC_WRONG_CHAR, "north texture", cub3d);
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMP, "north texture", cub3d);
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		ft_error(MALLOC_FAIL, "north texture", cub3d);
	get_path(path, &i, line, size + 2);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "north texture", cub3d);
	if (!(cub3d->north.ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
	&cub3d->north.width, &cub3d->north.height)))
		ft_error(DESC_PATH, "north texture", cub3d);
	cub3d->north.draw = (t_pixel *)mlx_get_data_addr(cub3d->north.ptr, &trash,
	&trash, &trash);
	my_free(path);
}

void		fp_south(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->south.ptr)
		ft_error(DESC_ALREADY, "south texture", cub3d);
	if (line[i] != 'O')
		ft_error(DESC_WRONG_CHAR, "south texture", cub3d);
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMP, "south texture", cub3d);
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		ft_error(MALLOC_FAIL, "south texture", cub3d);
	get_path(path, &i, line, size + 2);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "south texture", cub3d);
	if (!(cub3d->south.ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
	&cub3d->south.width, &cub3d->south.height)))
		ft_error(DESC_PATH, "south texture", cub3d);
	cub3d->south.draw = (t_pixel *)mlx_get_data_addr(cub3d->south.ptr, &trash,
	&trash, &trash);
	my_free(path);
}

void		fp_west(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	size = 1;
	if (cub3d->west.ptr)
		ft_error(DESC_ALREADY, "west texture", cub3d);
	if (line[i] != 'E')
		ft_error(DESC_WRONG_CHAR, "west texture", cub3d);
	if ((i = space(line, ++i)) == -1)
		ft_error(DESC_INCOMP, "west texture", cub3d);
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 2))))
		ft_error(MALLOC_FAIL, "west texture", cub3d);
	get_path(path, &i, line, size + 2);
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "west texture", cub3d);
	if (!(cub3d->west.ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
	&cub3d->west.width, &cub3d->west.height)))
		ft_error(DESC_PATH, "west texture", cub3d);
	cub3d->west.draw = (t_pixel *)mlx_get_data_addr(cub3d->west.ptr, &trash,
	&trash, &trash);
	my_free(path);
}

void	get_path(char *path, int *i, char *line, int max)
{
	int	size;

	size = 0;
	while (size < max && line[*i] && line[*i] != ' ')
	{
		path[size] = line[*i];
		(*i)++;
		size++;
	}
	path[size] = '\0';
}
