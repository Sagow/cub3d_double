/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:56:38 by marina            #+#    #+#             */
/*   Updated: 2020/09/20 19:54:56 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		filling_array(t_binary *new_array, t_binary *old_array, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (j < i)
		{
			/*new_array[j].c_x = old_array[j].c_x;
			new_array[j].c_y = old_array[j].c_y;
			new_array[j].type = old_array[j].type;*/
			new_array[j] = old_array[j];
		}
		if (j > i)
		{
			/*new_array[j + 1].c_x = old_array[j].c_x;
			new_array[j + 1].c_y = old_array[j].c_y;
			new_array[j + 1].type = old_array[j].type;*/
			new_array[j + 1] = old_array[j];
		}
		j++;
	}
}

t_binary	*create_node(int x, int y, char value, t_binary *array)
{
	int			i;
	int			size;
	t_binary	*new_array;

	i = 0;
	while (array && array[i].type && (x > array[i].c_x || (x == array[i].c_x && y < array[i].c_y)))
		i++;
	size = i;
	while (array && array[size].type)
		size++;
	size++;
	if (!(new_array = malloc(sizeof(t_binary) * (size + 1))))
		return (NULL);
	filling_array(new_array, array, i, size);
	new_array[i].c_x = x;
	new_array[i].c_y = y;
	new_array[i].type = value;
	new_array[size].type = 0;
	if (array)
		free(array);
	return (new_array);
}

t_binary	*translating(int fd)
{
	char		*buffer;
	t_binary	*array;
	int			line;
	int			i;

	buffer = NULL;
	array = NULL;
	line = 0;
	while (get_next_line(fd, &buffer) > 0)
	{
		i = 0;
		while (buffer && buffer[i])
		{
			if (buffer[i] != ' ' && buffer[i] != '0')
				array = create_node(i, line, buffer[i], array);
			i++;
		}
		line++;
	}
	i = 0;
	while (array[i].type)
	{
		array[i].c_y = line - array[i].c_y - 1;
		i++;
	}
	return (array);
}
/*
t_binary *tree_building(t_binary *array, int index)
{
	t_binary	*node;

	
}

t_binary	**temporary(int fd)
{
	t_binary	*array;
	t_binary	**tree;
	int			size;

	size = 0;
	array = translating(fd);
	while (array && array[size].type)
		size++;
	*tree = tree_building(array, size);
}

t_binary	*init(char type, int x, int y)
{
	t_binary	*node;

	if (!(node = malloc(sizeof(t_binary))))
		return (NULL);
	node->type = type;
	node->c_x = x;
	node->c_y = y;
	return (node);
}

void		init2(t_binary *node, t_binary *s, t_binary *b)
{
	node->smaller = s;
	node->bigger = b;
}

t_binary	**depannage(void)
{
	t_binary **res;
	t_binary *a;
	t_binary *b;
	t_binary *c;
	t_binary *d;
	t_binary *e;
	t_binary *f;

	//printf("repere\n");
	a = init('a', 2, 0);
	b = init('b', 1, 2);
	c = init('c', 4, 1);
	d = init('d', 0, 0);
	e = init('e', 3, 3);
	f = init('f', 4, 2);
	init2(a, b, c);
	init2(b, d, NULL);
	init2(c, e, f);
	init2(d, NULL, NULL);
	init2(e, NULL, NULL);
	init2(f, NULL, NULL);
	if (!(res = malloc(sizeof(t_binary *))))
		return (NULL);
	*res = a;
	//printf("repere\n");
	return (res);
}

void	print_binary(t_binary *node)
{
	if (node->smaller)
		print_binary(node->smaller);
	printf("x = %d, y = %d, type = %c\n", node->c_x, node->c_y, node->type);
	if (node->bigger)
		print_binary(node->bigger);
}
*/
int main(void)
{
	/*t_binary **test;

	test = depannage();
	print_binary(*test);
	*/
	t_binary	*array;
	int			fd;
	int			i;

	fd = open("test.cub", 'r');
	i = 0;
	array = NULL;
	array = translating(fd);
	while (array && array[i].type)
	{
		printf("x%d y%d t%c\n", array[i].c_x, array[i].c_y, array[i].type);
		i++;
	}
	return (0);
}