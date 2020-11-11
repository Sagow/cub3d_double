/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:53:30 by marina            #+#    #+#             */
/*   Updated: 2020/11/11 06:40:35 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double	simplifier(double angle)
{
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}

t_pixel	texture(t_case	wall, double y, t_text *text)
{
	double	x;

	if (wall.wall == 'W')
		x = 1 - (wall.p.y - (double)(int)wall.p.y);
	if (wall.wall == 'S')
		x = wall.p.x - (double)(int)wall.p.x;
	if (wall.wall == 'E')
		x = (wall.p.y - (double)(int)wall.p.y);
	if (wall.wall == 'N')
		x = 1 - (wall.p.x - (double)(int)wall.p.x);
	//if (x < 0 || x > 1 || y < 0 || y > 1)
		//printf("%lf %lf\n", x, y);
	return (text->draw[((int)(y * text->height) * text->width + (int)(x * text->width))]);
	//return (0x2e86c1);
}

/*void	draw_line()
{
	
}*/

void	draw_pixel(int x, int y, t_pixel colour, t_cub3d *cub3d)
{
	if (x >= 0 && x < cub3d->width && y >= 0 && y < cub3d->height && colour.a)
		cub3d->draw[y * cub3d->width + (cub3d->width - 1 - x)] = colour;
}

void	draw_col(t_cub3d *cub3d, t_case wall, int i)
{
	double	h;
	int		j;
	t_text	*t;

	h = (cub3d->height / 2) - ((cub3d->width / 2 - cub3d->fov / 2) / (wall.dist * cos(dtor(((double)(i * cub3d->fov) / cub3d->width) - cub3d->fov / 2))));
	if (wall.wall == 'N')
		t = &cub3d->north;
	else if (wall.wall == 'W')
		t = &cub3d->west;
	else if (wall.wall == 'S')
		t = &cub3d->south;
	else
		t = &cub3d->east;
	j = 0;
	while (j < h)
	{
		draw_pixel(i, j, cub3d->ceiling, cub3d);
		j++;
	}
	while (j < cub3d->height - h && j < cub3d->height)
	{
		draw_pixel(i, j, texture(wall, (double)(j - h) / ((double)cub3d->height - 2 * h), t), cub3d);
		j++;
	}
	while (j < cub3d->height)
	{
		draw_pixel(i, j, cub3d->floor, cub3d);
		j++;
	}
}

t_pixel	skin_pixel(t_cub3d *cub3d, double ray, double y)
{
	double	ang;
	double	x;

	ang = atan2(cub3d->sprite->data.p.y - cub3d->player.p.y, cub3d->sprite->data.p.x - cub3d->player.p.x);	
	x = (tan(ang - dtor(ray)) * cub3d->sprite->data.dist);
	if (x < 0)
		x = 0.5 + x;
	else
		x += 0.5;

	if (x > 1 || x < 0)
		return (pixel(0));
	return (cub3d->sprite->image->draw[((int)(y * cub3d->sprite->image->height) * cub3d->sprite->image->width + (int)(x * cub3d->sprite->image->width))]);
}

void		draw_sprites(t_cub3d *cub3d, double ray, int i)
{
	int		j;
	double	h;
	double	rad;
	t_sprite	*bin;

	rad = atan2(cub3d->sprite->data.p.y - cub3d->player.p.y, cub3d->sprite->data.p.x - cub3d->player.p.x) - dtor(ray);
	cub3d->sprite->data.dist = cub3d->sprite->data.dist / cos(rad);
	h = (cub3d->height / 2) - ((cub3d->width / 2 - cub3d->fov / 2) / (cub3d->sprite->data.dist));
	if ((sin(rad) * cub3d->sprite->data.dist <= 0.5) && (sin(rad) * cub3d->sprite->data.dist >= -0.5))
	{
		cub3d->distances[i] = cub3d->sprite->data.dist;
		j = h;
		while (j < cub3d->height - h)
		{
			draw_pixel(i, j, skin_pixel(cub3d, ray, (double)(j - h) / ((double)cub3d->height - 2 * h)), cub3d);
			j++;
		}
	}
	bin = cub3d->sprite;
	cub3d->sprite = cub3d->sprite->closer;
	my_free(bin);
	if (cub3d->sprite)
		draw_sprites(cub3d, ray, i);
}

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
		ray = cub3d->player.ang - (cub3d->fov / 2) + ((double)i / (double)cub3d->width * (double)cub3d->fov);
		ray = simplifier(ray);
		if (cub3d->sprite)
			free_sprite(cub3d->sprite);
		temp = reaching_obstacle(ray, cub3d);
		draw_col(cub3d, temp, i);
		cub3d->distances[i] = temp.dist;
		if (cub3d->sprite)
			draw_sprites(cub3d, ray, i);
		//verif_dist(cub3d, i);
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img, 0, 0);
}

int		key_press(int key_pressed, t_cub3d *cub3d)
{
	if (key_pressed == 32)
		exit(0);
	if (key_pressed == 65361)
		cub3d->player.ang = simplifier(cub3d->player.ang + 1);
	if (key_pressed == 65363)
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

char	arguments(int ac, char **av)
{
	char	*cub;

	if (ac < 2)
		ft_error(ARG_FEW, "the arguments");
	if (ac > 3)
		ft_error(ARG_MANY, "the call just above");
	cub = strstr(av[1], ".cub");
	if (!cub)
		ft_error(ARG_CUB, av[1]);
	if (strcmp(cub, ".cub") != 0)
		ft_error(ARG_CUB, av[1]);
	if (ac == 3)
	{
		if (strcmp(av[2], "--save") == 0)
			return (1);
		ft_error(ARG_SAVE, av[2]);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_cub3d			cub3d;
	int				fd;
	int				trash;

	cub3d.save = arguments(argc, argv);
	if ((fd = open(argv[1], 'r')) < 0)
		ft_error(OPEN_FAIL, argv[1]);
	cub3d.mlx = mlx_init();
	file_processing(fd, &cub3d);
	cub3d.win = mlx_new_window(cub3d.mlx, cub3d.width, cub3d.height, "Cub3d");
	cub3d.img = mlx_new_image(cub3d.mlx, cub3d.width, cub3d.height);
	cub3d.draw = (t_pixel *)mlx_get_data_addr(cub3d.img, &trash, &trash, &trash);
	if (!(cub3d.distances = malloc(sizeof(double) * cub3d.width)))
		return (-1);
	cub3d.fov = 60;
	cub3d.sprite = NULL;
	cub3d.show_map = 0;
	mlx_hook(cub3d.win, 2, (1L<<0), &key_press, &cub3d);
	update(&cub3d);
	if (!cub3d.save)
	{
		mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.img, 0, 0);
		mlx_loop(cub3d.mlx);
	}
	else
		printf("ici il faut faire le save !\n");
	return (0);
}