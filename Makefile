# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 14:20:14 by aderby            #+#    #+#              #
#    Updated: 2017/07/08 14:51:37 by aderby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

C_FIL = draw.c draw_bres.c hooks.c init.c initialize.c input.c main.c \
		rotate.c tands.c

O_FIL = *.o
O_LOC = obj

GCC_FLAGS = gcc -Wall -Wextra -Werror -L miniLibx -lmlx -framework OpenGL \
			-framework AppKit

LIB = libft/libft.a

all: $(NAME)

$(NAME):
		cd libft && make re
		cd miniLibx && make re
			$(GCC_FLAGS) $(LIB) $(C_SRC) $(C_FIL) -o $(NAME)

clean:
		cd libft && make clean

fclean: clean
		cd libft && make fclean
			/bin/rm -f $(NAME)

re: fclean all
