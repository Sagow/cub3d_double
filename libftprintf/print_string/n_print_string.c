/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_print_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 04:48:01 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 19:22:41 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		print(char *string, t_param *p)
{
	int	i;

	i = 0;
	while (i < p->length)
	{
		my_write(string[i], p);
		i++;
	}
}

static void		which_smaller(t_param *p)
{
	if (p->precision >= 0 && p->flag.preci && p->length > p->precision)
		p->length = p->precision;
}

void			n_print_string(char *string, t_param *p)
{
	if (string == NULL)
	{
		p->length = 6;
		which_smaller(p);
		fill_w_blanks(p);
		print("(null)", p);
		minus(p);
	}
	else
	{
		if (p->flag.preci && p->precision == 0)
			p->length = 0;
		else
			p->length = ft_strlen(string);
		which_smaller(p);
		fill_w_blanks(p);
		if (p->precision || !p->flag.preci)
			print(string, p);
		minus(p);
	}
}
