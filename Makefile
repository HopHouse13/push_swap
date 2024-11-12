# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:02:40 by pbret             #+#    #+#              #
#    Updated: 2024/11/12 11:47:52 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c\
			parsing.c\
			sorting.c\
			initialisation_stack.c\
			index.c\
			tools.c\
			optimisation_rotate.c\
			split_argv.c\
			moves_stack.c\
			instructions.c\
			instructions_1.c\
			instructions_2.c\
			sort_base.c\
			big_sort.c\

OBJ_DIR_PUSH_SWAP 	= srcs/obj_push_swap
SRCS_DIR			= srcs/
OBJS				= $(SRCS:%.c=$(OBJ_DIR_PUSH_SWAP)/%.o)
CC					= gcc
RM					= rm -rf
CFLAGS				= -Wall -Wextra -Werror -ggdb -c -I.
NAME				= push_swap

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(OBJS) -o $(NAME)
					
$(OBJ_DIR_PUSH_SWAP)/%.o : %.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					$(RM) $(OBJS) $(OBJ_DIR_PUSH_SWAP) $(SRCS_DIR)

fclean:				clean
					$(RM) $(NAME)
					
re:					fclean all

.PHONY: clean fclean re bonus