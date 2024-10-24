/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:07:52 by pbret             #+#    #+#             */
/*   Updated: 2024/10/23 17:21:14 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_list(char **tab_brut, t_node **head)
{
	int	i;

	i = 0;
	while (tab_brut[i])
			ft_first_initialisation(ft_atoi_long(tab_brut[i++]), -1, head);
}

void	ft_init_head(long int nbr, int index, t_node **head)
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
	new->index = index;
	*head = new;
}
// ft pour les pushs
void	ft_add_start(long int nbr, int index, t_node **head)
{
	t_node	*new;
	t_node	*tmp;

	if (*head == NULL)
	{
		ft_init_head(nbr, index, head);
		return ;
	}
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	tmp = *head;
	new->data = nbr;
	new->index = index;
	new->next = tmp;
	new->prev = NULL;
	tmp->prev = new;
	*head = new;
}
// pour initialiser la stack_a au debut
void	ft_first_initialisation(long int nbr, int index, t_node **head)
{
	t_node	*new;
	t_node	*tmp;

	if (*head == NULL)
	{
		ft_init_head(nbr, index, head);
		return ;
	}
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = nbr;
	new->next = NULL;
	new->index = index;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_free_lists(t_node **head_a, t_node **head_b)
{
	if (*head_a != NULL)
	{
		while ((*head_a)->next != NULL)
		{
			(*head_a) = (*head_a)->next;
			free((*head_a)->prev);
		}
		free ((*head_a));
	}
	if (*head_b != NULL)
	{
		while ((*head_b)->next != NULL)
		{
			(*head_b) = (*head_b)->next;
			free((*head_b)->prev);
		}
		free ((*head_b));
	}
}

