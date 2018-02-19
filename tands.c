/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tands.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 01:59:57 by aderby            #+#    #+#             */
/*   Updated: 2017/07/30 13:29:59 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

int		translate(t_wincon *wincon, int x_dist, int y_dist)
{
	t_point *tmp;

	tmp = wincon->map->point;
//	blacken_points(&wincon);
	while (tmp->next)
	{
		tmp->tx += x_dist;
		tmp->ty += y_dist;
		tmp = tmp->next;
	}
	draw_image(&wincon);
	return (1);
}

int		scale(t_wincon *wincon, double multiplier)
{
	t_point *tmp;

	tmp = wincon->map->point;
	while (tmp)
	{
		tmp->x *= multiplier;
		tmp->y *= multiplier;
		tmp->z *= multiplier;
		tmp = tmp->next;
	}
	draw_image(&wincon);
	return (1);
}
