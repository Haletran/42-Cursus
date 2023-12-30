# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 17:02:24 by baptiste          #+#    #+#              #
#    Updated: 2023/12/30 17:54:43 by baptiste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile vars
NAME	:= fract-ol
CC      := gcc
CFLAGS	:= -Wextra -Wall -Werror
SRCS	:= src/main.c
OBJS	:= ${SRCS:.c=.o}

# CODAM MLX VAR
LIBMLX	:= MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast

all: $(NAME)

libmlx:
	@echo "Building $@"
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@echo "Target $@ completed"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

gt:
	@echo "\nYou need to have MLX installed to execute so_long :\n----------------------------------------"
	@echo -n "So do you want to install Codam MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/codam-coding-college/MLX42 && make libmlx; fi
	@echo -n "Then do you want to install 42 MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/42Paris/minilibx-linux && make libmlx; fi
	@echo "----------------------------------------"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -f mlx.a

fclean: clean
	@rm -f $(NAME)

folder:
	@rm -rf MLX42

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
