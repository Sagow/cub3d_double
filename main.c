/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:53:30 by marina            #+#    #+#             */
/*   Updated: 2020/10/16 06:07:02 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define DEPARTX 2
#define DEPARTY 2
#define PIC_WIDTH 500
#define PLAYER_SCREEN 200
#define UNITY 128
#define KEY_Z 119
#define KEY_Q 97
#define KEY_S 115
#define KEY_D 100
#define SPEED 10

double	simplifier(double angle)
{
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}

unsigned int	texture(t_case	wall, double y, t_text *text)
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

void	draw_pixel(int x, int y, unsigned int colour, t_cub3d *cub3d)
{
	if (x >= 0 && x < cub3d->width && y >= 0 && y < cub3d->height && colour)
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

unsigned int	skin_pixel(t_cub3d *cub3d, double ray, double y)
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
		return (0);
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

void	blackout(t_cub3d *cub3d, unsigned int color)
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
	{
		cub3d->player.p.x += cos(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y += sin(dtor(cub3d->player.ang)) / SPEED;
	}
	if (key_pressed == KEY_S)
	{
		cub3d->player.p.x -= cos(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y -= sin(dtor(cub3d->player.ang)) / SPEED;
	}
	if (key_pressed == KEY_Q)
	{
		cub3d->player.p.x -= sin(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y += cos(dtor(cub3d->player.ang)) / SPEED;
	}
	if (key_pressed == KEY_D)
	{
		cub3d->player.p.x += sin(dtor(cub3d->player.ang)) / SPEED;
		cub3d->player.p.y -= cos(dtor(cub3d->player.ang)) / SPEED;
	}
	update(cub3d);
	aerial(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img, 0, 0);
	return (1);
}

void	init_skins(t_cub3d *cub3d, char *path, char *path2)
{
	int	trash;

	if (!(cub3d->skins = malloc(sizeof(t_skin *) * 3)))
		return ;
	cub3d->skins[0].type = '2';
	cub3d->skins[0].skin.ptr = mlx_xpm_file_to_image(cub3d->mlx, path, &cub3d->skins[0].skin.width, &cub3d->skins[0].skin.height);
	cub3d->skins[0].skin.draw = (unsigned int *)mlx_get_data_addr(cub3d->skins[0].skin.ptr, &trash, &trash, &trash);
	cub3d->skins[1].type = '3';
	cub3d->skins[1].skin.ptr = mlx_xpm_file_to_image(cub3d->mlx, path2, &cub3d->skins[1].skin.width, &cub3d->skins[1].skin.height);
	cub3d->skins[1].skin.draw = (unsigned int *)mlx_get_data_addr(cub3d->skins[1].skin.ptr, &trash, &trash, &trash);
	cub3d->skins[2].type = 0;
}

int main()
{
	t_cub3d			cub3d;
	int				fd;
	int				trash;

	cub3d.player.p.x = 1.5;
	cub3d.player.p.y = 1.5;
	cub3d.player.ang = 0;
	if ((fd = open("test.cub", 'r')) < 0)
		return (-1);
	mapping(fd, &cub3d);
	//A faire plus tard = test erreur mapping et qui ferme proprement
	cub3d.mlx = mlx_init();
	cub3d.win = mlx_new_window(cub3d.mlx, 500, 500, "Test");
	cub3d.img = mlx_new_image(cub3d.mlx, 500, 500);
	cub3d.north.ptr = mlx_xpm_file_to_image(cub3d.mlx, "./textures/north.xpm", &cub3d.north.width, &cub3d.north.height);
	cub3d.north.draw = (unsigned int *)mlx_get_data_addr(cub3d.north.ptr, &trash, &trash, &trash);
	cub3d.south.ptr = mlx_xpm_file_to_image(cub3d.mlx, "./textures/south.xpm", &cub3d.south.width, &cub3d.south.height);
	cub3d.south.draw = (unsigned int *)mlx_get_data_addr(cub3d.south.ptr, &trash, &trash, &trash);
	cub3d.east.ptr = mlx_xpm_file_to_image(cub3d.mlx, "./textures/east.xpm", &cub3d.east.width, &cub3d.east.height);
	cub3d.east.draw = (unsigned int *)mlx_get_data_addr(cub3d.east.ptr, &trash, &trash, &trash);
	cub3d.west.ptr = mlx_xpm_file_to_image(cub3d.mlx, "./textures/west.xpm", &cub3d.west.width, &cub3d.west.height);
	cub3d.west.draw = (unsigned int *)mlx_get_data_addr(cub3d.west.ptr, &trash, &trash, &trash);
	cub3d.draw = (unsigned int *)mlx_get_data_addr(cub3d.img, &trash, &trash, &trash);
	init_skins(&cub3d, "./sprite/sprite1.xpm", "./textures/south.xpm");
	cub3d.ceiling = 0xb03a2e;
	cub3d.floor = 0x6c3483;
	cub3d.width = 500;
	cub3d.height = 500;
	if (!(cub3d.distances = malloc(sizeof(double) * cub3d.width)))
		return (-1);
	cub3d.fov = 60;
	cub3d.sprite = NULL;
	mlx_hook(cub3d.win, 2, (1L<<0), &key_press, &cub3d);
	printf("sprite %c : %s\nsprite %c : %s\n", cub3d.skins[0].type, cub3d.skins[0].skin.ptr ? "oui" : "non", cub3d.skins[1].type, cub3d.skins[1].skin.ptr ? "oui" : "non");
	update(&cub3d);
	aerial(&cub3d);
	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.img, 0, 0);
	mlx_loop(cub3d.mlx);
	return (0);
}