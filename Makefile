# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbret <pbret@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:02:40 by pbret             #+#    #+#              #
#    Updated: 2024/10/07 16:22:24 by pbret            ###   ########.fr        #
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


				

#BONUS			=	


OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -ggdb -c -I.

LIBFT_DIR		= ./Libft
PRINTF_DIR		= ./Printf

LIBFT			= $(LIBFT_DIR)/libft.a
PRINTF			= $(PRINTF_DIR)/libftprintf.a

LFLAGS			= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT_DIR)
				@make -C $(PRINTF_DIR)
				$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(LFLAGS) -o $(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@ 

# bonus:
# 				$(CC) $(CFLAGS) $(BONUS)
# 				ar rcs $(NAME) $(BONUS_OBJS)

clean:
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(PRINTF_DIR)
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(PRINTF_DIR)
				$(RM) $(NAME)

re:				fclean all

.PHONY: clean fclean re bonus