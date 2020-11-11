/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:05:41 by marina            #+#    #+#             */
/*   Updated: 2020/11/11 06:38:50 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		fp_sprite(t_cub3d *cub3d, char *line, int i)
{
	int		size;
	char	*path;
	int		trash;

	
	size = 1;
	if (cub3d->skins)
		ft_error(DESC_ALREADY, "sprite");
	if (!(cub3d->skins = malloc(sizeof(t_skin *) * 2)))
		ft_error(MALLOC_FAIL, "sprite");
	if ((i = space(line, i)) == -1)
		ft_error(DESC_INCOMPLETE, "sprite");
	while (line[i + size] && line[i + size] != ' ')
		size++;
	if (!(path = malloc(sizeof(char) * (size + 1))))
		ft_error(MALLOC_FAIL, "sprite");
	size = 0;
	while (line[i] && line[i] != ' ')
	{
		path[size] = line[i];
		i++;
		size++;
	}
	path[size] = '\0';
	if ((i = space(line, i)) != -1)
		ft_error(DESC_WRONG_CHAR, "sprite");
	cub3d->skins[0].type = '2';
	cub3d->skins[0].skin.ptr = mlx_xpm_file_to_image(cub3d->mlx, path, &cub3d->skins[0].skin.width, &cub3d->skins[0].skin.height);
	cub3d->skins[0].skin.draw = (t_pixel *)mlx_get_data_addr(cub3d->skins[0].skin.ptr, &trash, &trash, &trash);
	cub3d->skins[1].type = 0;
	my_free(path);
}