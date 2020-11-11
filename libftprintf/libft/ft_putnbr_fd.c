/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 05:30:04 by mdelwaul          #+#    #+#             */
/*   Updated: 2019/11/17 19:04:03 by mdelwaul         ###   ########.fr       */
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

void			ft_putnbr_fd(int n, int fd)
{
	int			size;
	long int	number;
	char		c;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = number * (-1);
	}
	size = get_size(number);
	while (size > 0)
	{
		size--;
		c = (number / power(size) + '0');
		write(fd, &c, 1);
		number = number - (number / power(size) * power(size));
	}
}
