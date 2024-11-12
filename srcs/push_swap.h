/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:52 by pbret             #+#    #+#             */
/*   Updated: 2024/11/06 16:14:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "push_swap.h"

# define SUCCESS 0
# define FAILURE 1
# define STACK_A 2
# define STACK_B 3

typedef struct s_node
{
	int long		data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

//parsing
int			ft_parsing(char **tab);
char		**ft_management_av(int ac, char **av);
int			ft_has_other_digits(char **tab);
int			ft_has_maxs(char **tab_char);
int			ft_has_doublon(char **tab_char);

//split_argv
void		ft_strncpy(char *str1, char *str2, int nb);
int			ft_count_words(char *str);
char		**ft_initialisation_tab(char **tab, char *str);
char		**ft_split_argv(char *str);

//sorting
void		ft_sorting(char **tab_brut);

//tools
long int	ft_atoi_long(char *str);
void		ft_free_tab(char **tab);
int			ft_count_node(t_node **head);
int			ft_stack_a_is_sorted(t_node **head);
char		*ft_strdup(const char *s_src);

//initalisation_stack
void		ft_init_list(char **tab_brut, t_node **head);
void		ft_init_head(long int nbr, int index, t_node **head);
void		ft_first_initialisation(long int nbr, int index, t_node **head);
void		ft_free_lists(t_node **head_a, t_node **head_b);
void		ft_add_start(long int nbr, int index, t_node **head);

//index
t_node		*ft_find_node_not_index_and_val_min(t_node **head);
void		ft_initialisation_index(t_node **head);

//sort_base
void		ft_sort_base(t_node **head_a, t_node **head_b);
void		ft_sort_2(t_node **head_a);
void		ft_sort_3(t_node **head_a, t_node **head_b);
void		ft_sort_4(t_node **head_a, t_node **head_b);
void		ft_sort_5(t_node **head_a, t_node **head_b);

//big_sort
void		ft_big_sort(t_node **head_a, t_node **head_b);

//moves_stack
void		ft_swap(t_node **head);
void		ft_rotate(t_node **head);
void		ft_reverse_rotate(t_node **head);
void		ft_push(t_node **head_from, t_node **head_to);

//instructions
void		ft_sa(t_node **head);
void		ft_sb(t_node **head);
void		ft_ss(t_node **head_a, t_node **head_b);
void		ft_ra(t_node **head);
void		ft_rb(t_node **head);

//intructions_1
void		ft_rr(t_node **head_a, t_node **head_b);
void		ft_rra(t_node **head);
void		ft_rrb(t_node **head);
void		ft_rrr(t_node **head_a, t_node **head_b);
void		ft_pa(t_node **head_from, t_node **head_to);

//intructions_2
void		ft_pb(t_node **head_from, t_node **head_to);

//optimisation_rotate
t_node		*ft_find_node_index_max(t_node **head);
void		ft_rotate_with_position(t_node **head, int position, int flag);
void		ft_reverse_rotate_with_position(t_node **head, int position,
				int flag);
void		ft_optimisation_rotate(t_node **head, int position_to_index,
				int flag);
void		ft_rotates_for_max_index_first(t_node **head, int flag);

//control_functions
void		ft_print_list(t_node **head);
void		ft_print(t_node **head_a, t_node **head_b);
#endif