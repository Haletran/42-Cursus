# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 10:00:31 by tmatis            #+#    #+#              #
#    Updated: 2024/03/01 14:54:49 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosopher
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror
NOVISU 	= 0

FILE_EXTENSION	= .c

SRCS_PATH		= ./

INCLUDE_PATH	= includes

SRCS = src/utils/global_utils.c \
       src/parsing/parse.c \
       src/execution/init.c \
	   src/execution/exec.c \
	   src/end/ft_free.c \
	   src/utils/time.c \
	   philo.c

SHELL := /bin/zsh
OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

COM_STRING   = "compiling"


ifeq ($(detected_OS),Darwin) 
	RUN_CMD = script -q $@.log $1 > /dev/null; \
				RESULT=$$?
else ifeq ($(detected_OS),Linux)
	RUN_CMD = script -q -e -c "$(1)" $@.log > /dev/null; \
				RESULT=$$?; \
				sed -i '1d' $@.log; \
				sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log
else
	RUN_CMD = $(1) 2> $@.log; \
				RESULT=$$?
endif


define run_and_test
printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
$(RUN_CMD); \
if [ $$RESULT -ne 0 ]; then \
	printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)"; \
	rm -rf .files_changed; \
	if [ $(NOVISU) -eq 0 ]; then \
		echo; \
	fi; \
elif [ -s $@.log ]; then \
	printf "%b\n" "$(WARN_COLOR)[⚠]$(NO_COLOR)"; \
else  \
	printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

define save_files_changed
	FILE_CPP=`echo $(SRCS) $(MAIN)`; \
	FILE_OBJ=`find objs -type f -name '*.o' 2>/dev/null | sed 's/objs\///'`; \
	TO_COMPILE=`echo $$FILE_CPP | wc -w`; \
	for FILE in $$FILE_CPP; do \
		for OBJ in $$FILE_OBJ; do \
			if [ $${FILE%$(FILE_EXTENSION)} = $${OBJ%.o} ]; then \
				if [ $(SRCS_PATH)/$$FILE -ot objs/$$OBJ ]; then \
					FILE_DEP=`echo objs/$$OBJ | sed 's/\.o/\.d/'`; \
					HEAD_FILES=`< $$FILE_DEP xargs | grep -oh "\w*.h\w*"`; \
					RECOMPILE=0; \
					for HEAD in $$HEAD_FILES; do \
						if [ $(SRCS_PATH)/$$HEAD -nt objs/$$OBJ ]; then \
							RECOMPILE=1; \
							break; \
						fi; \
					done; \
					if [ $$RECOMPILE -eq 0 ]; then \
						((TO_COMPILE=$$TO_COMPILE-1)); \
					fi;\
				fi; \
			fi; \
		done; \
	done; \
	echo 0/$$TO_COMPILE > .files_changed
endef

define draw_bar
	FILE_TOTAL=`bash -c 'cat .files_changed | cut -d"/" -f2'`; \
	FILE_DONE=`bash -c 'cat .files_changed | cut -d"/" -f1'`; \
	if [ $$FILE_TOTAL -eq 0 ]; then \
		FILE_TOTAL=1; \
		FILE_DONE=1; \
	fi; \
	RES=`echo "scale=2; $$FILE_DONE/$$FILE_TOTAL*48" | bc`; \
	RES=`echo $${RES%%.*}`; \
	printf "$(OBJ_COLOR)[$(NO_COLOR)"; \
	i=0; \
	while [ $$i -lt 48 ]; do \
		if [ $$i -lt $$RES ]; then \
			printf "$(OK_COLOR)█$(NO_COLOR)"; \
		else \
			printf "$(COM_COLOR)▒$(NO_COLOR)"; \
		fi; \
		((i=$$i+1)); \
	done; \
	printf "$(OBJ_COLOR)]$(NO_COLOR)"; \
	printf " ($(COM_COLOR)$$FILE_DONE$(NO_COLOR)/$(COM_COLOR)$$FILE_TOTAL$(NO_COLOR))"; \
	printf " "; \
	((FILE_DONE=$$FILE_DONE+1)); \
	echo $$FILE_DONE/$$FILE_TOTAL > .files_changed;
endef

define display_progress_bar
	if [ $(NOVISU) -eq 0 ]; then \
		line=`bash -c 'oldstty=$$(stty -g); stty raw -echo min 0; tput u7 > /dev/tty; IFS=";" read -r -d R -a pos; stty $$oldstty; row=$$(($${pos[0]:2} - 1)); echo $$row'`; \
		max_line=`tput lines`; \
		((max_line=$$max_line-2));\
		new_line=0; \
		tput sc; \
		i=0; \
		while [ $$i -lt 60 ]; do \
			printf " "; \
			((i=$$i+1)); \
		done; \
		tput rc; \
		if [ $$line -gt $$max_line ]; then \
			new_line=1; \
			echo ; \
		else \
			((line=$$line+1));\
		fi; \
		tput sc; \
		tput cup $$line; \
		$(draw_bar) \
		if [ $$new_line -eq 1 ]; then \
			((line=$$line-1));\
			tput cup $$line; \
		else \
			tput rc; \
		fi; \
	fi
endef

################################################################################
#                                 Makefile rules                             #
################################################################################

all: setup $(NAME)
	@rm -rf .files_changed

$(NAME):	${OBJS}
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -o $@ ${OBJS})

setup:
	@$(call save_files_changed)

objs/%.o: 	$(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_PATH))

clean:
			@rm -rf objs objs_tests
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean:		clean
			@rm -rf $(NAME)
			@rm -rf .files_changed;
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re header

