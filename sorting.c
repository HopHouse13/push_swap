/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:58:18 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/05 19:15:18 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_sort_base(&head_a, &head_b);
		else
			ft_big_sort(&head_a, &head_b);
	}
	ft_free_lists(&head_a, &head_b);
}
