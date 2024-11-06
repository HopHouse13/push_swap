# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:02:40 by pbret             #+#    #+#              #
#    Updated: 2024/11/06 17:41:57 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	SRCS			=	main.c\
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


				

#BONUS			=	

# OBJ_DIR_PUSH_SWAP 	= srcs/obj_push_swap    !!!!!!!!!!!!
OBJECTS_DIR			= OBJS
OBJS				= $(SRCS:.c=.o)
BONUS_OBJS			= $(BONUS:.c=.o)
CC					= cc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror -ggdb -c -I.
NAME				= push_swap

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(OBJS) -o $(NAME)

%.o: %.c
					$(CC) $(CFLAGS) -c $< -o $@ 

# bonus:
# 					$(CC) $(CFLAGS) $(BONUS)
# 					ar rcs $(NAME) $(BONUS_OBJS)

clean:
					$(RM) $(OBJS) $(BONUS_OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY: clean fclean re bonus