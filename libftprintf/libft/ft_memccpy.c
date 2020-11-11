/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:52:42 by marina            #+#    #+#             */
/*   Updated: 2019/11/18 18:23:25 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*source;
	unsigned char		*desti;
	size_t				i;

	i = 0;
	if (!dst && !src)
		return (0);
	source = (unsigned char*)src;
	desti = (unsigned char*)dst;
	while (i < n)
	{
		*desti = *source;
		if (*source == (unsigned char)c)
			return (dst + i + 1);
		source++;
		desti++;
		i++;
	}
	return (NULL);
}
