/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:17 by pbret             #+#    #+#             */
/*   Updated: 2024/10/23 16:58:17 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// invers les deux premieres valeurs de la stack. Les noeuds ne bougent pas.
void	ft_swap(t_node **head)
{
	t_node	*tmp;
	int		tmp_data;
	int		tmp_index;

	if (*head == NULL && (*head)->next == NULL)
		return ;
	tmp = *head;
	tmp_data = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = tmp_data;
	tmp_index = tmp->index;
	tmp->index = tmp->next->index;
	tmp->next->index = tmp_index;
}
// tmp stock la data du 1er noeud puis avec la boucle, 
// chaque data prend la valeur de la celle d'apres.
// la boucle s'arrete a au dernier noeud, la data du dernier noeud 
// prend la valeur de tmp_data_head (initialement la premiere valeur).
void	ft_rotate(t_node **head)
{
	t_node	*tmp;
	int		tmp_data;
	int		tmp_index;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	tmp_data = tmp->data;
	tmp_index = tmp->index;
	while (tmp->next != NULL)
	{
		tmp->data = tmp->next->data;
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	tmp->data = tmp_data;
	tmp->index = tmp_index;
}

void	ft_reverse_rotate(t_node **head)
{
	t_node		*tmp;
	long int	tmp_data;
	int		tmp_index;

	if (*head == NULL || (*head)->next == NULL)
			return ;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_data = tmp->data;
	tmp_index = tmp->index;
	while (tmp != *head)
	{
		tmp->data = tmp->prev->data;
		tmp->index = tmp->prev->index;
		tmp = tmp->prev;
	}
	tmp->data = tmp_data;
	tmp->index = tmp_index;
}

void	ft_push(t_node **head_from, t_node **head_to)
{
	long int	data_tmp;
	int			index_tmp;
	t_node		*tmp;
	
	if (head_from == NULL)
		return ;
	tmp = *head_from;
	data_tmp = tmp->data;
	index_tmp = tmp->index;
	if (tmp->next)
		*head_from = tmp->next;
	else
		*head_from = NULL;
	free(tmp);
	ft_add_start(data_tmp, index_tmp, head_to);
}
