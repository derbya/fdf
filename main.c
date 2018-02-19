/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 10:32:58 by aderby            #+#    #+#             */
/*   Updated: 2017/07/10 16:00:18 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

int		err_handling(char *error)
{
	ft_putendl(error);
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	t_wincon	*wincon;

	if (ac != 2)
		return (err_handling("error: must have 2 arguments."));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (err_handling("error: invalid file."));
	if ((wincon = init(fd)) == NULL)
		return (err_handling("error: failed to make connection."));
	draw_image(&wincon);
	initialize_hooks(wincon);
	mlx_loop(wincon->mlx);
	return (0);
}
