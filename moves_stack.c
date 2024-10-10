/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:17 by pbret             #+#    #+#             */
/*   Updated: 2024/10/10 15:49:33 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// invers les deux premieres valeurs de la stack. Les noeuds ne bougent pas.
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
// tempo stock la data du 1er noeud puis avec la boucle, 
// chaque data prend la valeur de la celle d'apres.
// la boucle s'arrete a au dernier noeud, la data du dernier noeud 
// prend la valeur de tempo_data_head (initialement la premiere valeur).
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
	
	if (*head_from == NULL || head_from == NULL)
		return ;
	tempo = *head_from;
	data_tempo = tempo->data;
	if (tempo->next != NULL)
	{
		*head_from = tempo->next;
		tempo->next->prev = NULL;
		free(tempo);
	}
	else
		head_from = NULL;
	// free(tempo);   !!!! Si je free le noeud a supp, il y a un free en trop a la fin.
	ft_add_start(data_tempo, head_to);
}

