/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:18 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/17 17:56:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction de management du tri apres avoir verifie la conformite des val 
// d'entree 
// 
// -----------------------------------------------------------------------------
//
// 1] initialisation de la liste chainee a partir tab_brut et du pointeur head_a
// 2] free tab_brut car nous n'en avons plus besoin
// 3] initialisation d'un index pour chaque valeur en rapport a la puissance de 
//    la valeur exemple 99 -> index 1, 110 -> index 2, -10 -> index 0
// 4] if la liste chainee "head_a" n'est pas triee -> on rentre
// 5] en fonction le nombre de valeur, on fonction est appelee
// 		- 1 valeur -> return de la fonction
// 		- de 2 a 5 valeurs -> ft_base_sort
//		- de 6 a INT_MAX (2147483647)
// 6] apres avoir ete triee, la liste chainee est liberee

void	ft_sorting(char **tab_brut)
{
	t_node		*head_a;
	t_node		*head_b;

	head_a = NULL;
	head_b = NULL;
	ft_init_list(tab_brut, &head_a);
	ft_free_tab(tab_brut);
	ft_initialisation_index(&head_a);
	if (ft_stack_a_is_sorted(&head_a) == FAILURE)
	{
		if (ft_count_node(&head_a) == 1)
			return ;
		if (ft_count_node(&head_a) >= 2 && ft_count_node(&head_a) <= 5)
			ft_base_sort(&head_a, &head_b);
		else
			ft_big_sort(&head_a, &head_b);
	}
	ft_free_lists(&head_a, &head_b);
}
