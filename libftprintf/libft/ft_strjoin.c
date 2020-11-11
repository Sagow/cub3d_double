/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:43:03 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/12/27 18:26:24 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*filling(char const *s1, char const *s2, int size1, int size2)
{
	int		i;
	char	*uni;

	i = 0;
	if (!(uni = malloc(sizeof(char) * (size1 + size2 + 1))))
		return (0);
	if (s1)
		while (i < size1)
		{
			uni[i] = s1[i];
			i++;
		}
	if (s2)
		while (i < size1 + size2)
		{
			uni[i] = s2[i - size1];
			i++;
		}
	uni[i] = '\0';
	return (uni);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*uni;
	int		size1;
	int		size2;

	size1 = 0;
	size2 = 0;
	if (s1)
		while (s1[size1] != '\0')
			size1++;
	if (s2)
		while (s2[size2] != '\0')
			size2++;
	uni = filling(s1, s2, size1, size2);
	return (uni);
}
