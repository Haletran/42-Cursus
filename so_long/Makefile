# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:04:36 by codespace         #+#    #+#              #
#    Updated: 2024/01/20 16:53:52 by baptiste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile vars                                                                  
NAME    := so_long
CFLAGS  := -Wextra -Wall -Werror -g
SRCS    := so_long.c \
           src/utils.c \
           src/parse.c \
		   src/validity.c \
		   src/render.c \
           src/checker.c
OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBS    := MacroLibX/libmlx.so -lSDL2

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@if [ ! -d "MacroLibX" ]; then git clone https://github.com/seekrs/MacroLibX.git && make -C MacroLibX; fi
	@make -C ../libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) ../libft/libft.a -o $(NAME)

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



