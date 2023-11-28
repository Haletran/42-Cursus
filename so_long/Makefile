
OBJ = $(SRCS:.c=.o)
CC= cc
CFLAGS= -Wall -Wextra -Werror

SRCS= test.c 
NAME= so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Imlx_linux -lXext -lX11 -o $(NAME) libmlx_Linux.a

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re