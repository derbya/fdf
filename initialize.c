/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:43:27 by aderby            #+#    #+#             */
/*   Updated: 2017/07/08 02:16:03 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

void		make_connection(t_wincon **wincon, int len, int col)
{
	t_point	*tmp;
	t_point	*head;

	tmp = POINT;
	head = POINT;
	if (col > 1)
		while (len--)
			tmp = tmp->next;
	while (col--)
	{
		len = (*wincon)->col;
		while (len--)
		{
			head->right = (len > 0 ? head->next : NULL);
			head->down = (col > 0 ? tmp : NULL);
			tmp = (col > 0 ? tmp->next : NULL);
			head = head->next;
		}
	}
}

int			count_list(t_wincon **wincon)
{
	int		i;
	t_point	*tmp;

	i = 0;
	tmp = POINT;
	while (POINT->next)
	{
		i++;
		POINT = POINT->next;
	}
	POINT = tmp;
	return (i);
}

t_wincon	*init(int fd)
{
	t_wincon	*wincon;

	ft_putstr("allocating memory for the data\n");
	wincon = (t_wincon*)ft_memalloc(sizeof(t_wincon));
	ft_putstr("allocating memory for map\n");
	wincon->map = (t_map*)ft_memalloc(sizeof(t_map));
	ft_putstr("initializing connection\n");
	wincon->mlx = mlx_init();
	ft_putstr("creating window\n");
	wincon->win = mlx_new_window(wincon->mlx, WIN_L, WIN_H, "FdF Win");
	ft_putstr("parsing data\n");
	wincon->col = readfile(fd, &wincon, 0);
	ft_putstr("counting list\n");
	wincon->row = (count_list(&wincon) / wincon->col);
	ft_putstr("making connections between points\n");
	make_connection(&wincon, wincon->col, wincon->row);
	ft_putstr("calculating coordiates\n");
	initialize_pts(&wincon, wincon->row, wincon->col, 5);
	wincon->mouse = 0;
	wincon->rot = 0;
	return (wincon);
}
