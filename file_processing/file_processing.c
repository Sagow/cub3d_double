#include "../includes/cub3d.h"

void		my_free(void *pointer)
{
	if (pointer)
	{
		free(pointer);
		pointer = NULL;
	}
}

int			space(char *line, int i)
{
	if (!line)
		return (-2);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i])
		return (i);
	return (-1);
}

void		check_processed(t_cub3d *cub3d)
{
	if (!cub3d->width || !cub3d->height)
		ft_error(DESC_MISSING, "resolution");
	if (!cub3d->ceiling.a)
		ft_error(DESC_MISSING, "ceiling");
	if (!cub3d->floor.a)
		ft_error(DESC_MISSING, "floor");
	if (!cub3d->skins)
		ft_error(DESC_MISSING, "sprite");
	if (!cub3d->east.ptr)
		ft_error(DESC_MISSING, "east texture");
	if (!cub3d->north.ptr)
		ft_error(DESC_MISSING, "north texture");
	if (!cub3d->south.ptr)
		ft_error(DESC_MISSING, "south texture");
	if (!cub3d->west.ptr)
		ft_error(DESC_MISSING, "west texture");
}

void		init_cub3d(t_cub3d *cub3d)
{
	cub3d->width = 0;
	cub3d->height = 0;
	cub3d->floor.a = 0;
	cub3d->ceiling.a = 0;
	cub3d->skins = NULL;
	cub3d->east.ptr = NULL;
	cub3d->north.ptr = NULL;
	cub3d->south.ptr = NULL;
	cub3d->west.ptr = NULL;
	cub3d->map = NULL;
	cub3d->player.p.x = -1;
	cub3d->player.p.y = -1;
}

void		file_processing(int fd, t_cub3d *cub3d)
{
	int		gnl;
	char	*line;
	int		i;

	init_cub3d(cub3d);
	line = NULL;
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		i = 0;
		i = space(line, i);
		if (i >= 0 && line[i] == 'C')
			fp_ceiling(cub3d, line, ++i);
		else if (i >= 0 && line[i] == 'E')
			fp_east(cub3d, line, ++i);
		else if (i >= 0 && line[i] == 'F')
			fp_floor(cub3d, line, ++i);
		else if (i >= 0 && line[i] == 'N')
			fp_north(cub3d, line, ++i);
		else if (i >= 0 && line[i] == 'R')
			fp_resolution(cub3d, line, ++i);
		else if (i >= 0 && line[i] == 'S')
		{
			if (line[i + 1] == 'O')
				fp_south(cub3d, line, ++i);
			else
				fp_sprite(cub3d, line, ++i);
		}
		else if (i >= 0 && line[i] == 'W')
			fp_west(cub3d, line, ++i);
		else if (i >= 0 && line[i] == '1')
			fp_map(cub3d, fd, line);
		else if (i >= 0 && line[i])
			ft_error(DESC_WRONG_CHAR, line);
		my_free(line);
		gnl = get_next_line(fd, &line);
	}
	if (gnl < 0)
		ft_error(DESC_GNL, "file processing");
}
/*
void	test_print(t_cub3d *cub3d)
{
	printf("floor (%d) %d, %d, %d\n", cub3d->floor.a, cub3d->floor.r, cub3d->floor.g, cub3d->floor.b);
	printf("ceiling (%d) %d, %d, %d\n", cub3d->ceiling.a, cub3d->ceiling.r, cub3d->ceiling.g, cub3d->ceiling.b);

}

void	test_map(t_cub3d *cub3d)
{
	int i;

	i = 0;
	while (i < cub3d->map_y)
	{
		printf("|%s| %d\n", cub3d->map[i], i);
		i++;
	}
}

int main(void)
{
	int		fd;
	t_cub3d	cub3d;

	fd = open("process.cub", 'r');
	cub3d.mlx = mlx_init();
	if (fd > 0)
		file_processing(fd, &cub3d);
	else
		printf("fd = %d\n", fd);
	test_print(&cub3d);
	test_map(&cub3d);
}*/

/*
//A faire plus tard = ranger chaque nouvelle ligne dans une liste chainee puis tout mettre dans un tableau
void		mapping(int fd, t_cub3d *cub3d)
{
	char	**new_map;
	char	*line;
	int		i;
	int		gnl;

	line = NULL;
	if (!(cub3d->map = malloc(sizeof(char *))))
		return ;
	*cub3d->map = NULL;
	cub3d->map_y = 0;
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		cub3d->map_y++;
		i = 0;
		while (cub3d->map[i])
			i++;
		if (!(new_map = malloc(sizeof(char *) * (i + 2))))
			return ;
		i = -1;
		while (cub3d->map[++i])
			new_map[i] = cub3d->map[i];
		if (!(new_map[i] = malloc(sizeof(char) * ((int)strlen(line) + 1))))
			return ;
		strcpy(new_map[i], line);
		new_map[i + 1] = NULL;
		my_free(cub3d->map);
		my_free(line);
		cub3d->map = new_map;
	}
	cub3d->map_x = (int)strlen(cub3d->map[0]);
}
*/
/*
int		main(void)
{
	int		fd;
	char	**map;
	int		i;

	map = NULL;
	i = 0;
	if ((fd = open("test.cub", 'r')) < 0)
		return (-1);
	printf ("Lancement\n");
	map = mapping(fd);
	printf ("Mapping termine\n");
	if (!map)
		printf("Echec ! map est vide !\n");
	else
	{
		while (map[i])
		{
			printf("-%s-\n", map[i]);
			my_free(map[i]);
			i++;
		}
		my_free(map);
	}
	return (0);
}
*/