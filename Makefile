SRCS		=		src/ft_printf.c

OBJS		=		${SRCs:.c=.o}

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
				${CC} ${CFLAGS} ${OBJS} src/main.c -o ${NAME}

all:			$(NAME)


clean:

$(LIBFT):
				make -C libft

.PHONY: all clean fclean re $(LIBFT)
