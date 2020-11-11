/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:32:07 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/26 18:43:56 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	x_print_string(va_list ap, t_param *p)
{
	if (p->conversion == 'l')
		l_print_string(va_arg(ap, wint_t *), p);
	else
		n_print_string(va_arg(ap, char *), p);
}
