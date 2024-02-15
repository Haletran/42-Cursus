# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:29:01 by codespace         #+#    #+#              #
#    Updated: 2024/02/15 18:40:47 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Don't print any command
ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

NAME := push_swap
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g
DEBUG_FLAGS := -Wextra -Wall -Werror -g -fsanitize=address
CHECKER_LINK= "https://cdn.intra.42.fr/document/document/23552/checker_linux"

SRCS	= src/init.c \
		  src/parse.c \
		  src/utils.c \
		  src/instructions/ss.c \
		  src/instructions/pa.c \
		  src/instructions/rr.c \
		  src/instructions/rrr.c \
		  src/algo.c \
		  src/ft_free.c \
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
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"

checker:
	@if [ ! -f checker_linux ]; then wget $(CHECKER_LINK) -q --show-progress; fi
	@if [ $$? -eq 0 ]; then echo "\033[92;1;5m[checker_linux]\033[0m Downloaded Successfully" && chmod 777 checker_linux; fi

gdb: fclean $(OBJS)
	@make -C libft
	$(CC) $(DEBUG_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)
	echo "\033[41mDEGUG MODE : ON\033[0m"
	@echo -n "Do you want to launch GDB? [y/N] " && read ans && if [ "$${ans:-N}" = 'y' ]; then gdb --tui ./push_swap ; fi

valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./push_swap $1

norm:
	@printf "\n$(PROJECT_NAME)[ Norm check : ]\n"
	@norminette $(SRCS) includes libft get_next_line ft_printf

tester: checker
	@git clone https://gitlab.com/hydrasho/push_swap-testeur-max.git

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf checker_linux
	make -C $(LIBFT_DIR) fclean
	echo "\033[41m$(NAME) cleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re norm checker