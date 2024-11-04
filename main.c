/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/11/04 11:23:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft qui met les argv dans un tableau e tableau de char (brut)
// retour 1 (FAILUIRE) >>> error, 0 (SUCCESS)>>> validé
int	main(int ac, char **av)
{
	t_node		*head_a;
	t_node		*head_b;
	char		**tab_brut;

	head_a = NULL;
	head_b = NULL;
	if (ac > 1)
	{
		tab_brut = ft_management_av(ac, av);
		if (ft_parsing(tab_brut) == FAILURE)
		{
			write(STDERR_FILENO, "Error\n", 6);
			ft_free_tab(tab_brut);
		}
		else
		{
			ft_init_list(tab_brut, &head_a);
			ft_free_tab(tab_brut);
			ft_initialisation_index(&head_a);
			if (ft_head_a_is_sorted(&head_a) == FAILURE)
			{
				if (ft_count_node(&head_a) == 1)
					return (SUCCESS);
				if (ft_count_node(&head_a) >= 2 && ft_count_node(&head_a) <= 5)
					ft_sort_base(&head_a, &head_b);
				else
					ft_big_sort(&head_a, &head_b);
			}
		}
		ft_free_lists(&head_a, &head_b);
	}
	return (SUCCESS);
}
