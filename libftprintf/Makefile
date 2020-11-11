SRCS		=	ft_printf.c								\
				find_specifier.c						\
				specifiers.c							\
				commun_functions.c						\
				print_char.c							\
				print_string/x_print_string.c			\
				print_string/n_print_string.c			\
				print_string/l_print_string.c			\
				print_address.c							\
				print_int/x_print_int.c					\
				print_int/hh_print_int.c				\
				print_int/h_print_int.c					\
				print_int/n_print_int.c					\
				print_int/l_print_int.c					\
				print_int/ll_print_int.c				\
				print_unsigned/x_print_unsigned.c		\
				print_unsigned/hh_print_unsigned.c		\
				print_unsigned/h_print_unsigned.c		\
				print_unsigned/n_print_unsigned.c		\
				print_unsigned/l_print_unsigned.c		\
				print_unsigned/ll_print_unsigned.c		\
				print_hexa_lower/x_print_hexa_lower.c	\
				print_hexa_lower/hh_print_hexa_lower.c	\
				print_hexa_lower/h_print_hexa_lower.c	\
				print_hexa_lower/n_print_hexa_lower.c	\
				print_hexa_lower/l_print_hexa_lower.c	\
				print_hexa_lower/ll_print_hexa_lower.c	\
				print_hexa_upper/x_print_hexa_upper.c	\
				print_hexa_upper/hh_print_hexa_upper.c	\
				print_hexa_upper/h_print_hexa_upper.c	\
				print_hexa_upper/n_print_hexa_upper.c	\
				print_hexa_upper/l_print_hexa_upper.c	\
				print_hexa_upper/ll_print_hexa_upper.c	\
				print_percent.c							\
				written_so_far/x_written_so_far.c		\
				written_so_far/written_so_far.c
OBJS		=	${SRCS:.c=.o}
CC			=	clang
FLAGS		=	-Wall -Werror -Wextra
NAME		=	libftprintf.a
RM			=	rm -f

.c.o :
			${CC} ${FLAGS} -Ilibft -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS}
			make bonus -C libft -f Makefile
			mv libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all :		${NAME}

bonus :		all

clean :
			make clean -C libft -f Makefile
			${RM} ${OBJS} ${OBJBONUS}

fclean :	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all fclean clean re
