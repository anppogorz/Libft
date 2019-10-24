# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 08:26:03 by anpogorz          #+#    #+#              #
#    Updated: 2019/10/24 14:23:59 by anpogorz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c \
		  ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_memccpy.c \
		  ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c \
		  ./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strlcat.c \
		  ./ft_strlcpy.c ./ft_strlen.c ./ft_strncmp.c ./ft_strnstr.c \
		  ./ft_strrchr.c ./ft_tolower.c ./ft_toupper.c ./ft_itoa.c \
		  ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c \
		  ./ft_split.c ./ft_strjoin.c ./ft_strmapi.c ./ft_strtrim.c ./ft_substr.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I. -c

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
