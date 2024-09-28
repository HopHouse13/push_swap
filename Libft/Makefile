# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbret <pbret@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:53:10 by pbret             #+#    #+#              #
#    Updated: 2024/09/18 16:16:24 by pbret            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \
				ft_isprint.c ft_isascii.c ft_memcpy.c ft_memset.c ft_strlen.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_toupper.c \
				ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_is_plus_moins.c\

BONUS			=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -c -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):
				$(CC) $(CFLAGS) $(SRCS) 
				ar rcs $(NAME) $(OBJS)

bonus:
				$(CC) $(CFLAGS) $(BONUS)
				ar rcs $(NAME) $(BONUS_OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: clean fclean re bonus