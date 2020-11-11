/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:08:44 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/21 20:37:00 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		if (*temp == (unsigned char)c)
			return (temp);
		temp++;
		n--;
	}
	return (0);
}
