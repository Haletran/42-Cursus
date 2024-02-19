# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:11:13 by bapasqui          #+#    #+#              #
#    Updated: 2024/02/19 13:02:20 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Don't print any command
ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

NAME := philo
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g
DEBUG_FLAGS := -Wextra -Wall -Werror -g -fsanitize=address

SRCS	= src/global_utils.c \
		  src/parse.c \
		  src/init.c \
		  philo.c

OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"

gdb: fclean $(OBJS)
	$(CC) $(DEBUG_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)
	echo "\033[41mDEGUG MODE : ON\033[0m"
	@echo -n "Do you want to launch GDB? [y/N] " && read ans && if [ "$${ans:-N}" = 'y' ]; then gdb --tui ./philo ; fi

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	echo "\033[41m$(NAME) cleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re