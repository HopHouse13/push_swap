/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:17 by pbret             #+#    #+#             */
/*   Updated: 2024/10/17 16:40:55 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// invers les deux premieres valeurs de la stack. Les noeuds ne bougent pas.
void	ft_swap(t_node **head)
{
	t_node	*tempo;
	int		tempo_data;

	if (*head == NULL && (*head)->next == NULL)
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
	t_node	*tmp;
	int		tmp_data;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	tmp_data = tmp->data;
	while (tmp->next != NULL)
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
	tmp->data = tmp_data;
}

void	ft_reverse_rotate(t_node **head)
{
	t_node		*tmp;
	long int	tmp_data;

	if (*head == NULL || (*head)->next == NULL)
			return ;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_data = tmp->data;
	while (tmp != *head)
	{
		tmp->data = tmp->prev->data;
		tmp = tmp->prev;
	}
	tmp->data = tmp_data;
}

void	ft_push(t_node **head_from, t_node **head_to)
{
	long int	data_tmp;
	int			replaced_tmp;
	t_node		*tmp;
	
	if (head_from == NULL)
		return ;
	tmp = *head_from;
	data_tmp = tmp->data;
	replaced_tmp = tmp->replaced;
	if (tmp->next)
		*head_from = tmp->next;
	else
		*head_from = NULL;
	free(tmp);
	ft_add_start(data_tmp,replaced_tmp, head_to);
}

