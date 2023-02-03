# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:51:37 by vchulkai          #+#    #+#              #
#    Updated: 2023/02/02 22:19:49 by vchulkai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_con1.c ft_printf_con2.c ft_util1.c ft_util2.c ft_util3.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

%o: %c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
