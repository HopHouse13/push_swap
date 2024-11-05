/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/11/05 19:03:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft qui met les argv dans un tableau e tableau de char (brut)
// retour 1 (FAILUIRE) >>> error, 0 (SUCCESS)>>> validé
int	main(int ac, char **av)
{
	char		**tab_brut;

	if (ac > 1)
	{
		tab_brut = ft_management_av(ac, av);
		if (ft_parsing(tab_brut) == FAILURE)
		{
			write(STDERR_FILENO, "Error\n", 6);
			ft_free_tab(tab_brut);
		}
		else
			ft_sorting(tab_brut);
	}
	return (SUCCESS);
}
