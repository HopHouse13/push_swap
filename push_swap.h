/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:52 by pbret             #+#    #+#             */
/*   Updated: 2024/09/28 18:19:29 by pbret            ###   ########.fr       */
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
int			ft_parsing(char **tab);
char		**ft_management_av(int ac, char **av);
int			ft_has_other_digits(char **tab);
int			ft_has_maxs(char **tab_char);
int			ft_has_doublon(char **tab_char);

//tools
long int	ft_atoi_long(char *str);

//initalisation_stack
void		ft_init_head(int nbr, t_node **head);
void		ft_add_back(int nbr, t_node **head);
void		ft_free(t_node **head);
#endif