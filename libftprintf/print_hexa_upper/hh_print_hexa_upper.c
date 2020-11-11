/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hh_print_hexa_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:45:17 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 19:26:04 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int		size_number(unsigned char number, t_param *p)
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

static	void	print_number(unsigned char number, t_param *p)
{
	unsigned short		div;
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
		+ 'A');
		my_write(c, p);
		number %= div;
		div /= 16;
		i--;
	}
}

void			hh_print_hexa_upper(unsigned char number, t_param *p)
{
	int	i;

	i = 0;
	p->length = size_number(number, p);
	p->length = (p->length < p->precision ? p->precision : p->length);
	if (p->flag.hashtag && number)
		p->length += 2;
	fill_w_blanks(p);
	if (p->flag.hashtag && number)
	{
		my_write('0', p);
		my_write('X', p);
	}
	while (size_number(number, p) + i++ < p->precision)
		my_write('0', p);
	if (!p->flag.preci || p->precision > 0 || number)
		print_number(number, p);
	minus(p);
}
