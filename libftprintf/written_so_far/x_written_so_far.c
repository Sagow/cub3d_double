/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_written_so_far.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:14:32 by marina            #+#    #+#             */
/*   Updated: 2020/08/27 19:22:23 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	x_written_so_far(va_list ap, t_param *p)
{
	if (p->conversion == 'H')
		hh_written_so_far((signed char *)va_arg(ap, int *), p);
	if (p->conversion == 'h')
		h_written_so_far((short *)va_arg(ap, int *), p);
	if (p->conversion == 'n')
		n_written_so_far(va_arg(ap, int *), p);
	if (p->conversion == 'l')
		l_written_so_far(va_arg(ap, long int *), p);
	if (p->conversion == 'L')
		ll_written_so_far(va_arg(ap, long long int *), p);
}
