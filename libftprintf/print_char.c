/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 04:13:46 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/26 21:46:12 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		l_my_write(wint_t c, t_param *p)
{
	write(1, &c, 4);
	p->printed++;
}

void			n_print_char(char c, t_param *p)
{
	p->length = 1;
	fill_w_blanks(p);
	my_write((char)c, p);
	minus(p);
}

void			l_print_char(wint_t c, t_param *p)
{
	p->length = 1;
	fill_w_blanks(p);
	l_my_write((wint_t)c, p);
	minus(p);
}

void			x_print_char(va_list ap, t_param *p)
{
	if (p->conversion == 'l')
		l_print_char(va_arg(ap, wint_t), p);
	else
		n_print_char((char)va_arg(ap, int), p);
}
