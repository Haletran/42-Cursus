NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= test2.c
OBJS	:= ${SRCS:.c=.o}

all: gt libmlx $(NAME)

libmlx:
	@echo "Building $@"	
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@echo "Target $@ completed"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

gt:
	@echo "You need to have MLX installed to execute so_long \n----------------------------------------"
	@echo -n "So do you want to install Codam MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/codam-coding-college/MLX42; fi
	@echo -n "Then do you want to install 42 MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/42Paris/minilibx-linux; fi

clean:
	@rm -rf $(OBJS) 
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx

process_with_progress_bar:
	@echo -n "Progress: "
	@for i in {1..10}; do \
		echo -n "."; \
		sleep 1; \
	done
	@echo " Done"