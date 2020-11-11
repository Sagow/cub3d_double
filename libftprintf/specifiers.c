/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:39:54 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 17:49:41 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		n_specifier(char *format, va_list ap, t_param *p)
{
	p->letter = find_specifier(format, ap, p);
	if (p->letter == 'c')
		x_print_char(ap, p);
	if (p->letter == 's')
		x_print_string(ap, p);
	if (p->letter == 'p')
		print_address(va_arg(ap, void *), p);
	if (p->letter == 'd' || p->letter == 'i')
		x_print_int(ap, p);
	if (p->letter == 'u')
		x_print_unsigned(ap, p);
	if (p->letter == 'x')
		x_print_hexa_lower(ap, p);
	if (p->letter == 'X')
		x_print_hexa_upper(ap, p);
	if (p->letter == 'n')
		x_written_so_far(ap, p);
	if (p->letter == '%')
		print_percent(p);
}
