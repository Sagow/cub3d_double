/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:49:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/20 17:05:06 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	buffer[len];

	if (dst == NULL && src == NULL)
		return (NULL);
	ft_memcpy(buffer, src, len);
	ft_memcpy(dst, buffer, len);
	return (dst);
}
