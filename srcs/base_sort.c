/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:43:33 by pbret             #+#    #+#             */
/*   Updated: 2024/11/16 13:37:38 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction d'appelle de fonction de tri en fonction du nombre de noeuds.
// 
// -----------------------------------------------------------------------------
//
// fonction prend en charge le tri lorsque le valeur sont de 2 a 5.
//

void	ft_base_sort(t_node **head_a, t_node **head_b)
{
	if ((ft_count_node(head_a)) == 2)
		ft_sort_2(head_a);
	if ((ft_count_node(head_a)) == 3)
		ft_sort_3(head_a, head_b);
	if ((ft_count_node(head_a)) == 4)
		ft_sort_4(head_a, head_b);
	if ((ft_count_node(head_a)) == 5)
		ft_sort_5(head_a, head_b);
}
// _____________________________________________________________________________
// 
// fonction de tri de 2 noeuds.
// 
// -----------------------------------------------------------------------------
//
// if la valeur de index du 1er noeud est superieur a la valeur de index du 2eme
// noeud -> appelle de la fonction ft_sa. (swap entre les 2 premiers noeuds de 
// de la liste chainee)
//

void	ft_sort_2(t_node **head_a)
{
	if ((*head_a)->index > (*head_a)->next->index)
		ft_sa(head_a);
}
// _____________________________________________________________________________
// 
// fonction de tri de 3 noeuds.
// 
// -----------------------------------------------------------------------------
//
// tmp_a et tmp_b prennent respectivement les pointeurs de la stack_a et b pour
// conserver les pointeurs des 2 stack et pourvoir continuer a les manipuler.
// la fonction compare les 3 valeurs de index entre elles. chaque if compare un
// precis. les if sont controles a la suite car il est possible de devoir faire
// 2 mouvements pour obtenir le tri. exemple:
//
// a c b -> reverse rotate (b a c) puis swap (a b c)
//
// a > b et a > c			-> b c a -> rotate
// b > a et b > c			-> a c b -> reverse rotate
// b < a et b < c et a < c	-> b a c -> swap
// 
// le 2eme parametre est la stack_b car ft_sort_3 est appele dans ft_sort_4 et 5
// lors du dernier if du swap stack_a, pour optimiser les mouvements de 
// ft_sort_5, la fonction a besoin de savoir si il est necessaire de 
// swap stack_b en meme temps. ft_ss(1 coup, 2 mouvements)
// pour ca, elle a besoin de savoir la position de chaque noeuds de la stack_b.
// la fonction ft_sort_5 a besoin que le noeud avec le plus grand index soit en
// premiere position.
// voici les conditions pour ft_ss:
// -> qu'il y a au moins 2 noeuds dans la stack_b et que index du 1er noeud soit
// inferieur au 2eme noeud.

void	ft_sort_3(t_node **head_a, t_node **head_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = *head_a;
	tmp_b = *head_b;
	if (tmp_a->index > tmp_a->next->index
		&& tmp_a->index > tmp_a->next->next->index)
		ft_ra(head_a);
	if (tmp_a->next->index > tmp_a->index
		&& tmp_a->next->index > tmp_a->next->next->index)
		ft_rra(head_a);
	if (tmp_a->next->index < tmp_a->index
		&& tmp_a->next->index < tmp_a->next->next->index
		&& tmp_a->index < tmp_a->next->next->index)
	{
		if (tmp_b && tmp_b->next && tmp_b->index < tmp_b->next->index)
			ft_ss(head_a, head_b);
		else
			ft_sa(head_a);
	}
}
// _____________________________________________________________________________
// 
// fonction de tri de 4 noeuds.
// 
// -----------------------------------------------------------------------------
//
// les valeurs des lettres correspondent a l'ordre de placement dans l'alphabet.
// exemple : a < c ou c > b
// situation initial : 
//
//    ->	b a d c
//
// 1] appel de la ft_rotates_for_max_index_first pr avoir le noeud avec l'index
//    le plus grand en premiere position.
//
//    ->	d c b a
//
// 2] push du 1er noeud de la stack_a dans la stack_b.
//    (noeud avec le plus grand index)
//
//    ->  	c b a			d
//
// 3] appel de la ft_sort_3 pour trier les 3 noeuds de la stack_a.
//
//    ->  	a b c			d
//
// 4] appel de ft_pa pour push le noeud de la stack_a a la stack_b.
//
//    ->	d a b c
//
// 5] appel de  ft_ra pour rotate la stack_a.
//
//    ->	a b c d
//

void	ft_sort_4(t_node **head_a, t_node **head_b)
{
	ft_rotates_for_max_index_first(head_a, STACK_A);
	ft_pb(head_a, head_b);
	ft_sort_3(head_a, head_b);
	ft_pa(head_b, head_a);
	ft_ra(head_a);
}
// _____________________________________________________________________________
// 
// fonction de tri de 5 noeuds.
// 
// -----------------------------------------------------------------------------
//
// les valeurs des lettres correspondent a l'ordre de placement dans l'alphabet.
// exemple : a < c ou c > b
// situation initial : 
//
//    ->	b a e c d
//
// 1] appel de la ft_rotates_for_max_index_first pr avoir le noeud avec l'index
//    le plus grand en premiere position.
//
//    ->	e c d b a
//
// 2] push du 1er noeud de la stack_a dans la stack_b.
//    (noeud avec le plus grand index)
//
//    ->  	c d b a			e

// 3] 2eme appel de la ft_rotates_for_max_index_first dans la stack_a pour avoir
//    le noeud avec l'index le 2eme plus grand en premiere position.
//
//    ->  	d b a c			e
//
// 4] push du 1er noeud de la stack_a dans la stack_b.
//    (noeud avec le 2eme plus grand index)
//
//    ->  	b a c			d e
//
// 5] appel de la ft_sort_3 pour trier les 3 noeuds de la stack_a.
//
//    ->  	a b c			d e
//
// 6] appel de la ft_rotates_for_max_index_first dans la stack_b pour avoir
//    le noeud avec l'index le 2eme plus grand en premiere position.
//
//    ->  	a b c			e d
//
// 7] appel de ft_pa(x2) pour push les noeuds de la stack_a a la stack_b.
//
//    ->	d e a b c
//
// 8] appel de ft_ra(x2) pour rotate la stack_a pour obtenir une stack_a
//    commencant par le noeud avec la plus petite valeur.
//
//    ->	a b c d e
//	

void	ft_sort_5(t_node **head_a, t_node **head_b)
{
	ft_rotates_for_max_index_first(head_a, STACK_A);
	ft_pb(head_a, head_b);
	ft_rotates_for_max_index_first(head_a, STACK_A);
	ft_pb(head_a, head_b);
	ft_sort_3(head_a, head_b);
	ft_rotates_for_max_index_first(head_b, STACK_B);
	ft_pa(head_b, head_a);
	ft_pa(head_b, head_a);
	ft_ra(head_a);
	ft_ra(head_a);
}
