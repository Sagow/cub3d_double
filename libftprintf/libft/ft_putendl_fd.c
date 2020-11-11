/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:25:21 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/21 20:37:37 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int size;

	if (!s)
		return ;
	size = 0;
	while (s[size] != '\0')
		size++;
	write(fd, s, size);
	write(fd, "\n", 1);
}
