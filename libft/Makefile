# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftassada <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 20:09:55 by ftassada          #+#    #+#              #
#    Updated: 2021/06/14 15:56:48 by ftassada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
				ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		=	${SRCS:.c=.o}

BONUSSRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				ft_lstmap.c

BONUSOBJS	=	${BONUSSRCS:.c=.o}

CFLAGS		=	-Wall -Werror -Wextra

HEADER		=	libft.h

NAME		=	libft.a

AR			=	ar rc

%o:				%c ${HEADER}
				gcc ${CFLAGS} -c $<

$(NAME):		${OBJS}
				${AR} ${NAME} ${OBJS}
				ranlib	${NAME}

bonus:			${NAME} ${BONUSOBJS}
				${AR} ${NAME} ${BONUSOBJS}
				ranlib	${NAME}
			
all:			${NAME}

clean:
				rm -rf ${OBJS}

fclean:			clean
				rm -rf ${NAME}

re:				fclean	all

.PHONY:			all clean fclean re
