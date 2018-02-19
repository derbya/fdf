/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:10:29 by aderby            #+#    #+#             */
/*   Updated: 2017/07/10 16:17:08 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

void	put_pixels(t_wincon **wincon, t_bres *b)
{
	while (POINT->next)
	{
		mlx_pixel_put((*wincon)->mlx, (*wincon)->win,
				POINT->x + POINT->tx, POINT->y + POINT->ty, POINT->color);
		if (POINT->right)
		{
			draw_lines_r(wincon, b);
			ft_memset(b, 0, sizeof(t_bres));
			b->i = 1;
		}
		if (POINT->down)
		{
			draw_lines_d(wincon, b);
			ft_memset(b, 0, sizeof(t_bres));
			b->i = 1;
		}
		POINT = POINT->next;
	}
}

void	draw_image(t_wincon **wincon)
{
	t_point *tmp;
	t_bres	*b;

	tmp = POINT;
	b = (t_bres *)ft_memalloc(sizeof(t_bres));
	mlx_clear_window((*wincon)->mlx, (*wincon)->win);
	put_pixels(wincon, b);
	string_put(wincon);
	POINT = tmp;
	free(b);
}
