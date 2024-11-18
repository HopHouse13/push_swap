/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:28:55 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/18 18:51:21 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// la fonction a pour but de trier la suite des valeurs de 6 a INT_MAX.
// elle compare bit par bit l'ensemble des index.
// 1er bit de droite :
// 
// -> si le bit est un 1	-> rotate stack_a
// -> sinon (bit = 0)		-> push stack_b
// (1er bit = 0 en stack_b ou 1er bit = 1 en stack_a)
//
// apres avoir traite l'ensemble des noeuds, la fonction push tous les noeuds de
// la stack_b dans la stack_a dans l'ordre inverse d'arrivee. 
// (1er noeud push en b -> dernier push en a)
//
// puis cette operation est repetee avec le 2eme bit en partant de droite.
//
// cette manipulation est repetee autant de fois qu'il y a de bits dans la
// plus grande valeur index trouvee dans la liste chainee pour pouvoir traiter
// l'entierete des bits dans l'ensemble des valeurs index.
// 
// -----------------------------------------------------------------------------
//
// 1] index_biggest prend la valeur index du noeud que retourne
//    ft_find_node_index_max. (le plus grand index)
//
// 2] max_bits est initialisee a zero.
//
// 3] cette boucle sert a definir combien de bits on aura a comparer pour
//    traiter l'ensemble des bits qui se trouvent dans la plus grande
//    valeur index.
//    tant que le bit shifting de la valeur de index_biggest est
//    different de NULL -> on rentre
//    -> incrementation de la variable max_bits.
//
//    max_bits est une valeur de "decalage" de bits -> comparaison du X eme bit
//    de index_biggest, X etant la valeur de max_bits. comme cette valeur est
//    incrementee a chaque passe de boucle, les bits sont decales toujours de 1.
//
// 4] initialisation de i a zero.
//
// 5] boucle: tant que i est inferieur a max_bits (plus grand nombre de bits)
//    cette boucle garantit que la fonction aura compare la totalite des bits.
//    -> on rentre
//
//    -> nb_nodes_stack_a prend le nombre de noeud dans la stack_a
//       (retour de ft_count_node) pour sortir de la 2eme boucle apres avoir
//       traite l'ensemble des noeuds pour chaque bit compare.
//
//    -> boucle: tant que nb_nodes_stack_a est different de 0 -> on rentre.
//
//    -> la fonction traite noeud par noeud.
//       if le noeud actuel a comme index, un index avec un 1 au I eme bit
//       (valeur de i) alors la stack_a est rotate de 1 avec l'appel de ft_ra.
//
//    -> else le noeud est push en b car son I eme bit = 0 avec l'appel de ft_pb
//       cette ligne "if ((((*head_a)->index >> i) & 1) == 1)" signifit:
//
//       si le bit est 1 & 1	=	1		->	la condition est vrai.
//
//       					contrairement a :
//
//       si le bit est 0 & 1	=	0		->	la condition est fausse.
//
//    -> decrementation de nb_nodes_stack_a pour traiter l'ensemble des noeuds
//
//    -> apres que la totalite des noeuds ont ete traites, la fonction push tous
//       les noeuds de la stack_b en stack_a dans l'ordre d'arrive :
//       dernier arrive -> 1er push
//       ce processus est accompli par une petite boucle:
//       tant que le retour de ft_count_node est different de zero -> push en a
//        
//    -> incrementation de i pour decaler de 1 le bit comparer et on recommence
//       du debut de la boucle avec la comparaison du bit suivant de tous les
//       index de l'ensemble des noeuds de la liste chainee.
//
//    a la fin quand tout ce processus est fini, la stack_a est triee dans
//    l'ordre croissant.

void	ft_big_sort(t_node **head_a, t_node **head_b)
{
	int	index_biggest;
	int	max_bits;
	int	i;
	int	nb_nodes_stack_a;

	index_biggest = ft_find_node_index_max(head_a)->index;
	max_bits = 0;
	while (index_biggest >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		nb_nodes_stack_a = ft_count_node(head_a);
		while (nb_nodes_stack_a != 0)
		{
			if ((((*head_a)->index >> i) & 1) == 1)
				ft_ra(head_a);
			else
				ft_pb(head_a, head_b);
			nb_nodes_stack_a--;
		}
		while (ft_count_node(head_b) != 0)
			ft_pa(head_b, head_a);
		i++;
	}
}
