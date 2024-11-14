/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:07:52 by pbret             #+#    #+#             */
/*   Updated: 2024/11/14 10:26:29 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction d'initialisation de la liste chainee
// 
// -----------------------------------------------------------------------------
//
// boucle qui applique a chaque valeur de chaque sous-tableau, 
// -> ft_initialisation_linked_list
// en parametre le tableau principal, la valeur par defaut de l'index et
// le pointeur du head de la stack_a

void	ft_init_list(char **tab_brut, t_node **head)
{
	int	i;

	i = 0;
	while (tab_brut[i])
		ft_initialisation_linked_list(ft_atoi_long(tab_brut[i++]), -1, head);
}
// _____________________________________________________________________________
// 
// fonction d'initialisation du 1er noeud qui sera relie au head
// 
// -----------------------------------------------------------------------------
//
// 1] malloc de new de type t_node (strust dans ppush_swap.h)
//    + verification si le malloc a fonctionne sinon return.
// 2] ratachement de data, prev, next, index de new a leurs val d'initialisation
// 3] enfin la valeur du pointeur ou le pointeur head pointe devient
//    la meme valeurs du pointeur new. 

void	ft_init_head(long int nbr, int index, t_node **head)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
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

// _____________________________________________________________________________
// 
// fonction pour initialiser une nouveau noeud a la fin de la liste chainee
// 
// -----------------------------------------------------------------------------
//
// 1] if la head pointe vers NULL, cela veut dire qu'il n'y a aucun noeud dedans
//    -> appelle ft_init_head avec les mm parametres d'entree pour creer le 1er
//    noeud sur qui la head va pointer.
// 2] malloc de new de type t_node (strust dans ppush_swap.h)
//    + verification si le malloc a fonctionne sinon return.
// 3] la fonction ratache data, next, index de new a leurs valeurs respectifs.
// 4] tmp prend la valeur du pointeur head pour pourvoir le manipuler
//    la liste chainee tout en gardant la valeur du pointeur de la head.
// 5] boucle: tant qu'on est pas au dernier noeud -> on rentre et on avance.
// 6] la fonction fait en sorte que le next du dernier noeud (tmp) pointe vers
//    le nouveau noeud (new) avec ses valeurs deja initialiser.
// 7] et egalement que le previous (prev) du nouveau noeud (new) pointe vers
//    l'ancien dernier noeud (tmp).

void	ft_initialisation_linked_list(long int nbr, int index, t_node **head)
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
