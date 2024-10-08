/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:07:52 by pbret             #+#    #+#             */
/*   Updated: 2024/10/08 18:54:18 by pbret            ###   ########.fr       */
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
	*head = new;
}

void	ft_add_start(long int nbr, t_node **head)
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
	new->next = tempo;
	new->prev = NULL;
	tempo->prev = new;
	*head = new;
}

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
	tempo = *head;
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo->next = new;
	new->prev = tempo;
}

void	ft_free_list(t_node **head)
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

void	ft_print_list(t_node **head)
{
	t_node *tempo;

	tempo = *head;
	while (tempo)
	{
		ft_printf("[%d]\n", tempo->data);
		tempo = tempo->next;
	}
	printf("\n\n");
}
