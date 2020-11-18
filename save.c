/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:33:42 by marina            #+#    #+#             */
/*   Updated: 2020/11/18 17:04:02 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

unsigned int	size_of_file(t_cub3d *cub3d)
{
	unsigned int	size_picture;

	size_picture = cub3d->height * cub3d->width * sizeof(t_pixel);
	return (54 + size_picture);
}

void			file_type_data(int fd, t_cub3d *cub3d)
{
	unsigned int	value;

	value = (unsigned int)size_of_file(cub3d);
	write(fd, "BM", 2);
	write(fd, &value, 4);
	value = (unsigned int)0;
	write(fd, &value, 2);
	write(fd, &value, 2);
	value = (unsigned int)54;
	write(fd, &value, 4);
}

void			image_information_data(int fd, t_cub3d *cub3d)
{
	unsigned int	uvalue;
	signed int		svalue;

	uvalue = (unsigned int)40;
	write(fd, &uvalue, 4);
	svalue = (signed int)cub3d->width;
	write(fd, &svalue, 4);
	svalue = (signed int)cub3d->height;
	write(fd, &svalue, 4);
	uvalue = (unsigned int)1;
	write(fd, &uvalue, 2);
	uvalue = (unsigned int)sizeof(t_pixel);
	write(fd, &uvalue, 2);
	uvalue = (unsigned int)0;
	write(fd, &uvalue, 4);
	write(fd, &uvalue, 4);
	svalue = (signed int)0;
	write(fd, &svalue, 4);
	write(fd, &svalue, 4);
	write(fd, &uvalue, 4);
	write(fd, &uvalue, 4);
}

void			raw_pixel_data(int fd, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->height)
	{
		j = 0;
		while (j < cub3d->width)
		{
			write(fd, &(cub3d->draw[i * cub3d->height + j]), sizeof(t_pixel));
			j++;
		}
		i++;
	}
	
}

void			save(t_cub3d *cub3d)
{
	int		fd;
	char	*path = "screenshots/save";
	int		i;

	i = 1;
	while ((fd = open(ft_strjoin(ft_strjoin(path, ft_itoa(i)), ".bmp"), O_CREAT, 'r')) == -1 && i < 200)
		i++;
	if (fd < 0)
		ft_error(FILE_CREATION, "screenshots");
	file_type_data(fd, cub3d);
	image_information_data(fd, cub3d);
	raw_pixel_data(fd, cub3d);
}
