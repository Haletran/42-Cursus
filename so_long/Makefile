#  ________   _______   ___        ______    _____  ___    _______   
# /"       ) /    " \  |"  |      /    " \  (\"   \|"  \  /" _   "|  
#(:   \___/ // ____  \ ||  |     // ____  \ |.\\   \    |(: ( \___)  
# \___  \  /  /    ) :)|:  |    /  /    ) :)|: \.   \\  | \/ \       
#  __/  \\(: (____/ //  \  |___(: (____/ // |.  \    \. | //  \ ___  
# /" \   :)\        /  ( \_|:  \\        /  |    \    \ |(:   _(  _| 
#(_______/  \"_____/    \_______)\"_____/    \___|\____\) \_______)  

# Makefile vars                                                                  
NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
SRCS	:= test.c  
OBJS	:= ${SRCS:.c=.o}

#CODAM MLX VAR
LIBMLX	:= MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofastsda

#42 MLX VAR
42MLX := minilibx-linux
HEADERSC := -Imlx_linux -lXext -lX11
LIBSC := -I/usr/include -Imlx_linux -O3


all: $(NAME)

42mlx:
	@echo "Building $@"	
	@make -C $(42MLX)
	@mv $(42MLX)/libmlx_Linux.a ./mlx.a
	@echo "Target $@ completed"
	@echo "Compiling $(NAME)"
	@$(CC) $(OBJ) $(HEADERSC) $(NAME) mlx.a
	@echo "Compilation completed"

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
	@echo "\nYou need to have MLX installed to execute so_long :\n----------------------------------------"
	@echo -n "So do you want to install Codam MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/codam-coding-college/MLX42 && make libmlx; fi
	@echo -n "Then do you want to install 42 MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/42Paris/minilibx-linux && make 42mlx; fi
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
