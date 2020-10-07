/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:11:49 by marina            #+#    #+#             */
/*   Updated: 2020/09/05 19:03:34 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_t_manip(t_manip *var, t_position *eye, double angle, char dir)
{
	var->eye = eye;
	var->ang = angle;
	var->dir = dir;
}