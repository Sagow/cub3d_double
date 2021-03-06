/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:53:30 by marina            #+#    #+#             */
/*   Updated: 2020/12/01 14:47:35 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	blackout(t_cub3d *cub3d, t_pixel color)
{
	int	i;

	i = 0;
	while (i < cub3d->width * cub3d->height)
	{
		draw_pixel(i % cub3d->width, i / cub3d->width, color, cub3d);
		i++;
	}
}

void	update(t_cub3d *cub3d)
{
	int		i;
	double	ray;
	t_case	temp;

	i = 0;
	while (i < cub3d->width)
	{
		ray = cub3d->player.ang - (cub3d->fov / 2) +
		((double)i / (double)cub3d->width * (double)cub3d->fov);
		ray = simplifier(ray);
		if (cub3d->sprite)
			free_sprite(cub3d->sprite);
		temp = reaching_obstacle(ray, cub3d);
		draw_col(cub3d, temp, i);
		cub3d->distances[i] = temp.dist;
		if (cub3d->sprite)
			draw_sprites(cub3d, ray, i);
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img, 0, 0);
}

int		key_press(int key_pressed, t_cub3d *cub3d)
{
	if (key_pressed == KEY_ESC)
		my_exit(cub3d);
	if (key_pressed == KEY_LEFT)
		cub3d->player.ang = simplifier(cub3d->player.ang + 1);
	if (key_pressed == KEY_RIGHT)
		cub3d->player.ang = simplifier(cub3d->player.ang - 1);
	if (key_pressed == KEY_Z)
		move_forward(cub3d);
	if (key_pressed == KEY_S)
		move_backward(cub3d);
	if (key_pressed == KEY_Q)
		move_left(cub3d);
	if (key_pressed == KEY_D)
		move_right(cub3d);
	if (key_pressed == KEY_M)
		cub3d->show_map++;
	update(cub3d);
	if (cub3d->show_map % 2)
		aerial(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img, 0, 0);
	return (1);
}

char	arguments(int ac, char **av, t_cub3d *cub3d)
{
	char	*cub;

	if (ac < 2)
		ft_error(ARG_FEW, "the arguments", cub3d);
	if (ac > 3)
		ft_error(ARG_MANY, "the call just above", cub3d);
	cub = ft_strnstr(av[1], ".cub", ft_strlen(av[1]));
	if (!cub)
		ft_error(ARG_CUB, av[1], cub3d);
	if (ft_strncmp(cub, ".cub", 5) != 0)
		ft_error(ARG_CUB, av[1], cub3d);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) == 0)
			return (1);
		ft_error(ARG_SAVE, av[2], cub3d);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_cub3d			cub3d;
	int				fd;
	int				t;

	init_cub3d(&cub3d);
	cub3d.save = arguments(argc, argv, &cub3d);
	if ((fd = open(argv[1], 'r')) < 0)
		ft_error(OPEN_FAIL, argv[1], &cub3d);
	cub3d.mlx = mlx_init();
	file_processing(fd, &cub3d);
	cub3d.win = mlx_new_window(cub3d.mlx, cub3d.width, cub3d.height, "Cub3d");
	cub3d.img = mlx_new_image(cub3d.mlx, cub3d.width, cub3d.height);
	cub3d.draw = (t_pixel *)mlx_get_data_addr(cub3d.img, &t, &t, &t);
	if (!(cub3d.distances = malloc(sizeof(double) * cub3d.width)))
		return (-1);
	mlx_hook(cub3d.win, 2, (1L << 0), &key_press, &cub3d);
	mlx_hook(cub3d.win, 17, 1L << 17, click, &cub3d);
	update(&cub3d);
	if (cub3d.save)
		save(&cub3d);
	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.img, 0, 0);
	mlx_loop(cub3d.mlx);
	return (0);
}
