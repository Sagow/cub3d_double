/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:59:29 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/17 19:00:09 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(long int number)
{
	int res;

	res = 1;
	while (number > 9)
	{
		number = number / 10;
		res++;
	}
	return (res);
}

static long int	power(int p)
{
	long int res;

	res = 1;
	while (p > 0)
	{
		res = res * 10;
		p--;
	}
	return (res);
}

static void		filler(int n, long int number, int size, char *res)
{
	if (n < 0)
	{
		size--;
		*res = '-';
		res++;
	}
	while (size > 0)
	{
		size--;
		*res = (number / power(size) + '0');
		res++;
		number = number - (number / power(size) * power(size));
	}
	*res = '\0';
}

char			*ft_itoa(int n)
{
	int			size;
	long int	number;
	char		*res;
	char		*start;

	number = n;
	size = 0;
	if (number < 0)
	{
		size++;
		number = number * (-1);
	}
	size = size + get_size(number);
	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (0);
	start = res;
	filler(n, number, size, res);
	return (start);
}
