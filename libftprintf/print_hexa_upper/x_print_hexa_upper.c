/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print_hexa_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:47:56 by marina            #+#    #+#             */
/*   Updated: 2020/08/27 18:30:49 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	x_print_hexa_upper(va_list ap, t_param *p)
{
	if (p->conversion == 'H')
		hh_print_hexa_upper((unsigned char)va_arg(ap, int), p);
	if (p->conversion == 'h')
		h_print_hexa_upper((unsigned short)va_arg(ap, int), p);
	if (p->conversion == 'n')
		n_print_hexa_upper(va_arg(ap, unsigned int), p);
	if (p->conversion == 'l')
		l_print_hexa_upper(va_arg(ap, long unsigned int), p);
	if (p->conversion == 'L')
		ll_print_hexa_upper(va_arg(ap, long long unsigned int), p);
}
