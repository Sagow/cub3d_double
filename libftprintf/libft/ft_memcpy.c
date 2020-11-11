/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:51:16 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/21 20:37:09 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*desti;

	source = src;
	desti = dst;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		*desti = *source;
		source++;
		desti++;
		n--;
	}
	return (dst);
}
