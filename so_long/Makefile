# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:04:36 by codespace         #+#    #+#              #
#    Updated: 2024/01/16 11:13:39 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile vars                                                                  
NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
SRCS	:= so_long.c \
		   src/parsing.c
OBJS	:= ${SRCS:.c=.o}
LIBS	:= MacroLibX/libmlx.so -lSDL2


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

gt:
	@echo "\nYou need to have MLX installed to execute so_long :\n----------------------------------------"
	@echo -n "So do you want to install  MacroLibX ? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/seekrs/MacroLibX.git && make -C MacroLibX; fi
	@echo "----------------------------------------"

clean:
	@rm -rf $(OBJS) 
	@rm -rf $(LIBMLX)/build
	@rm -rf mlx.a

fclean: clean
	@rm -rf $(NAME)

folder:
	@rm -rf MLX42
	@rm -rf minilibx-linux

re: clean all

.PHONY: all, clean, fclean, re, libmlx
