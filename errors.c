/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 03:44:43 by marina            #+#    #+#             */
/*   Updated: 2020/11/18 18:06:52 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_error(char *message, char *place)
{
	ft_printf("Error\n%s (in %s)\n", message, place);
	exit(0);
}
