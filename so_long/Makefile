NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= test2.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx: 
	@echo "Building $@"	
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@echo "Target $@ completed"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

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