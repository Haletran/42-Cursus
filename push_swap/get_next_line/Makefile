# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:04:47 by codespace         #+#    #+#              #
#    Updated: 2024/01/11 19:15:34 by codespace        ###   ########.fr        #
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
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re