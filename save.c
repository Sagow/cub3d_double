/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:33:42 by marina            #+#    #+#             */
/*   Updated: 2020/11/23 19:21:02 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	size_of_file(t_cub3d *cub3d)
{
	int	size_picture;

	size_picture = cub3d->height * cub3d->width * sizeof(t_pixel);
	return (54 + size_picture);
}

void			file_type_data(int fd, t_cub3d *cub3d)
{
	int	value;

	value = size_of_file(cub3d);
	write(fd, "BM", 2);
	write(fd, &value, 4);
	value = 0;
	write(fd, &value, 2);
	write(fd, &value, 2);
	value = 54;
	write(fd, &value, 4);

	printf("fd file_data= %d\n", fd);
}

void			image_information_data(int fd, t_cub3d *cub3d)
{
	/*unsigned int	uvalue;
	signed int		svalue;*/
	int	value;

	value = 40;
	write(fd, &value, 4);
	value = (int)cub3d->width;
	write(fd, &value, 4);
	value = (int)cub3d->height;
	write(fd, &value, 4);
	value = 1;
	write(fd, &value, 2);
	value = 32;
	write(fd, &value, 2);
	value = 0;
	write(fd, &value, 4);
	write(fd, &value, 4);
	write(fd, &value, 4);
	write(fd, &value, 4);
	write(fd, &value, 4);
	write(fd, &value, 4);
}

void			raw_pixel_data(int fd, t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	*tmp;

	tmp = (int *)mlx_get_data_addr(cub3d->img, &i, &i, &i);
	i = cub3d->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < cub3d->width)
		{
			write(fd, &(tmp[i * cub3d->width + j]), sizeof(t_pixel));
			j++;
		}
		i--;
	}
}

void			save(t_cub3d *cub3d)
{
	int		fd;
	char	*name1;
	char	*name2;
	mode_t	mode = S_IRUSR | /*S_IWUSR |*/ S_IRGRP | S_IROTH;
	int		i;

	i = 1;
	name1 = ft_strjoin("screenshots/save", ft_itoa(i));
	name2 = ft_strjoin(name1, ".bmp");
	my_free(name1);
	while ((fd = open(name2, O_RDONLY | O_CREAT, mode)) == -1 && i < 300)
	{
		i++;
		my_free(name2);
		name1 = ft_strjoin("screenshots/save", ft_itoa(i));
		name2 = ft_strjoin(name1, ".bmp");
		my_free(name1);
	}
	my_free(name2);
	if (fd < 0)
		ft_error(FILE_CREATION, "screenshots");
	file_type_data(fd, cub3d);
	image_information_data(fd, cub3d);
	raw_pixel_data(fd, cub3d);
	close(fd);
}
