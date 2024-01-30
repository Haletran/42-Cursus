# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:29:01 by codespace         #+#    #+#              #
#    Updated: 2024/01/30 16:48:20 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g

SRCS	= src/init.c \
		  src/parse.c \
		  src/utils.c \
		  src/instructions/sa.c \
		  src/instructions/sb.c \
		  push_swap.c 
OBJS	= ${SRCS:.c=.o}

LIBFT_DIR = libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

all: libft $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)

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