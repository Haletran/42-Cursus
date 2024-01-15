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
SRCS	:= test.c  \
		   init.c
OBJS	:= ${SRCS:.c=.o}
LIBS	:= MacroLibX/[libmlx.so/libmlx.dylib/libmlx.dll] -lSDL2


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

gt:
	@echo "\nYou need to have MLX installed to execute so_long :\n----------------------------------------"
	@echo -n "So do you want to install Codam MLX? [y/N] " && read ans && if [ $${ans:-'N'} = 'y' ]; then git clone https://github.com/seekrs/MacroLibX.git && make -C MacroLibX; fi
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
