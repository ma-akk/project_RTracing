# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtresa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 20:49:09 by gtresa            #+#    #+#              #
#    Updated: 2020/11/10 13:44:00 by gtresa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_memcmp.c ft_memchr.c ft_memmove.c ft_calloc.c ft_memccpy.c ft_memcpy.c ft_bzero.c ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strrchr.c ft_strchr.c ft_strnstr.c ft_strncmp.c ft_strlen.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_isspace.c ft_atof.c

SRCS_BONUS	= ft_lstnew.c	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= libft.a

FLAGS		= -Wall -Wextra -Werror

HEADER		= libft.h

.c.o:
		gcc ${FLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS} ${HEADER}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

bonus:	${NAME} ${OBJS_BONUS}
		ar rc ${NAME} ${OBJS_BONUS}
		ranlib ${NAME}

clean:
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean:	clean
		rm -rf ${NAME} ${bonus} 

re:		fclean all

.PHONY:	all clean fclean re 
