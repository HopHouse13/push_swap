/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:17 by pbret             #+#    #+#             */
/*   Updated: 2024/10/08 16:39:03 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//invers les deux premieres valeurs de la stack. Les noeuds ne bougent pas.
void	ft_swap(t_node **head)
{
	t_node	*tempo;
	int		tempo_data;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return ;
	tempo = *head;
	tempo_data = tempo->data;
	tempo->data = tempo->next->data;
	tempo->next->data = tempo_data;
}

void	ft_rotate(t_node **head)
{
	t_node	*tempo;
	int		tempo_data_head;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return ;
	tempo = *head;
	tempo_data_head = tempo->data;
	while (tempo->next != NULL)
	{
		tempo->data = tempo->next->data;
		tempo = tempo->next;
	}
	tempo->data = tempo_data_head;
}

void	ft_reverse_rotate(t_node **head)
{
	t_node	*tempo;
	int		tempo_data_last;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return ;
	tempo = *head;
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo_data_last = tempo->data;
	while (tempo->prev != NULL)
	{
		tempo->data = tempo->prev->data;
		tempo = tempo->prev;
	}
	tempo->data = tempo_data_last;
}

void	ft_push(t_node **head_from, t_node **head_to)
{
	long int	data_tempo;
	t_node		*tempo;
	
	if (*head_from == NULL || *head_to == NULL)
		return ;
	tempo = *head_from;
	data_tempo = tempo->data;
	tempo->next->prev = NULL;
	*head_from = tempo->next;
	free(tempo);
	ft_add_start(data_tempo, head_to);
}

/* void	ft_push(t_node **head_from, t_node **head_to)
{
	t_node		*tempo;

	if (*head_from == NULL || head_from == NULL || *head_to == NULL)
		return ;
	tempo = *head_from;
	*head_from = tempo->next;
	tempo->prev = *head_to;
	if (*head_to)
		tempo->next = *head_to;
	else
		tempo->next = NULL;
	*head_to = tempo;
} */
// void	ft_push(t_node **head_from, t_node **head_to)
// {
// 	long int	tempo_data;
// 	t_node		*new;
// 	tempo_data = *(head_from)->data;
// 	head_from = *(head_from)->next;
// 	free(*head_from);
// 	new = ft_new_node(tempo_data);
// 	if (*head_to)
// 	{
// 		new->next = *head_from;
// 		new->prev = head_to;
// 		head_to = new;
// 	}
// 	else
// 	{
// 		new->prev = head_to;
// 		head_to = new;
// 	}
// }
