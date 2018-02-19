/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:21:28 by aderby            #+#    #+#             */
/*   Updated: 2017/07/10 15:56:47 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

int		rotate_x(t_wincon *wincon, float degrees)
{
	double	y;
	double	z;
	t_point	*tmp;

	tmp = wincon->map->point;
//	blacken_points(&wincon);
	while (tmp)
	{
		y = tmp->y;
		z = tmp->z;
		tmp->y = (cos(degrees) * y) + (sin(degrees) * z);
		tmp->z = (-sin(degrees) * y) + (cos(degrees) * z);
		tmp = tmp->next;
	}
	draw_image(&wincon);
	return (1);
}

int		rotate_y(t_wincon *wincon, float degrees)
{
	double	x;
	double	z;
	t_point	*tmp;

	tmp = wincon->map->point;
//	blacken_points(&wincon);
	while (tmp)
	{
		x = tmp->x;
		z = tmp->z;
		tmp->x = (cos(degrees) * x) + (-sin(degrees) * z);
		tmp->z = (sin(degrees) * x) + (cos(degrees) * z);
		tmp = tmp->next;
	}
	draw_image(&wincon);
	return (1);
}

int		rotate_z(t_wincon *wincon, float degrees)
{
	double	x;
	double	y;
	t_point	*tmp;

	tmp = wincon->map->point;
//	blacken_points(&wincon);
	while (tmp)
	{
		x = tmp->x;
		y = tmp->y;
		tmp->x = (cos(degrees) * x) + (sin(degrees) * y);
		tmp->y = ((-sin(degrees)) * x) + (cos(degrees) * y);
		tmp = tmp->next;
	}
	draw_image(&wincon);
	return (1);
}
