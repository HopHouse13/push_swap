/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:07:52 by pbret             #+#    #+#             */
/*   Updated: 2024/10/17 17:31:14 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_list(char **tab_brut, t_node **head)
{
	int	i;

	i = 0;
	while (tab_brut[i])
			ft_add_end(ft_atoi_long(tab_brut[i++]), head);
}

void	ft_init_head(long int nbr, t_node **head)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		new = NULL;
		return ;
	}
	new->data = nbr;
	new->prev = NULL;
	new->next = NULL;
	new->replaced = 0;
	*head = new;
}
// ft pour les pushs
void	ft_add_start(long int nbr, int replaced, t_node **head)
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
	tempo = *head;
	new->data = nbr;
	new->replaced = replaced;
	new->next = tempo;
	new->prev = NULL;
	tempo->prev = new;
	*head = new;
}
// pour initialiser la stack_a au debut
void	ft_add_end(long int nbr, t_node **head)
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
	new->replaced = 0;
	tempo = *head;
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo->next = new;
	new->prev = tempo;
}

void	ft_free_lists(t_node **head_a, t_node **head_b)
{
	if (head_a != NULL)
	{
		while ((*head_a)->next != NULL)
		{
			(*head_a) = (*head_a)->next;
			free((*head_a)->prev);
		}
		free ((*head_a));
	}
	if (head_b != NULL)
	{
		while ((*head_b)->next != NULL)
		{
			(*head_b) = (*head_b)->next;
			free((*head_b)->prev);
		}
		free ((*head_b));
	}
}

