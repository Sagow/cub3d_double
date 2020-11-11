/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:23:05 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 18:49:54 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_flag	get_flags(char *format, t_flag flag, int i)
{
	while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
	format[i] == '#' || format[i] == '0')
	{
		if (format[i] == '-')
			flag.minus = 1;
		if (format[i] == '+')
			flag.plus = 1;
		if (format[i] == ' ')
			flag.space = 1;
		if (format[i] == '#')
			flag.hashtag = 1;
		if (format[i] == '0')
			flag.zero = 1;
		i++;
	}
	return (flag);
}

static int		get_width(char *format, int i, va_list ap, t_param *p)
{
	while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
	format[i] == '#' || format[i] == '0')
		i++;
	while (format[i] >= '0' && format[i] <= '9')
	{
		p->width = (p->width == -1 ? 0 : p->width);
		p->width = p->width * 10 + (format[i] - '0');
		i++;
	}
	if (format[i] == '*')
	{
		p->width = va_arg(ap, int);
		if (p->width < 0)
		{
			p->width *= -1;
			p->flag.minus = 1;
		}
		i++;
	}
	return (i);
}

static int		get_precision(char *format, int i, va_list ap, t_param *p)
{
	i++;
	p->flag.preci = 1;
	while (format[i] >= '0' && format[i] <= '9')
	{
		p->precision = (p->precision == -1 ? 0 : p->precision);
		p->precision = p->precision * 10 + (format[i] - '0');
		i++;
	}
	if (format[i] == '*')
	{
		p->precision = va_arg(ap, int);
		i++;
	}
	if (p->precision < 0)
	{
		p->precision = 0;
		p->flag.preci = 0;
	}
	return (i);
}

static int		get_conversion(char *format, int i, t_param *p)
{
	while (format[i] == 'l' || format[i] == 'h')
	{
		if (format[i] == 'l')
			p->conversion = (p->conversion == 'l') ? 'L' : 'l';
		if (format[i] == 'h')
			p->conversion = (p->conversion == 'h') ? 'H' : 'h';
		i++;
	}
	return (i);
}

char			find_specifier(char *format, va_list ap, t_param *p)
{
	int i;

	i = 1;
	init_param(p);
	p->flag = get_flags(format, p->flag, i);
	i = get_width(format, i, ap, p);
	if (format[i] == '.')
		i = get_precision(format, i, ap, p);
	i = get_conversion(format, i, p);
	return (format[i]);
}
