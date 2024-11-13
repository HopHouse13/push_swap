/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:40:24 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/13 18:10:46 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// _____________________________________________________________________________
// 
// fonction qui retourne le pointeur tmp qui pointe vers le noeud de
// la liste chainee transmis en parametre dont la valeur de data est 
// la plus petite et qui m'a pas deja ete indexe.
// 
// -----------------------------------------------------------------------------
//
// 1]
// En 2 etapes:
// - on trouve la plus petite valeur des node qui n'ont pas encore ete indexes (index enocre a -1 (non indexe)) 
// cette valeur sera stocker dans "val_min"
// - on repart au debut de la liste chainee et on compare chaque data avec la val_min pour
// trouver le node avec la valeur la plus petite. On retourne le pointeur de ce node

// index = -1 veut dire que le node n'a pas encore ete indexe, index = -1 a ete initialise lors de l'initialisation de la liste chainee
t_node	*ft_find_node_not_index_and_val_min(t_node **head)
{
	long int	val_min;
	t_node		*tmp;

	if (*head == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	val_min = INT_MAX;
	while (tmp != NULL)
	{
		if (val_min > tmp->data && tmp->index == -1)
		{
			val_min = tmp->data;
			tmp = *head;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (val_min != tmp->data)
		tmp = tmp->next;
	return (tmp);
}
// _____________________________________________________________________________
// 
// fonction qui attribut une valeur a la variable "index" en fonction de l'odre
// de grandeur de "data"
// 
// -----------------------------------------------------------------------------
//
// 1] verification si head pointe bien vers le 1er noeud de la liste chainee.
//    l'ordre des 2 premieres etapes peuvent etre inverser.
// 2] boucle: tant que i est inferieur au nombre de noeud dans la liste chainee.
//    -> on rentre.
//    -> tmp pointe vers le noeud de la liste chainee head dont la valeur
//    de data est la plus petite et qui m'a pas deja ete indexe.
//    -> l'index du noeud que tmp pointe prend la valeur i
//    -> i s'incremente en commancant par 0
//
// -----------------------------------------------------------------------------
//
// boucle pour imprimer les index avec leurs data:
//
// while (tmp != NULL)
// {
// printf("[%d]\t[%ld]\n", tmp->index, tmp->data);
// tmp = tmp->next;
// }

void	ft_initialisation_index(t_node **head)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (*head == NULL)
		return ;
	while (i < ft_count_node(head))
	{
		tmp = ft_find_node_not_index_and_val_min(head);
		tmp->index = i;
		i++;
	}
}
