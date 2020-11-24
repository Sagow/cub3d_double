/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 03:05:37 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/11/24 13:09:18 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			jump(t_buffer *b, int fd)
{
	if (b[fd].buffer[b[fd].w] == '\n')
		return (1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static t_buffer	b[FD_SETSIZE];
	char			*res;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	res = NULL;
	cycle(b, fd, &res);
	b[fd].w += jump(b, fd);
	res = wierd(b, fd, res);
	if (b[fd].r != -1)
		*line = res;
	else if (res)
	{
		free(res);
		res = NULL;
	}
	return (b[fd].r > 0 ? 1 : b[fd].r);
}

void		cycle(t_buffer *b, int fd, char **line)
{
	char			*temp;

	temp = NULL;
	if (b[fd].w >= b[fd].r)
		ft_read(b, fd);
	while (b[fd].r > 0 && b[fd].buffer[b[fd].w] != '\n')
	{
		if (b[fd].w >= b[fd].r)
			ft_read(b, fd);
		temp = ft_fill(b, fd, *line);
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		*line = temp;
	}
	if (b[fd].w >= b[fd].r)
		ft_read(b, fd);
}

char		*wierd(t_buffer *b, int fd, char *line)
{
	char	*empty;

	if ((empty = malloc(sizeof(char))))
	{
		empty[0] = '\0';
		if (!line && b[fd].r >= 0)
			return (empty);
		free(empty);
	}
	return (line);
}
