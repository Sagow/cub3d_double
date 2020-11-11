/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:23:48 by marina            #+#    #+#             */
/*   Updated: 2020/02/05 04:28:26 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		skip_to_char(const char *format)
{
	int i;

	i = 1;
	while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
	format[i] == '#' || format[i] == '0')
		i++;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '*')
		i++;
	if (format[i] == '.')
	{
		i++;
		while (format[i] >= '0' && format[i] <= '9')
			i++;
		if (format[i] == '*')
			i++;
	}
	while (format[i] == 'l' || format[i] == 'h')
		i++;
	i++;
	return (i);
}

void	init_param(t_param *p)
{
	p->flag.minus = 0;
	p->flag.plus = 0;
	p->flag.space = 0;
	p->flag.hashtag = 0;
	p->flag.zero = 0;
	p->flag.preci = 0;
	p->width = -1;
	p->precision = 0;
	p->conversion = 'n';
	p->length = -1;
	p->letter = '\0';
}

int		ft_printf(const char *format, ...)
{
	char	*pointeur;
	va_list	ap;
	t_param p;

	p.printed = 0;
	va_start(ap, format);
	pointeur = (char *)format;
	while (*pointeur != '\0')
	{
		if (*pointeur == '%')
		{
			n_specifier((char*)pointeur, ap, &p);
			pointeur += skip_to_char(pointeur);
		}
		else
		{
			my_write(*pointeur, &p);
			pointeur++;
		}
	}
	return (p.printed);
}
