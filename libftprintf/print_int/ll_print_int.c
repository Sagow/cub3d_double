/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:54:14 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/28 15:58:04 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int		size_number(long long unsigned int integer, t_param *p)
{
	int	i;

	i = 1;
	if (integer == 0 && p->flag.preci && p->precision == 0)
		return (0);
	while (integer > 9)
	{
		integer /= 10;
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

void			ll_print_int(long long int integ, t_param *p)
{
	long long unsigned int	integer;
	int						i;

	i = 0;
	integer = (long long unsigned int)(integ < 0 ? integ * -1 : integ);
	p->length = size_number(integer, p);
	p->length = (p->length < p->precision ? p->precision : p->length);
	if (p->flag.plus || p->flag.space || integ < 0)
		p->length++;
	if (p->flag.preci && p->precision >= 0)
		p->flag.zero = 0;
	if (!p->flag.zero)
		fill_w_blanks(p);
	if (integ < 0)
		my_write('-', p);
	if ((p->flag.plus || p->flag.space) && integ >= 0)
		my_write(p->flag.plus ? '+' : ' ', p);
	if (p->flag.zero)
		fill_w_blanks(p);
	while (size_number(integer, p) + i++ < p->precision)
		my_write('0', p);
	if (!p->flag.preci || p->precision > 0 || integer)
		print_number(integer, p);
	minus(p);
}
