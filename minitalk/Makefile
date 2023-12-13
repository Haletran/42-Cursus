# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 13:13:53 by codespace         #+#    #+#              #
#    Updated: 2023/12/13 16:59:15 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJS := ${SRCS:.c=.o}
NAME = minitalk


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) client.c -o client
	$(CC) $(CFLAGS) server.c -o server

client:
	$(CC) $(CFLAGS) client.c -o client

server: clean
	$(CC) $(CFLAGS) server.c -o server

clean:
	rm -rf $(OBJS)
	rm -rf server

fclean: clean
	rm -rf client
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
