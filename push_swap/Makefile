# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:29:01 by codespace         #+#    #+#              #
#    Updated: 2024/01/09 17:33:58 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g

SRCS	= src/init.c \
		  push_swap.c
OBJS	= ${SRCS:.c=.o}

LIBFT_DIR = ../libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

all: libft $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_TARGET) -o $(NAME) $(OBJS)

libft:
	@make -C $(LIBFT_DIR)

gdb: fclean $(NAME)
	gdb --tui ./push_swap

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re