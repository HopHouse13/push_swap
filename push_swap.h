/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:52 by pbret             #+#    #+#             */
/*   Updated: 2024/10/16 19:58:02 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "push_swap.h"
# include "Libft/libft.h"
# include <limits.h>

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef struct s_node
{
	int	long		data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

//parsing
int			ft_parsing(char **tab);
char		**ft_management_av(int ac, char **av);
int			ft_has_other_digits(char **tab);
int			ft_has_maxs(char **tab_char);
int			ft_has_doublon(char **tab_char);

//tools
long int	ft_atoi_long(char *str);
void		ft_free_tab(char **tab);
int			ft_count_node(t_node **head);
void		ft_print_list(t_node **head);
long int	ft_find_val_min(t_node **head);
void		ft_push_to_good_position(t_node **head_from, t_node **head_to);



//initalisation_stack
void		ft_init_list(char **tab_brut, t_node **head);
void		ft_init_head(long int nbr, t_node **head);
void		ft_add_end(long int nbr, t_node **head);
void		ft_free_lists(t_node **head_a, t_node **head_b);
void		ft_add_start(long int nbr, t_node **head);


//split_argv
void		ft_strncpy(char *str1, char *str2, int nb);
int			ft_count_words(char *str);
char		**ft_initialisation_tab(char **tab, char *str);
char		**ft_split_argv(char *str);

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

//sort_base
void		ft_sort_base(t_node **head_a, t_node **head_b);
void		ft_sort_2(t_node **head_a);
void		ft_sort_3(t_node **head_a);
void		ft_sort_4(t_node **head_a, t_node **head_b);
void		ft_sort_5(t_node **head_a, t_node **head_b);


void	ft_test(t_node **head_a, t_node **head_b);
#endif