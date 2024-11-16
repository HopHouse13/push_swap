/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/11/16 13:47:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction d'appelle de fonction main.
// 
// -----------------------------------------------------------------------------
//
// 1] if il y a plus que 1 arguments en parametre d'entree -> on rentre.
//    sinon le programme se cloture et renvoir rien.
// 2] stockage du tableau de tableau avec chaque valeur par tableau que renvoie
//    ft_management_av dans tab_brut.
// 3] -> if le retour de la ft_parsing est egale a FAILURE(1) -> le programme
//    ecrit "Error" et free l'ensemble des tableaux et le tableau principal.
//    -> else la fonction ft_sorting est appelee.

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
