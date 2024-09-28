/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:07:52 by pbret             #+#    #+#             */
/*   Updated: 2024/09/27 14:42:21 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_node **head, long int *tab_int, char **tab_char)
{
	int		nb_elements;
	int		i;
	
	head = NULL;
	nb_elements = ft_count_elem(tab_char);
	/* printf("\nnb_elements : [%d]\n", nb_elements); */
	i = 0;
	ft_init_head(tab_int[i], head); //-initialisation head de la lst
	while (i < nb_elements)
	{
		ft_add_back(tab_int[i], head); //boule pour mettre chaque valeur dans un noeud
		i++;
	}
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
	new -> data = nbr;
	new -> prev = NULL;
	new -> next = NULL;
	*head = new;
}
void	ft_add_back(long int nbr, t_node **head)
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
	{
		ft_free(head);
		return ;
	}
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




/* check = head_a;
temp = head_a;
while (temp != NULL)
	check = temp->next;
	while (check != NULL)
		if (temp->data == check->data)
			return (ERROR_DUPLICATE);
		else
			check = check->next;
	temp = temp->next; */