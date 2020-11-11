/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:46:02 by marina            #+#    #+#             */
/*   Updated: 2020/08/28 16:14:21 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <wchar.h>
# include <stdarg.h>
# include <limits.h>

typedef	struct		s_flag
{
	char			minus;
	char			plus;
	char			space;
	char			hashtag;
	char			zero;
	char			preci;
}					t_flag;

typedef	struct		s_param
{
	t_flag			flag;
	int				width;
	int				precision;
	char			conversion;
	int				length;
	char			letter;
	long long int	printed;
}					t_param;

int					ft_printf(const char *format, ...);
char				find_specifier(char *format, va_list ap, t_param *p);
void				init_param(t_param *p);
void				n_specifier(char *format, va_list ap, t_param *p);
/*
**-----------------------------------------------------------------------------
**						The commun functions, used everywhere
**-----------------------------------------------------------------------------
*/
void				my_write(char c, t_param *p);
void				minus(t_param *p);
void				fill_w_blanks(t_param *p);

/*
**-----------------------------------------------------------------------------
**							The "print" functions
**-----------------------------------------------------------------------------
*/
/*
**	no conversions possible
*/
void				print_address(void *address, t_param *p);
void				print_percent(t_param *p);
/*
**	choosing conversion
*/
void				x_print_char(va_list ap, t_param *p);
void				x_print_string(va_list ap, t_param *p);
void				x_print_int(va_list ap, t_param *p);
void				x_print_unsigned(va_list ap, t_param *p);
void				x_print_hexa_lower(va_list ap, t_param *p);
void				x_print_hexa_upper(va_list ap, t_param *p);
void				x_written_so_far(va_list ap, t_param *p);
/*
**	the default functions (no conversion)
*/
void				n_print_char(char c, t_param *p);
void				n_print_string(char *string, t_param *p);
void				n_print_int(int integ, t_param *p);
void				n_print_unsigned(unsigned int number, t_param *p);
void				n_print_hexa_lower(unsigned int number, t_param *p);
void				n_print_hexa_upper(unsigned int number, t_param *p);
void				n_written_so_far(int *n, t_param *p);
/*
**	converted in long (l)
*/
void				l_print_char(wint_t c, t_param *p);
void				l_print_string(wint_t *string, t_param *p);
void				l_print_int(long int integ, t_param *p);
void				l_print_unsigned(long unsigned int number, t_param *p);
void				l_print_hexa_lower(long unsigned int number, t_param *p);
void				l_print_hexa_upper(long unsigned int number, t_param *p);
void				l_written_so_far(long int *n, t_param *p);
/*
**	converted in long long (ll)
*/
void				ll_print_int(long long int integ, t_param *p);
void				ll_print_unsigned(long long unsigned int number, t_param
*p);
void				ll_print_hexa_lower(long long unsigned int number, t_param
*p);
void				ll_print_hexa_upper(long long unsigned int number, t_param
*p);
void				ll_written_so_far(long long int *n, t_param *p);
/*
**	converted in short (h)
*/
void				h_print_int(short int integ, t_param *p);
void				h_print_unsigned(short unsigned int number, t_param *p);
void				h_print_hexa_lower(short unsigned int number, t_param *p);
void				h_print_hexa_upper(short unsigned int number, t_param *p);
void				h_written_so_far(short int *n, t_param *p);
/*
**	converted in char (hh)
*/
void				hh_print_int(signed char integ, t_param *p);
void				hh_print_unsigned(unsigned char number, t_param *p);
void				hh_print_hexa_lower(unsigned char number, t_param *p);
void				hh_print_hexa_upper(unsigned char number, t_param *p);
void				hh_written_so_far(signed char *n, t_param *p);

#endif
