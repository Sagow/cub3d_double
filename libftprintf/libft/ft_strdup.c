/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 01:27:58 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/21 20:38:07 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*copy;

	size = 0;
	while (s1[size] != '\0')
	{
		size++;
	}
	if (!(copy = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (size >= 0)
	{
		copy[size] = s1[size];
		size--;
	}
	return (copy);
}
