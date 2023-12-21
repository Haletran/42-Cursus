# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 13:13:53 by codespace         #+#    #+#              #
#    Updated: 2023/12/21 14:19:19 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = Minitalk

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
CLIENT_TARGET = client

SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SERVER_TARGET = server

LIBFT_DIR = ../libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

all: $(LIBFT_TARGET) $(CLIENT_TARGET) $(SERVER_TARGET)

$(LIBFT_TARGET):
	@make -C $(LIBFT_DIR)
	
$(CLIENT_TARGET): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_TARGET)

$(SERVER_TARGET): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(CLIENT_TARGET) $(SERVER_TARGET)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
