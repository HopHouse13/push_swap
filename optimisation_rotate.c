/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:14:27 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/04 16:36:40 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 etapes:
// - on trouve le plus petit index de la liste chainee que l'on stock dans "index_max"
// - on reviens au debut pour comparer l'index de chaque node avec index_max pour trouver et renvoyer le node avec le plus grand index
t_node		*ft_find_node_index_max(t_node **head)
{
	long int	index_max;
	t_node		*tmp;
	
	if (*head == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	index_max = INT_MIN;
	while (tmp != NULL)
	{
		if (index_max < tmp->index)
		{
			index_max = tmp->index;
			tmp = *head;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (index_max != tmp->index)
		tmp = tmp->next;
	return (tmp);
}

void	ft_optimisation_rotate(t_node **head, int position_to_start, int flag)
{
	if (*head)
	{
		int size;
		
		size = position_to_start;
		if (size <= (ft_count_node(head) / 2))
			while (size)
			{
				if (flag == STACK_A)
					ft_ra(head);
				else
					ft_rb(head); 
				size--;
			}
		else
		{
			size = (ft_count_node(head) - position_to_start);
			while (size)
			{
				if (flag == STACK_A)
					ft_rra(head);
				else
					ft_rrb(head);
				size--;
			}
		}
	}
	return ;
}

void	ft_rotates_for_max_index_first(t_node **head, int flag)
{
	int	position_to_start;
	t_node	*tmp;
	t_node	*max;
	
	tmp = *head;
	position_to_start = 0;
	max = ft_find_node_index_max(head);
	while (tmp != max)
	{
		tmp = tmp->next;
		position_to_start++;
	}
	ft_optimisation_rotate(head, position_to_start, flag);
}