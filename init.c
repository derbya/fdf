/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:04:52 by aderby            #+#    #+#             */
/*   Updated: 2017/07/08 12:33:02 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

void	pointnew(t_point **point)
{
	(*point) = (t_point*)malloc(sizeof(t_point));
	(*point)->x = 0;
	(*point)->y = 0;
	(*point)->z = 0;
	(*point)->color = 0;
	(*point)->tx = WIN_L / 2;
	(*point)->ty = WIN_H / 2;
	(*point)->next = NULL;
	(*point)->right = NULL;
	(*point)->down = NULL;
}

int		get_color(char *color)
{
	unsigned long	icolor;
	char			*base16;
	int				i;
	int				exp;

	base16 = "0123456789ABCDEF";
	color = color + 2;
	icolor = 0;
	exp = 16777216;
	while (*color)
	{
		i = 0;
		while (*color != base16[i])
			i++;
		icolor = icolor + ((i) * exp);
		color++;
		exp /= 16;
	}
	return (icolor);
}

void	initialize_pts(t_wincon **wincon, int row, int col, int r)
{
	double	xd;
	double	yd;
	double	xi;
	double	yi;
	t_point	*tmp;

	tmp = (*wincon)->map->point;
	xd = (((WIN_L / r) * (r - 1)) - ((WIN_L / r)));
	yd = (((WIN_H / r) * (r - 1)) - ((WIN_H / r)));
	yi = 0;
	while (row--)
	{
		xi = 0;
		col = (*wincon)->col;
		while (col--)
		{
			POINT->x = ((*wincon)->col == 1 ? 0 : ((xd / 2) * -1) + xi);
			POINT->y = ((*wincon)->row == 1 ? 0 : ((yd / 2) * -1) + yi);
			(*wincon)->map->point = (*wincon)->map->point->next;
			xi += (xd / ((*wincon)->col - 1));
		}
		yi += (yd / ((*wincon)->row - 1));
	}
	(*wincon)->map->point = tmp;
}

void	fill_points(t_point **point, char *parsed)
{
	char	**p2;

	p2 = ft_strsplit(parsed, ',');
	(*point)->z = (((int)ft_arrlen(ft_strsplit(parsed, ',')) > 1)
			? ft_atoi(p2[0]) * 3 : ft_atoi(parsed)) * 3;
	(*point)->color = (((int)ft_arrlen(ft_strsplit(parsed, ',')) > 1)
			? get_color(p2[1]) : 16777215);
}

int		readfile(int fd, t_wincon **wincon, int i)
{
	char	*line;
	char	**parsed;
	t_point	*tmp;

	pointnew(&POINT);
	tmp = POINT;
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		parsed = ft_strsplit(line, ' ');
		while (*parsed)
		{
			fill_points(&POINT, *parsed);
			parsed++;
			i++;
			pointnew(&POINT->next);
			POINT = POINT->next;
		}
	}
	POINT = tmp;
	return (i);
}
