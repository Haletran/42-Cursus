# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:29:01 by codespace         #+#    #+#              #
#    Updated: 2024/01/15 12:40:07 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc 
CFLAGS := -Wextra -Wall -Werror -g
CHECKER_LINK= "https://cdn.intra.42.fr/document/document/23552/checker_linux"

SRCS	= src/init.c \
		  src/parse.c \
		  src/utils.c \
		  src/instructions/sa.c \
		  src/instructions/sb.c \
		  src/instructions/pa.c \
		  push_swap.c 
OBJS	= ${SRCS:.c=.o}

LIBFT_DIR = ../libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET)

libft:
	@make -C $(LIBFT_DIR)

gdb: fclean libft $(NAME)
	gdb --tui ./push_swap
	
testeur:
	@@if [ ! -f checker_linux ]; then wget $(CHECKER_LINK) -q --show-progress && chmod 777 checker_linux; fi
	@echo -n "Do you want to install Push_swap-testeur-max ? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://gitlab.com/hydrasho/push_swap-testeur-max.git ; fi
	@echo -n "Do you want to install Push_swap Visualizer ? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://gitlab.com/hydrasho/visualizer-push-swap.git ; fi

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf checker_linux
	rm -rf push_swap-testeur-max
	rm -rf visualizer-push-swap
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft