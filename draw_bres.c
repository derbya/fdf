/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 01:31:23 by aderby            #+#    #+#             */
/*   Updated: 2017/07/08 02:21:37 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

static int	pick_color(t_wincon **wincon, int brd)
{
	int color;

	color = POINT->color;
	if (brd == 0)
		color = 0x000000;
	if (brd == 1)
		if (POINT->right->color != 0xFFFFFF)
			color = POINT->right->color;
	if (brd == 2)
		if (POINT->down->color != 0xFFFFFF)
			color = POINT->down->color;
	return (color);
}

void		draw_line(t_wincon **wincon, t_bres **b, int brd)
{
	int	color;

	color = pick_color(wincon, brd);
	while ((*b)->i++ < (*b)->dx)
	{
		mlx_pixel_put((*wincon)->mlx, (*wincon)->win,
				(*b)->x + POINT->tx, (*b)->y + POINT->ty, color);
		while ((*b)->d >= 0)
		{
			if ((*b)->swap)
				(*b)->x += (*b)->s1;
			else
				(*b)->y += (*b)->s2;
			(*b)->d -= 2 * (*b)->dx;
		}
		if ((*b)->swap)
			(*b)->y += (*b)->s2;
		else
			(*b)->x += (*b)->s1;
		(*b)->d += 2 * (*b)->dy;
	}
}

void		draw_lines_r(t_wincon **wincon, t_bres *bres)
{
	bres->dx = ft_abs(POINT->right->x - POINT->x);
	bres->dy = ft_abs(POINT->right->y - POINT->y);
	bres->s1 = ft_sign(POINT->right->x - POINT->x);
	bres->s2 = ft_sign(POINT->right->y - POINT->y);
	if (bres->dy > bres->dx)
	{
		bres->tmp = bres->dx;
		bres->dx = bres->dy;
		bres->dy = bres->tmp;
		bres->swap = 1;
	}
	bres->d = 2 * bres->dy - bres->dx;
	bres->x = POINT->x;
	bres->y = POINT->y;
	bres->i = 1;
	draw_line(wincon, &bres, 1);
}

void		draw_lines_d(t_wincon **wincon, t_bres *bres)
{
	bres->dx = ft_abs(POINT->down->x - POINT->x);
	bres->dy = ft_abs(POINT->down->y - POINT->y);
	bres->s1 = ft_sign(POINT->down->x - POINT->x);
	bres->s2 = ft_sign(POINT->down->y - POINT->y);
	if (bres->dy > bres->dx)
	{
		bres->tmp = bres->dx;
		bres->dx = bres->dy;
		bres->dy = bres->tmp;
		bres->swap = 1;
	}
	bres->d = 2 * bres->dy - bres->dx;
	bres->x = POINT->x;
	bres->y = POINT->y;
	bres->i = 1;
	draw_line(wincon, &bres, 2);
}
