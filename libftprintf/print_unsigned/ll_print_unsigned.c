/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:16:57 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 19:27:46 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int		size_number(long long unsigned int number, t_param *p)
{
	int	i;

	i = 1;
	if (number == 0 && p->flag.preci && p->precision == 0)
		return (0);
	while (number > 9)
	{
		number /= 10;
		i++;
	}
	return (i);
}

static	void	print_number(long long unsigned int number, t_param *p)
{
	long long unsigned int	div;
	int						i;

	div = 1;
	i = 1;
	while (i < size_number(number, p))
	{
		div *= 10;
		i++;
	}
	while (i > 0)
	{
		my_write('0' + number / div, p);
		number %= div;
		div /= 10;
		i--;
	}
}

void			ll_print_unsigned(long long unsigned int number, t_param *p)
{
	int	i;

	i = 0;
	if (p->precision >= 0 && p->flag.preci)
		p->flag.zero = 0;
	p->length = size_number(number, p);
	p->length = (p->length < p->precision ? p->precision : p->length);
	fill_w_blanks(p);
	while (size_number(number, p) + i++ < p->precision)
		my_write('0', p);
	if (!p->flag.preci || p->precision > 0 || number)
		print_number(number, p);
	minus(p);
}
