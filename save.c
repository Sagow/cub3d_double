/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:33:42 by marina            #+#    #+#             */
/*   Updated: 2020/11/18 14:58:11 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	file_type_data(int fd, t_cub3d *cub3d)
{
	write(fd, "BM", 2);
	write(fd, (unsigned int)size_of_file(cub3d), 4);
	write(fd, (unsigned int)0, 2);
	write(fd, (unsigned int)0, 2);
	write(fd, (unsigned int)54), 4);
}

void	image_information_data(int fd, t_cub3d *cub3d)
{
	write(fd, (unsigned int)40, 4);
	write(fd, (signed int)cub3d->width, 4);
	write(fd, (signed int)cub3d->height, 4);
	write(fd, (unsigned int)1, 2);
	write(fd, (unsigned int)sizeof(t_pixel), 2);
	write(fd, (unsigned int)0, 4);
	write(fd, (unsigned int)0, 4);
	write(fd, (signed int)0, 4);
	write(fd, (signed int)0, 4);
	write(fd, (unsigned int)0, 4);
	write(fd, (unsigned int)0, 4);
}

void	raw_pixel_data(void)
{
	
}

void	save(/*t_cub3d *cub3d*/ void)
{
	int		fd;
	mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char	*path = "screenshots/save";
	int		i;

	i = 1;
	while ((fd = open(ft_strjoin(ft_strjoin(path, ft_itoa(i)), ".bmp"), O_CREAT, 'r')) == -1 && i < 200)
		i++;
	
}

int		main(void)
{
	save();
	return (0);
}