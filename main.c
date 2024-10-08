/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/10/08 18:59:27 by pbret            ###   ########.fr       */
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
		if (ft_parsing(tab_brut)) // retour 1 >>> error, 0 >>> validé
		{
			write(STDERR_FILENO, "error\n", 6);
			ft_free_tab(tab_brut);
		}
		else
		{
			ft_init_list(tab_brut, &head_a);
			ft_free_tab(tab_brut);
			ft_base_sort(&head_a, &head_b);
		}
		
		if(head_a != NULL)
			ft_free_list(&head_a);
		if (head_b != NULL)
			ft_free_list(&head_b);
	}
	return (EXIT_SUCCESS);
}

/* if(head_a != NULL)
		{
			ft_printf(CYAN"stack_a\n\n");
			ft_print_list(&head_a);
			ft_sa(&head_a);
			ft_ra(&head_a);
			ft_pb(&head_a, &head_b);
			ft_ss(&head_a, &head_b);
			ft_rr(&head_a, &head_b);
			ft_rra(&head_a);
			ft_rrr(&head_a, &head_b);
			ft_printf("\n\n");
			ft_print_list(&head_a);
			ft_printf("\n\n"RESET);
		}
		if (head_b != NULL)
		{
			ft_printf(YELLOW"stack_b\n\n");
			ft_print_list(&head_b);
			ft_sa(&head_b);
			ft_rb(&head_b);
			ft_rrb(&head_b);
			ft_pa(&head_b, &head_a);
			ft_printf("\n\n");
			ft_print_list(&head_b);
			ft_printf("\n\n"RESET);
		} */