/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 04:18:54 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/21 20:31:53 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	size_t	size_dst;

	i = 0;
	j = 0;
	size_dst = ft_strlen(dst);
	if (dstsize <= size_dst || dstsize == 0)
		return (dstsize + ft_strlen(src));
	if (!src)
		return (size_dst);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + size_dst);
}
