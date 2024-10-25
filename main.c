/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/10/25 12:32:22 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node		*head_a;
	t_node		*head_b;
	char		**tab_brut;

	head_a = NULL;
	head_b = NULL;
	if (ac > 1)
	{
		tab_brut = ft_management_av(ac, av); // ft qui met les argv dans un tableau e tableau de char (brut)
		if (ft_parsing(tab_brut) == FAILURE) // retour 1 (FAILUIRE) >>> error, 0 (SUCCESS)>>> validé
		{
			write(STDERR_FILENO, "Error\n", 6);
			ft_free_tab(tab_brut);
		}
		else
		{
			ft_init_list(tab_brut, &head_a);
			ft_free_tab(tab_brut);
			ft_initialisation_index(&head_a);
			if (ft_check_if_sort(&head_a) == FAILURE)
			{
				if (ft_count_node(&head_a) == 1)
					return (SUCCESS);
				if (ft_count_node(&head_a) >= 2 && ft_count_node(&head_a) <= 5)
					ft_sort_base(&head_a, &head_b);
				// else
				//	ft_big_sort(&head_a, &head_b);
			}
		}
		ft_free_lists(&head_a, &head_b);
	}
	return (SUCCESS);
}


//printf("[%d]\n", ft_count_node(&head_a));
/* if(head_a != NULL)
		{
			printf(CYAN"stack_a\n\n");
			ft_print_list(&head_a);
			ft_sa(&head_a);
			ft_ra(&head_a);
			ft_pb(&head_a, &head_b);
			ft_ss(&head_a, &head_b);
			ft_rr(&head_a, &head_b);
			ft_rra(&head_a);
			ft_rrr(&head_a, &head_b);
			printf("\n\n");
			ft_print_list(&head_a);
			printf("\n\n"RESET);
		}
		if (head_b != NULL)
		{
			printf(YELLOW"stack_b\n\n");
			ft_print_list(&head_b);
			ft_sa(&head_b);
			ft_rb(&head_b);
			ft_rrb(&head_b);
			ft_pa(&head_b, &head_a);
			printf("\n\n");
			ft_print_list(&head_b);
			printf("\n\n"RESET);
		} */