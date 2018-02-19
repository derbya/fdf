/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:23:30 by aderby            #+#    #+#             */
/*   Updated: 2017/07/10 16:00:10 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

int			mouse_release(int button, int x, int y, t_wincon *wincon)
{
	button *= 1;
	x *= 1;
	y *= 1;
	wincon->mouse = 0;
	return (1);
}

int			mouse_press(int button, int x, int y, t_wincon *wincon)
{
	button *= 1;
	x *= 1;
	y *= 1;
	if (button == 1)
		wincon->mouse = 1;
	else if (button == 2)
		wincon->mouse = 2;
	if (button == 4)
		scale(wincon, 1.05);
	if (button == 5)
		scale(wincon, 0.95);
	return (1);
}

static int	move_dist(int p, int c)
{
	if (p > c)
		return (-6);
	if (p < c)
		return (6);
	return (0);
}

void		string_put(t_wincon **wincon)
{
	mlx_string_put((*wincon)->mlx, (*wincon)->win, 10, 10, 0x1095FF, STRING1);
	mlx_string_put((*wincon)->mlx, (*wincon)->win, 10, 30, 0x1095FF, STRING2);
	mlx_string_put((*wincon)->mlx, (*wincon)->win, 10, 50, 0x1095FF, STRING3);
	mlx_string_put((*wincon)->mlx, (*wincon)->win, 10, 70, 0x1095FF, STRING4);
	mlx_string_put((*wincon)->mlx, (*wincon)->win, 10, 90, 0x1095FF, STRING1);
}

int			mouse_move(int x, int y, t_wincon *wincon)
{
	static int	px;
	static int	py;
	int			xd;
	int			yd;

	yd = move_dist(py, y);
	xd = move_dist(px, x);
	if (wincon->mouse == 2)
	{
		if (px > (x + 3))
			rotate_y(wincon, 0.035);
		else if (px < (x - 3))
			rotate_y(wincon, -0.035);
		if (py > (y + 3))
			rotate_x(wincon, 0.035);
		else if (py < (y - 3))
			rotate_x(wincon, -0.035);
	}
	else if (wincon->mouse == 1)
		translate(wincon, xd, yd);
	px = x;
	py = y;
	return (1);
}
