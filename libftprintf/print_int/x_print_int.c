/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:36:04 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 18:31:54 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	x_print_int(va_list ap, t_param *p)
{
	if (p->conversion == 'H')
		hh_print_int((signed char)va_arg(ap, int), p);
	if (p->conversion == 'h')
		h_print_int((short)va_arg(ap, int), p);
	if (p->conversion == 'n')
		n_print_int(va_arg(ap, int), p);
	if (p->conversion == 'l')
		l_print_int(va_arg(ap, long int), p);
	if (p->conversion == 'L')
		ll_print_int(va_arg(ap, long long int), p);
}
