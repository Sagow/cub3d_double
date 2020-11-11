/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:56:29 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/12/27 16:36:49 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		start(char const *s1, char const *set)
{
	int i;
	int j;
	int in;

	i = 0;
	in = 1;
	if (s1[i] == '\0')
		return (0);
	while (in == 1)
	{
		in = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				in = 1;
			j++;
		}
		i++;
	}
	return (--i);
}

static int		end(char const *s1, char const *set, int i)
{
	int j;
	int in;

	j = 0;
	in = 1;
	while (in == 1)
	{
		j = 0;
		in = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				in = 1;
			j++;
		}
		i--;
	}
	return (++i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s;
	int		e;
	char	*res;

	i = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	s = start(s1, set);
	if (s1[s] == '\0')
		return (ft_strdup(""));
	while (s1[i] != '\0')
		i++;
	e = end(s1, set, --i);
	if (!(res = malloc(sizeof(char) * (e - s + 2))))
		return (0);
	i = -1;
	while ((++i) <= e - s)
		res[i] = s1[s + i];
	res[i] = '\0';
	return (res);
}
