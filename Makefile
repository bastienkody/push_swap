INC = ./inc/push_swap.h

SRC_DIR = ./src/

SRCS =	${SRC_DIR}main.c\
		${SRC_DIR}parsing.c\
		${SRC_DIR}struct_nb.c\
		${SRC_DIR}instructions.c\
		${SRC_DIR}instruction_s.c\
		${SRC_DIR}sorting_few.c\
		${SRC_DIR}radix_sort.c\
		${SRC_DIR}utils_sorting.c\
		${SRC_DIR}utils.c

OBJS =	${SRCS:.c=.o}

NAME =	push_swap

CC =	cc

CFLAGS =	-Wall -Wextra -Werror

LDFLAGS =	-L./libft -lft

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS} ${INC} 
			make -C libft/
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

clean:
		rm -rf ${OBJS}
		make clean -C libft/

fclean:		clean
		rm -rf ${NAME}
		make fclean -C libft/

re:		fclean all

.PHONY:	all clean re
