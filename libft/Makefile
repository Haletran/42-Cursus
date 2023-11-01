# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 14:41:26 by bapasqui          #+#    #+#              #
#    Updated: 2023/11/01 11:36:10 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:%.c=%.o)
CFLAGS = -g -Wall -Werror -Wextra
CC = gcc
NAME = libft
SRC= $(wildcard *.c)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	ar -crs libft.a $(OBJ) 

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

so:
	$(CC) -fPIC $(CFLAGS) $(SRC)
	gcc -shared -o libft.so $(OBJ)

re: fclean all	

.PHONY: all clean fclean re
