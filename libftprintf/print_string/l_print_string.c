/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_print_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:00:41 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 18:32:17 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		l_my_write(wint_t c, t_param *p)
{
	write(1, &c, 4);
	p->printed++;
}

static void		print(wint_t *string, t_param *p)
{
	int	i;

	i = 0;
	while (i < p->length)
	{
		l_my_write(string[i], p);
		i++;
	}
}

static void		which_smaller(t_param *p)
{
	if (p->precision >= 0 && p->flag.preci && p->length > p->precision)
		p->length = p->precision;
}

void			l_print_string(wint_t *string, t_param *p)
{
	if (string == NULL)
	{
		p->length = 6;
		which_smaller(p);
		fill_w_blanks(p);
		print((wint_t *)"(null)", p);
		minus(p);
	}
	else
	{
		if (p->flag.preci && p->precision == 0)
			p->length = 0;
		else
			p->length = ft_strlen((char *)string);
		which_smaller(p);
		fill_w_blanks(p);
		if (p->precision || !p->flag.preci)
			print(string, p);
		minus(p);
	}
}
