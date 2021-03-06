/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 03:28:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/20 06:26:07 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		size_number(long unsigned int number, t_param *p)
{
	int	i;

	i = 1;
	if (number == 0 && p->flag.preci && p->precision == 0)
		return (0);
	while (number > 15)
	{
		number /= 16;
		i++;
	}
	return (i);
}

static	void	print_number(long unsigned int number, t_param *p)
{
	long unsigned int	div;
	int					i;
	char				c;

	div = 1;
	i = 1;
	while (i < size_number(number, p))
	{
		div *= 16;
		i++;
	}
	while (i > 0)
	{
		c = (number / div < 10) ? (number / div + '0') : (number / div - 10
		+ 'a');
		my_write(c, p);
		number %= div;
		div /= 16;
		i--;
	}
}

void			print_address(void *address, t_param *p)
{
	long unsigned int	number;
	int					i;

	number = (long unsigned int)address;
	i = 0;
	if (p->precision >= 0 && p->flag.preci)
		p->flag.zero = 0;
	p->length = size_number(number, p);
	p->length = (p->length < p->precision ? p->precision : p->length);
	p->length += 2;
	if (!p->flag.zero)
		fill_w_blanks(p);
	my_write('0', p);
	my_write('x', p);
	if (p->flag.zero)
		fill_w_blanks(p);
	while (size_number(number, p) + i++ < p->precision)
		my_write('0', p);
	if (!p->flag.preci || p->precision > 0 || number)
		print_number(number, p);
	minus(p);
}
