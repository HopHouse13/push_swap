# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:02:40 by pbret             #+#    #+#              #
#    Updated: 2024/11/16 13:29:51 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(SRCS_DIR)/main.c\
			$(SRCS_DIR)/parsing.c\
			$(SRCS_DIR)/sorting.c\
			$(SRCS_DIR)/initialisation_stack.c\
			$(SRCS_DIR)/index.c\
			$(SRCS_DIR)/tools.c\
			$(SRCS_DIR)/optimisation_rotate.c\
			$(SRCS_DIR)/split_argv.c\
			$(SRCS_DIR)/moves_stack.c\
			$(SRCS_DIR)/instructions/instructions.c\
			$(SRCS_DIR)/instructions/instructions_1.c\
			$(SRCS_DIR)/instructions/instructions_2.c\
			$(SRCS_DIR)/base_sort.c\
			$(SRCS_DIR)/big_sort.c\
			$(SRCS_DIR)/print_list.c\

SRCS_DIR	= srcs
OBJ_DIR 	= obj_push_swap
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -ggdb -c -I$(SRCS_DIR)
NAME		= push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)
					
$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)
					
re:			fclean all

.PHONY: clean fclean re bonus
