# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 14:41:26 by bapasqui          #+#    #+#              #
#    Updated: 2023/11/15 14:40:08 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf.a

SRCS =	ft_printf.c \
	
all: $(NAME)

$(NAME): $(OBJS)
	make -C ../libft
	cp ../libft/libft.a ft_printf.a
	ar rc $(NAME) $(OBJS)

clean:
	make -C ../libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C ../libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re