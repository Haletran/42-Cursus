# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:29:01 by codespace         #+#    #+#              #
#    Updated: 2024/01/09 15:07:30 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g

SRCS	= src/parse.c
OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

gdb: fclean $(NAME)
	gdb --tui ./push_swap

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all