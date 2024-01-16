# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:04:36 by codespace         #+#    #+#              #
#    Updated: 2024/01/16 15:53:11 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile vars                                                                  
NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -g
SRCS	:= so_long.c \
		   src/utils.c \
		   src/parse.c \
		   src/checker.c
OBJS	:= ${SRCS:.c=.o}
LIBS	:= MacroLibX/libmlx.so -lSDL2


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C MacroLibX
	@make -C ../libft
	@$(CC) $(OBJS) $(LIBS) ../libft/libft.a $(HEADERS) -o $(NAME)

gt:
	@echo "\nYou need to have MLX installed to execute so_long :\n----------------------------------------"
	@echo -n "So do you want to install  MacroLibX ? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/seekrs/MacroLibX.git && make -C MacroLibX; fi
	@echo "----------------------------------------"

gdb: $(NAME)
	gdb --tui ./so_long

clean:
	@make -C MacroLibX clean
	@rm -rf $(OBJS) 

fclean: clean
	@make -C MacroLibX fclean
	@rm -rf $(NAME)

folder:
	rm -rf MacroLibX

re: clean all

.PHONY: all, clean, fclean, re, folder, gt
