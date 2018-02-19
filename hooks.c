/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:15:38 by aderby            #+#    #+#             */
/*   Updated: 2017/07/27 16:41:20 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

int		exit_program(void)
{
	exit(0);
}

int		key_release(int keycode, t_wincon *wincon)
{
	(void)wincon;
	if (keycode == 256)
		wincon->rot = 0;
	return (1);
}

int		key_press(int keycode, t_wincon *wincon)
{
	ft_putnbr(keycode);
	ft_putstr("\n");
	(void)wincon;
	if (keycode == 53)
		exit_program();
	if (keycode == 256)
		wincon->rot = 1;
	if (keycode == 0)
		translate(wincon, -5, 0);
	if (keycode == 1)
		translate(wincon, 0, 5);
	if (keycode == 2)
		translate(wincon, 5, 0);
	if (keycode == 13)
		translate(wincon, 0, -5);
	if (keycode == 3)
		scale(wincon, 1.05);
	if (keycode == 5)
		scale(wincon, 0.95);
	return (1);
}

void	initialize_hooks(t_wincon *wincon)
{
	mlx_hook(wincon->win, 2, 0, key_press, wincon);
	mlx_hook(wincon->win, 3, 0, key_release, wincon);
	mlx_hook(wincon->win, 4, 0, mouse_press, wincon);
	mlx_hook(wincon->win, 5, 0, mouse_release, wincon);
	mlx_hook(wincon->win, 6, 0, mouse_move, wincon);
	mlx_hook(wincon->win, 17, 0, exit_program, wincon);
}
