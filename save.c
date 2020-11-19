/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:33:42 by marina            #+#    #+#             */
/*   Updated: 2020/11/19 00:43:42 by marina           ###   ########.fr       */
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

	printf("fd file_data= %d\n", fd);
}

void			image_information_data(int fd, t_cub3d *cub3d)
{
	/*unsigned int	uvalue;
	signed int		svalue;*/
	int	value;

	value = /*(unsigned int)*/40;
	write(fd, &value, 4);
	value = /*(signed int)*/cub3d->width;
	write(fd, &value, 4);
	value = /*(signed int)*/cub3d->height;
	write(fd, &value, 4);
	value = /*(unsigned int)*/1;
	write(fd, &value, 2);
	value = /*(unsigned int)*/sizeof(t_pixel);
	write(fd, &value, 2);
	value = /*(unsigned int)*/0;
	write(fd, &value, 4);
	write(fd, &value, 4);
	value = /*(signed int)*/0;
	write(fd, &value, 4);
	write(fd, &value, 4);
	write(fd, &value, 4);
	write(fd, &value, 4);
}

void			color_table(int fd)
{
	unsigned char	intensity;

	intensity = 255;
	write(fd, &intensity, 1);
	write(fd, &intensity, 1);
	write(fd, &intensity, 1);
	intensity = 0;
	write(fd, &intensity, 1);
}

void			raw_pixel_data(int fd, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = cub3d->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < cub3d->width)
		{
			write(fd, &(cub3d->draw[i * cub3d->height + j]), sizeof(t_pixel));
			j++;
		}
		i--;
	}
}

void			save(t_cub3d *cub3d)
{
	int		fd;
	char	*path = "screenshots/save";
	//mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int		i;

	i = 1;
	//while ((fd = open(ft_strjoin(ft_strjoin(path, ft_itoa(i)), ".bmp"), O_CREAT, mode/*'w'*/)) == -1 && i < 200)
	//	i++;
	while ((fd = open(ft_strjoin(ft_strjoin(path, ft_itoa(i)), ".bmp"),O_RDWR | O_CREAT/* | O_WRONLY*/)) == -1 && i < 100)
		i++;
	printf("fd = %d\n", fd);
	printf("sizeof t_pixel : %lu\n", sizeof(t_pixel));
	if (fd < 0)
		ft_error(FILE_CREATION, "screenshots");
	file_type_data(fd, cub3d);
	image_information_data(fd, cub3d);
	//color_table(fd);
	raw_pixel_data(fd, cub3d);
	close(fd);
}
