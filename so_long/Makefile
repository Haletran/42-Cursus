# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:04:36 by codespace         #+#    #+#              #
#    Updated: 2024/01/17 15:09:00 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile vars                                                                  
NAME    := so_long
CFLAGS  := -Wextra -Wall -Werror -g
SRCS    := so_long.c \
           src/utils.c \
           src/parse.c \
           src/checker.c
OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBS    := MacroLibX/libmlx.so -lSDL2

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C MacroLibX
	@make -C ../libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) ../libft/libft.a -o $(NAME)

gt:
	@echo -n "Do you want to install  MacroLibX ? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/seekrs/MacroLibX.git && make -C MacroLibX; fi

gdb: $(NAME)
	gdb --tui ./so_long

clean:
	@make -C MacroLibX clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C MacroLibX fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re folder gt



