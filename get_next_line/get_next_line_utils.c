/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 03:41:43 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/02/04 04:58:22 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_read(t_buffer *b, int fd)
{
	b[fd].r = read(fd, b[fd].buffer, BUFFER_SIZE);
	if (b[fd].r > 0)
		b[fd].w = 0;
	else
		b[fd].w = 1;
}

int			size(t_buffer *b, int fd, char *line)
{
	int		size;
	int		i;

	size = 0;
	i = b[fd].w;
	while (i < b[fd].r && b[fd].buffer[i] != '\n')
		i++;
	while (line && line[size])
		size++;
	size += i;
	return (size);
}

char		*ft_fill(t_buffer *b, int fd, char *line)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(char) * (size(b, fd, line) + 1))))
	{
		b[fd].r = -1;
		return (NULL);
	}
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (b[fd].w < b[fd].r && b[fd].buffer[b[fd].w] != '\n')
	{
		new[i] = b[fd].buffer[b[fd].w];
		i++;
		b[fd].w++;
	}
	new[i] = '\0';
	return (new);
}
