/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:52 by pbret             #+#    #+#             */
/*   Updated: 2024/09/27 14:30:28 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "push_swap.h"
# include "Printf/ft_printf.h"
# include "Libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	long int		data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node; 

//parsing
long int	*ft_parsing(char **tab);
char  	  **ft_management_av(int ac, char  **av);
int			ft_has_other_digits(char **tab);
int 		ft_has_maxs(long int *tab_int, char **tab_char);
int			ft_has_doublon(long int *tab_int, char **tab_char);

//tools
long int	ft_atoi_long(char *str);
long int	*ft_init_tab_int(long int *tab_int, char **tab_char);
int			ft_count_elem(char **tab_char);

//initalisation_stack
void		ft_init_stack(t_node **head, long int *tab_int, char **tab_char);
void		ft_init_head(int long nbr, t_node **head);
void		ft_add_back(int long nbr, t_node **head);
void		ft_free(t_node **head);



#endif