/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 04:29:46 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 17:44:14 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	my_write(char c, t_param *p)
{
	write(1, &c, 1);
	p->printed++;
}

void	fill_w_blanks(t_param *p)
{
	int	i;

	i = 0;
	while (!p->flag.minus && p->width > (p->length + i))
	{
		my_write(p->flag.zero ? '0' : ' ', p);
		i++;
	}
}

void	minus(t_param *p)
{
	int	i;

	i = 0;
	while (p->flag.minus && p->width > (p->length + i))
	{
		my_write(' ', p);
		i++;
	}
}
