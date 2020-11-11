/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:53:14 by marina            #+#    #+#             */
/*   Updated: 2019/12/30 15:56:15 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		words++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (words);
}

static int	my_abort(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j]);
		res[j] = 0;
		j--;
	}
	return (0);
}

static int	mini_malloc(char const *s, char c, char **res)
{
	int		j;
	int		i;
	int		size_word;

	j = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		size_word = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			size_word++;
			i++;
		}
		if (!(res[j] = malloc(sizeof(char) * (size_word + 1))))
			return (my_abort(res, j - 1));
		j++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	if (!(res[j] = malloc(sizeof(char))))
		return (my_abort(res, j - 1));
	return (j + 1);
}

static void	filler(char const *s, char c, char **res)
{
	int		k;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			res[j][k] = s[i];
			i++;
			k++;
		}
		res[j][k] = '\0';
		j++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	res[j] = NULL;
}

char		**ft_split(char const *s, char c)
{
	int		size;
	char	**res;

	if (!s)
		return (0);
	size = wordcount(s, c);
	if (!(res = malloc(sizeof(char*) * (size + 1))))
		return (0);
	if (!(mini_malloc(s, c, res)))
	{
		free(res);
		res = 0;
		return (0);
	}
	filler(s, c, res);
	return (res);
}
