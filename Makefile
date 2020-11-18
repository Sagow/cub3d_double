SRCS		=	file_processing/file_processing.c	\
				file_processing/fp_colors.c			\
				file_processing/fp_map.c			\
				file_processing/fp_map2.c			\
				file_processing/fp_resolution.c		\
				file_processing/fp_sprite.c			\
				file_processing/fp_walls.c			\
				detect_wall.c						\
				detect_wall2.c						\
				draw_aerial.c						\
				drawing.c							\
				errors.c							\
				main.c								\
				mathematics.c						\
				move.c								\
				save.c								\
				sprite.c							\
				get_next_line/get_next_line.c		\
				get_next_line/get_next_line_utils.c
INCLUDES	=	-Iget_next_line						\
				-Ilibftprintf						\
				-Iincludes
OBJS		=	${SRCS:.c=.o}
CC			=	clang
FLAGS		=	-Wall -Werror -Wextra ${INCLUDES} -D BUFFER_SIZE=4096 -O3
LIBS		=	-lXext -lbsd -lmlx -lX11 -lm
NAME		=	cub3d
RM			=	rm -f

.c.o :
			${CC} -c $< -o ${<:.c=.o} ${FLAGS}

$(NAME) :	${OBJS}
			make -C libftprintf -f Makefile
			mv libftprintf/libftprintf.a .
			${CC} ${OBJS} ${FLAGS} ${LIBS} -Ilibftprintf -g -o ${NAME}

all :		${NAME}

bonus :		all

clean :
			make clean -C libftprintf -f Makefile
			${RM} ${OBJS}
			${RM} libftprintf.a

fclean :	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all fclean clean re