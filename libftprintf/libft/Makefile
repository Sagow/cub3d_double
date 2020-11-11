SRC_MEM		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c
SRC_IS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
SRC_STR		=	ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c
SRC_FD		=	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_OTHER	=	ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c ft_itoa.c
SRC_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRCS		=	${SRC_MEM} ${SRC_IS} ${SRC_STR} ${SRC_FD} ${SRC_OTHER}
OBJS		=	${SRCS:.c=.o}
OBJBONUS	=	${SRCS:.c=.o} ${SRC_BONUS:.c=.o}
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
NAME		=	libft.a
RM			=	rm -f

.c.o :
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS}
			${CC} ${FLAGS} -c ${SRCS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all :	${NAME}

bonus :	${OBJBONUS}
		${CC} ${FLAGS} -c ${SRCS} ${SRC_BONUS}
		ar rc ${NAME} ${OBJBONUS}
		ranlib ${NAME}

clean :
			${RM} ${OBJS} ${OBJBONUS}

fclean :	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all fclean clean re
