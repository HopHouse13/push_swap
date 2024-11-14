/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:40:24 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/14 14:55:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction qui retourne le pointeur tmp qui pointe vers le noeud de
// la liste chainee transmis en parametre dont la valeur de la variable data est
// la plus petite des noeuds qui n'ont pas deja ete indexes.
// 
// -----------------------------------------------------------------------------
//
// 1] verification si head et le premier noeud de la liste chainee existent.
//    (etape non obligatoire)
// 2] la fonction fait pointer tmp sur le 1er noeud comme le pointeur head.
//    la fonction va manipuler tmp pour conserver le pointeur head.
// 3] val_min prend la plus grande val qu'elle puisse recevoir. (int max)
//    cela est pour forcer que le if dans la boucle soit tout le temps vraie et
//    que val_min prenne forcement une valeur dans la liste chainee.
// 4] bouble: tant que tmp (liste chainee) existe -> on rentre.
//    -> if val_min est de valeur superieur a data du noeud cactuel et que ce 
//       meme noeud a comme -1 a index.
//       -1 a index veut dire que ce noeud n'a pas encore ete indexe.
//    -> ces 2 condtions sont validees, val_min prend la valeur de la data
//       du noeud trouve.
//    -> tmp re-pointe de nouveau au debut de la liste chainee pour comparer
//       avec la totalitee des valeurs de la variable data de chaque noeud qui
//       n'ont pas encore ete indexes avec la nouvelle valeur de val_min. 
//    -> si val_min reste la plus petite, tmp passe au noeud suivant en prenant
//       la valeur de pointeur du noeud suivant.
//       lorsque nous avons parcouru la totalite de la liste chainee et que
//       val_min est restee la valeur la plus petite -> nous avons trouve
//       la valeur la plus petite de la liste chainee. BRAVO
//    -> la boucle s'arrete et tmp revient au 1er noeud.
//    -> la 2eme boucle: tant que val_min est différent de data au noeud actuel.
//       on parcourt l'ensemble de la liste chainee pour trouver le noeud qui a
//       la meme valeur que val_min.
//    -> lorsque il y a une egalite, la boucle s'arrete. tmp est au noeud avec
//       la valeur de val_min donc la valeur la plus petite.
//       la fonction renvoie le pointeur tmp qui est au noeud avec val plus pti.

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
