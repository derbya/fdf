/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:10:35 by aderby            #+#    #+#             */
/*   Updated: 2017/07/11 19:36:58 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fdf.h"

char	*fixed_line(char *str)
{
	char	alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	*head;
	int		color;
	int		i;
	int		j;

	head = str;
	color = 25000;
	while (*str)
	{
		if (*str == '.')
			*str = '0';
		else if (*str > 'A' && *str < 'Z')
			while (alpha[i])
			{
				if (*str == alpha[i])
				{
					color *= i * 4;
					i = 0;
					break ;
				}

				i++;
			}
		str++;
	}
	str = head;
	return (str);
}

int		main(int ac, char **av)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*fixedline;

	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDWR);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr_fd(line, fd2);
		line = fixed_line(line);
		free(line);
	}
	return (0);
}
