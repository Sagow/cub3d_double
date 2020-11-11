/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:51:54 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/21 20:38:02 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_copy;

	i = 0;
	s_copy = (char *)s;
	while (s_copy[i] != c && s_copy[i] != '\0')
	{
		i++;
	}
	if (s_copy[i] == c)
	{
		return (&s_copy[i]);
	}
	else
	{
		return (0);
	}
}
