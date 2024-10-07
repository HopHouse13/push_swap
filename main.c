/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/10/07 17:39:49 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node		*head_a = NULL;
	t_node		*head_b = NULL;
	char		**tab_brut;

	if (ac > 1)
	{
		tab_brut = ft_management_av(ac, av); // ft qui met les argv dans un tableau e tableau de char (brut)
		if (ft_parsing(tab_brut)) // retour 1 >>> error, 0 >>> validé
			ft_printf(RED"\n[error]\n\n"RESET);
		else
		{
			ft_init_list(tab_brut, &head_a);
			ft_init_list(tab_brut, &head_b);
			ft_free_tab(tab_brut);
			ft_printf(GREEN"\n[parsing valide]\n\n"RESET);
		}
		if(head_a != NULL)
		{
			ft_printf(CYAN"stack_a\n\n");
			ft_print_list(&head_a);
			ft_push(&head_a, &head_b);
			ft_ss(&head_a, &head_b);
			ft_print_list(&head_a);
			ft_printf("\n\n"RESET);
			ft_free_list(&head_a);
		}
		
		if (head_b != NULL)
		{
			ft_printf(YELLOW"stack_b\n\n");
			ft_print_list(&head_b);
			ft_push(&head_b, &head_a);
			ft_print_list(&head_b);
			ft_printf("\n\n"RESET);
			ft_free_list(&head_b);
		}
	}
	return (EXIT_SUCCESS);
}

