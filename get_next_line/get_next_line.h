/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 03:08:27 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/02/04 05:38:27 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_buffer
{
	char		buffer[BUFFER_SIZE];
	int			w;
	int			r;
}				t_buffer;

char			*ft_fill(t_buffer *b, int fd, char *line);
int				size(t_buffer *b, int fd, char *line);
void			ft_read(t_buffer *b, int fd);
char			*wierd(t_buffer *b, int fd, char *line);
void			cycle(t_buffer *b, int fd, char **line);
int				get_next_line(int fd, char **line);

#endif
