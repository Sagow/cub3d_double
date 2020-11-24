/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marina <marina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:27:06 by marina            #+#    #+#             */
/*   Updated: 2020/11/24 12:44:27 by marina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double	ang_cal(int opp1, int opp2, int adj1, int adj2)
{
	double	opp;
	double	adj;

	opp = (opp1 > opp2) ? opp1 - opp2 : opp2 - opp1;
	adj = (adj1 > adj2) ? adj1 - adj2 : adj2 - adj1;
	return (180 * atan(opp / adj) / M_PI);
}

double	rtod(double rad)
{
	return (simplifier(rad * 180 / M_PI));
}

double	dtor(double angle)
{
	return (angle * M_PI / 180);
}

double	fmod(double number, double div)
{
	while (number >= (div - 0.1))
		number -= div;
	return (number);
}

double	simplifier(double angle)
{
	while (angle < 0)
		angle += 360;
	while (angle >= 360)
		angle -= 360;
	return (angle);
}
