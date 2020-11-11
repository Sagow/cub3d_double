/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:13:13 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/12/30 16:03:39 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	int					j;
	int					size;
	char				*sub;

	i = 0;
	j = 0;
	size = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && i < start)
		i++;
	while (s[i + size] != '\0' && (size_t)size < len)
		size++;
	if (!(sub = malloc((sizeof(char) * (size + 1)))))
		return (0);
	while (s[i] && j < size)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
