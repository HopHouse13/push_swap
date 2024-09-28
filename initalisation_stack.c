/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:07:52 by pbret             #+#    #+#             */
/*   Updated: 2024/09/28 18:13:18 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_head(int nbr, t_node **head)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		new = NULL;
		return ;
	}
	new -> data = nbr;
	new -> prev = NULL;
	new -> next = NULL;
	*head = new;
}

void	ft_add_back(int nbr, t_node **head)
{
	t_node	*new;
	t_node	*tempo;
	
	if (*head == NULL)
	{
		ft_init_head(nbr, head);
		return ;
	}
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = nbr;
	new->next = NULL;
	tempo = *head;
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo->next = new;
	new->prev = tempo;
}

void	ft_free(t_node **head)
{
	t_node	*tempo;
	
	tempo = *head;
	while (tempo->next != NULL)
	{
		tempo = tempo->next;
		free(tempo->prev);
	}
	free (tempo);
}
