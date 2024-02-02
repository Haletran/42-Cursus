# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:29:01 by codespace         #+#    #+#              #
#    Updated: 2024/02/02 15:21:00 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Don't print any command
ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

NAME := push_swap
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g
FSANITIZE := -fsanitize=address

SRCS	= src/init.c \
		  src/parse.c \
		  src/utils.c \
		  src/instructions/ss.c \
		  src/instructions/pa.c \
		  src/instructions/rr.c \
		  src/instructions/rrr.c \
		  src/algo.c \
		  push_swap.c

OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBFT_DIR = libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	echo "-> Compiling push_swap"
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)
	echo "Successfully compilated :)"

gdb: fclean $(NAME)
	gdb --tui ./push_swap

valgrind: $(NAME)
	valgrind --leak-check=full ./push_swap 5 10 2 1

norm:
	@printf "\n$(PROJECT_NAME)[ Norm check : ]\n"
	@norminette $(SRCS) includes libft get_next_line ft_printf  | grep 'Error' ; true

clean:
	echo "-> Clean OBJ files"
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	echo "-> Clean the project"
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re norm
