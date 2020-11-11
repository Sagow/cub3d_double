/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:11:49 by marina            #+#    #+#             */
/*   Updated: 2020/11/11 06:46:31 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	uinit_t_manip(t_manip *var, t_position *eye, double angle, char dir)
{
	var->eye = eye;
	var->ang = angle;
	var->dir = dir;
}