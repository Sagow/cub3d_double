/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:42:52 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 18:33:43 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	x_print_unsigned(va_list ap, t_param *p)
{
	if (p->conversion == 'H')
		hh_print_unsigned((unsigned char)va_arg(ap, int), p);
	if (p->conversion == 'h')
		h_print_unsigned((unsigned short)va_arg(ap, int), p);
	if (p->conversion == 'n')
		n_print_unsigned(va_arg(ap, unsigned int), p);
	if (p->conversion == 'l')
		l_print_unsigned(va_arg(ap, long unsigned int), p);
	if (p->conversion == 'L')
		ll_print_unsigned(va_arg(ap, long long unsigned int), p);
}
