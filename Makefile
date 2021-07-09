SRCS		=		src/ft_printf.c src/ft_strfuncs.c src/ft_uItoa.c

OBJS		=		${SRCS:.c=.o}

HEADER		=		includes/myprintf.h

NAME		=		libftprintf.a

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra

AR			=		ar

RM			=		rm -f

LIBFT		=		libft

ARFLAGS		=		rc

%o: %c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${LIBFT} ${OBJS}
				make -C libft
				ar rc libft/libft.a ${OBJS}
				cp libft/libft.a ${NAME}
				gcc src/main.c ${NAME}

all:			$(NAME)


clean:
		make clean -C libft
		${RM} ${OBJS}

fclean: clean
		make fclean -C libft
		${RM} ${OBJS} ${NAME}

re:		fclean	all

.PHONY: all clean fclean re
