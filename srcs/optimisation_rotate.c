/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:14:27 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/18 00:06:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction qui revoie le noeud avec l'index le plus grand de la stack passee
// en parametre.
// 
// -----------------------------------------------------------------------------
//
// 1] check si head et le 1er noeud de head existe.
// 2] tmp prend la meme valeur que *head (1er noeud)
// 3] index_max prend INT_MIN pour que le 1er if soit forcement vrai.
// 4] boucle: tant que tmp n'est pas varrive a la fin de la liste chainee-> ok
//    -> if index_max est inferieur a l'index du noeud actuel -> on rentre.
//    -> index_max prend la valeur de l'index du noeud actuel.
//    -> tmp reprend la valeur du pointeur du 1er noeud.
//    cette derniere ligne serre a comparer l'ensemble des index avec index_max.
//    -> si l'index_max est superieur a l'index du noeud actuel -> on passe au
//    noeud suivant. (tmp = tmp->next)
//    etc
// 5] une fois que la fonction a comparer l'ensemble des index de
//    la liste chainee, nous avons trouve le noeud avec l'index le plus grand
//    et tmp revient au debut.
// 6] boucle: tant que l'index du noeud actuel n'est pas egale a index_max -> ok
//    -> on avance au noeud suivant jusqu'a que l'on trouve le noeud avec
//       l'index le plus grand.
// 7] une fois trouve, la fonction le renvoie a travers tmp qui a pris la valeur
//    du pointeur du noeud concerne.

t_node	*ft_find_node_index_max(t_node **head)
{
	long int	index_max;
	t_node		*tmp;

	if (*head == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	index_max = INT_MIN;
	while (tmp != NULL)
	{
		if (index_max < tmp->index)
		{
			index_max = tmp->index;
			tmp = *head;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (index_max != tmp->index)
		tmp = tmp->next;
	return (tmp);
}

// _____________________________________________________________________________
// 
// fonction simple pr appeler la bonne fonction de rotate au bon nombre de fois.
// 
// -----------------------------------------------------------------------------
//
// boucle: tant que position existe -> on rentre.
// -> if le flag est egale a STACK_A -> appel de ft_ra.
// -> else ft_rb (donc la stack_b)
// -> decrementation de position.

void	ft_rotate_with_position(t_node **head, int position, int flag)
{
	while (position)
	{
		if (flag == STACK_A)
			ft_ra(head);
		else
			ft_rb(head);
		position--;
	}
}
// _____________________________________________________________________________
// 
// fonction simple pour appeler la bonne fonction de reverse rotate au bon
// nombre de fois.
// 
// -----------------------------------------------------------------------------
//
// boucle: tant que position existe -> on rentre.
// -> if le flag est egale a STACK_A -> appel de ft_rra.
// -> else ft_rrb. (donc la stack_b)
// -> decrementation de position.

void	ft_reverse_rotate_with_position(t_node **head, int position, int flag)
{
	while (position)
	{
		if (flag == STACK_A)
			ft_rra(head);
		else
			ft_rrb(head);
		position--;
	}
}
// _____________________________________________________________________________
// 
// fonction simple pour definir si il faut rotate ou reverse_rotate.
// la fonction se base sur la mediane du nombre de noeud.
// si le noeud se trouve dans la premiere partie de la mediane -> rotate
// sinon -> revers_rotate
//
// -----------------------------------------------------------------------------
//
// 1] if le il y a au moins un noeud rattache au head -> on rentre.
// 2] position prend le nombre de noeuds qui separe le 1er noeud avec le noeud
//    avec le plus grand index.
// 3] if position est inferieur ou egale a la mediane du nombre de noeud total
//    -> appel de ft_rotate_with_position
//    sinon
//    -> appel ft_reverse_rotate_with_position

void	ft_optimisation_rotate(t_node **head, int position_to_start, int flag)
{
	int	position;

	if (*head)
	{
		position = position_to_start;
		if (position <= (ft_count_node(head) / 2))
			ft_rotate_with_position(head, position, flag);
		else
		{
			position = (ft_count_node(head) - position_to_start);
			ft_reverse_rotate_with_position(head, position, flag);
		}
	}
	return ;
}
// _____________________________________________________________________________
// 
// fonction qui trouve le noeud avec l'index le plus eleve et qui compte a
// quelle position du debut de la liste chainee se trouve ce noeud.
// ft_optimisation_rotate est appelee avec ces 2 informations trouvee.
// 
// -----------------------------------------------------------------------------
//
// tmp prend le meme pointeur que head.
// max est egale au au pointeur du noeud qui a le plus grand index
// (retour de ft_find_node_index_max)
// boucle: tant que le noeud tmp ne soit pas egale au noeud max -> on rentre
// -> la fonction avance avec tmp = tmp->next
// -> incrementation de position_to_start pour savoir a conbien de position est
//    notre noeud du debut.
// lorsque la boucle s'arrete nous avons la position de notre noeud.
// appel de ft_optimisation_rotate pour une savoir si il est plus judicieux de
// faire des rotate ou des reverse rotate pour mettre notre noeud
// en premiere position de la stack.
// le flag serre a savoir si c'est la stack_a ou b.

void	ft_rotates_for_max_index_first(t_node **head, int flag)
{
	int		position_to_start;
	t_node	*tmp;
	t_node	*max;

	tmp = *head;
	position_to_start = 0;
	max = ft_find_node_index_max(head);
	while (tmp != max)
	{
		tmp = tmp->next;
		position_to_start++;
	}
	ft_optimisation_rotate(head, position_to_start, flag);
}
