/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:17 by pbret             #+#    #+#             */
/*   Updated: 2024/10/07 17:04:39 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//invers les deux premieres valeurs de la stack. Les noeuds ne bougent pas.
void	ft_swap(t_node **head)
{
	t_node	*tempo;
	int		tempo_data;
	
	if(*head == NULL || head == NULL || (*head)->next == NULL)
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

	if(*head == NULL || head == NULL || (*head)->next == NULL)
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

	if(*head == NULL || head == NULL || (*head)->next == NULL)
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
	t_node		*tempo_p;
	
	if(*head_from == NULL || head_from == NULL)
		return ;
	tempo_p = *head_from; 
	*head_from = tempo_p->next;
	tempo_p->prev = *head_to;
	if (*head_to)
		tempo_p->next = *head_to;
	else
		tempo_p->next = NULL;
	*head_to = tempo_p;
}
	/* tempo_data = head_from->data;
	tempo_p = head_from;
	head_from = head_from->next;
	free(tempo_p);
	head_from->prev = NULL;
	ft_add_front(tempo_data, head_to);
 */
/* 
	ATTENTION AUX INT ET LONG INT
	ATTENTION ft_add_front
	ATTENION  push_swap.h */
	
	

