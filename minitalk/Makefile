# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 13:13:53 by codespace         #+#    #+#              #
#    Updated: 2023/12/14 20:39:26 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = minitalk

SRCS := client.c server.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft client server 
	@echo "Compiling $(NAME)..."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@echo "Compiling libft..."
	@make -C ../libft
	mv ../libft/libft.a .

client: client.o
	@echo "Compiling client..."
	@$(CC) $(CFLAGS) libft.a client.o -o client

server: server.o
	@echo "Compiling server..."
	@$(CC) $(CFLAGS) libft.a server.o -o server

clean:
	@make clean -C ../libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C ../libft
	rm -rf libft.a
	rm -rf $(NAME)
	rm -rf client server

re: fclean all

.PHONY: all clean fclean re client server
