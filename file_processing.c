#include "cub3d.h"

void		my_free(void *pointer)
{
	if (pointer)
	{
		free(pointer);
		pointer = NULL;
	}
}

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