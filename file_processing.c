#include "cub3d.h"

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
		error(DESC_MISSING, "resolution");
	if (!cub3d->ceiling)
		error(DESC_MISSING, "ceiling");
	if (!cub3d->floor)
		error(DESC_MISSING, "floor");
	if (!cub3d->sprite)
		error(DESC_MISSING, "sprite");
	if (!cub3d->east.ptr)
		error(DESC_MISSING, "east texture");
	if (!cub3d->north.ptr)
		error(DESC_MISSING, "north texture");
	if (!cub3d->south.ptr)
		error(DESC_MISSING, "south texture");
	if (!cub3d->west.ptr)
		error(DESC_MISSING, "west texture");
}

void		init_cub3d(t_cub3d *cub3d)
{
	cub3d->width = 0;
	cub3d->height = 0;
	cub3d->floor = 0;
	cub3d->ceiling = 0;
	cub3d->skins = NULL;
	cub3d->east.ptr = NULL;
	cub3d->north.ptr = NULL;
	cub3d->south.ptr = NULL;
	cub3d->west.ptr = NULL;
}

void		file_processing(int fd, t_cub3d *cub3d)
{
	int		gnl;
	char	*line;
	int		i;

	printf("2\n");
	init_cub3d(cub3d);
	line = NULL;
	printf("3\n");

	gnl = get_next_line(fd, &line);
	printf("4\n");

	while (gnl > 0)
	{
		printf("line = %s\n", line);
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
		else if (i >= 0 && line[i])
			error(DESC_WRONG_CHAR, line);
		my_free(line);
		gnl = get_next_line(fd, &line);
	printf("5\n");

	}
	printf("9\n");

	if (gnl < 0)
		error(DESC_GNL, "file processing");
	check_processed(cub3d);
}

int main(void)
{
	int		fd;
	t_cub3d	cub3d;

	fd = open("process.cub", 'r');
	printf("1\n");
	cub3d.mlx = mlx_init();
	if (fd > 0)
		file_processing(fd, &cub3d);
	else
		printf("fd = %d\n", fd);
	
}

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