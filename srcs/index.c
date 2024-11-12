/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:40:24 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/05 18:20:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// En 2 etapes:
// - on trouve la plus petite valeur des node qui n'ont pas encore ete indexes (index enocre a -1 (non indexe)) 
// cette valeur sera stocker dans "val_min"
// - on repart au debut de la liste chainee et on compare chaque data avec la val_min pour
// trouver le node avec la valeur la plus petite. On retourne le pointeur de ce node

// index = -1 veut dire que le node n'a pas encore ete indexe, index = -1 a ete initialise lors de l'initialisation de la liste chainee
t_node	*ft_find_node_not_index_and_val_min(t_node **head)
{
	long int	val_min;
	t_node		*tmp;

	if (*head == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	val_min = INT_MAX;
	while (tmp != NULL)
	{
		if (val_min > tmp->data && tmp->index == -1)
		{
			val_min = tmp->data;
			tmp = *head;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (val_min != tmp->data)
		tmp = tmp->next;
	return (tmp);
}

	// while (tmp != NULL)
	// {
	// 	printf("[%d]\t[%ld]\n", tmp->index, tmp->data);
	// 	tmp = tmp->next;
	// }

void	ft_initialisation_index(t_node **head)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *head;
	if (*head == NULL)
		return ;
	while (i < ft_count_node(head))
	{
		tmp = ft_find_node_not_index_and_val_min(head);
		tmp->index = i;
		i++;
	}
	tmp = *head;
}
