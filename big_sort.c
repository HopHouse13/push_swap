/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:28:55 by ubuntu            #+#    #+#             */
/*   Updated: 2024/10/30 19:06:00 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_sort(t_node **head_a, t_node **head_b)
{
	//ft_test(head_a, head_b);
	int	index_biggest;
	int	max_bits;
	int	i;
	int	nb_nodes_stack_a;

	index_biggest = ft_find_node_index_max(head_a)->index;
	max_bits = 0;
	while (index_biggest >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		nb_nodes_stack_a = ft_count_node(head_a);
		while (nb_nodes_stack_a != 0)
		{
			if ((((*head_a)->index >> i) & 1) == 1)
				ft_ra(head_a);
			else
				ft_pb(head_a, head_b);
			nb_nodes_stack_a--;
		}
		while (ft_count_node(head_b) != 0)
			ft_pa(head_b, head_a);
		i++;
	//ft_test(head_a, head_b);
	}
}
