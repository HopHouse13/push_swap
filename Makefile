# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fHea <fHea@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:02:40 by pbret             #+#    #+#              #
#    Updated: 2024/10/15 11:59:25 by fHea             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c\
					parsing.c\
					initalisation_stack.c\
					tools.c\
					split_argv.c\
					moves_stack.c\
					instructions.c\
					instructions_1.c\
					instructions_2.c\
					sort_base.c\


				

#BONUS			=	


OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -ggdb -c -I.
LIBFT_DIR		= ./Libft
LIBFT			= $(LIBFT_DIR)/libft.a
LFLAGS			= -L$(LIBFT_DIR) -lft

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT_DIR)
				$(CC) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@ 

# bonus:
# 				$(CC) $(CFLAGS) $(BONUS)
# 				ar rcs $(NAME) $(BONUS_OBJS)

clean:
				@make clean -C $(LIBFT_DIR)
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				$(RM) $(NAME)

re:				fclean all

.PHONY: clean fclean re bonus