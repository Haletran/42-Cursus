# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:04:47 by codespace         #+#    #+#              #
#    Updated: 2024/02/06 23:41:14 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftgnl.a
CC := cc
CFLAGS := -Wextra -Wall -Werror -g

SRCS	= get_next_line.c \
		  get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	echo "Compiling \033[1m\033[32mget_next_line\033[0m"
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re