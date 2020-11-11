/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   written_so_far.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:21:11 by mdelwaul          #+#    #+#             */
/*   Updated: 2020/08/27 17:38:03 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void			hh_written_so_far(signed char *n, t_param *p)
{
	*n = *(signed char *)p->printed;
}

void			h_written_so_far(short int *n, t_param *p)
{
	*n = *(short int *)p->printed;
}

void			n_written_so_far(int *n, t_param *p)
{
	*n = *(int *)p->printed;
}

void			l_written_so_far(long int *n, t_param *p)
{
	*n = *(long int *)p->printed;
}

void			ll_written_so_far(long long int *n, t_param *p)
{
	*n = *(long long int *)p->printed;
}
