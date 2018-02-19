/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 05:26:42 by jrameau           #+#    #+#             */
/*   Updated: 2017/07/02 13:29:21 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"
#include <fcntl.h>

typedef	struct	s_test
{
	t_list		*list;
}				t_test;

typedef	struct	s_test2
{
	t_test		*test;
}				t_test2;

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_test2	*test2;
	t_list	*head;

	test2 = ft_memalloc(sizeof(t_test2));
	test2->test = ft_memalloc(sizeof(t_test));
	test2->test->list = ft_lstnew(NULL, 0);
	head = test2->test->list;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		test2->test->list->content = ft_strdup(line);
		test2->test->list->content_size = ft_strlen(line);
		free(line);
		test2->test->list->next = ft_lstnew(NULL, 0);
		test2->test->list = test2->test->list->next;
	}
	if (argc == 2)
		close(fd);
	while (head)
	{
		ft_putstr(head->content);
		ft_putstr("\n");
		head = head->next;
	}
}
