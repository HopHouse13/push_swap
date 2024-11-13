/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:20:14 by pbret             #+#    #+#             */
/*   Updated: 2024/11/13 09:50:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction pour passer le/les parametres d'entree dans tab_brut (tableau char)
// 
// -----------------------------------------------------------------------------
// 2 cas: 
// - soit 1 parametre entre double cote : ./push_swap "5 4 3 2 1"
// 		-> ft_split avec le av[1] 
//		-> tab de tab avec chaque valeur par tableau
// - soit x parametres sans double cote : ./push_swap 5 4 3 2 1
//		-> malloc de type (char *) * ac (nb de parametres)
// 		-> boucle pour dupliquer chaque valeur dans chaque tab avec ft_strdup
// pas de + 1 pour '\0' au malloc car il prend la place du nom de l'executable
// ("./push_swap")

char	**ft_management_av(int ac, char **av)
{
	int		i;
	char	**tab_brut;

	if (ac == 2)
		tab_brut = ft_split_argv(av[1]);
	if (ac > 2)
	{
		tab_brut = malloc (sizeof(char *) * ac);
		if (!tab_brut)
			return (NULL);
		i = 0;
		while (av[i + 1])
		{
			tab_brut[i] = ft_strdup(av[i + 1]);
			i++;
		}
		tab_brut[i] = NULL;
	}
	return (tab_brut);
}
// _____________________________________________________________________________
//
// Fonction qui check si dans chaque tableau de valeurs,
// il y a uniquement des digits et si les signes +/- sont au bon enplacement.
//
// -----------------------------------------------------------------------------
//
// 1] Vérifie s'il y a un signe au début-> si c'est le cas-> j++; on avance d'un
// 2] boucle tant que le tableau existe -> si autre que digits, 'FAILURE'
// 3] "if (!is_digit)" -> Vérifie s'il y a au moins un chiffre apres le signe
// Forcement si minimum 1 digit dans le tableau -> "is_digit" prend 1
// Sinon il reste a 0 (comme a son initialisation a chauque tableau)
// -> on rentre dans le "if (is_digit != FAILURE)" -> 'FAILURE' (= 1, MACRO)
// 4] i++; on avance au tableau suivant jusqu'a la fin du tableau du tableau

int	ft_has_other_digits(char **tab)
{
	int	i;
	int	j;
	int	is_digit;

	i = 0;
	while (tab[i])
	{
		j = 0;
		is_digit = 0;
		if ((tab[i][0]) && ((tab[i][j]) == '+' || tab[i][0] == '-'))
			j++;
		while (tab[i][j])
		{
			if (tab[i][j] >= '0' && tab[i][j] <= '9')
				is_digit = FAILURE;
			else
				return (FAILURE);
			j++;
		}
		if (is_digit != FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
// _____________________________________________________________________________
//
// fonction qui check si chaque valeur ne depasse pas le INT_MIN et INT_MAX.
//
// -----------------------------------------------------------------------------
//
// convertion de char -> int pour chaque valeur controlee. (tab_char[i]

int	ft_has_maxs(char **tab_char)
{
	int	i;

	i = 0;
	while (tab_char[i])
	{
		if (ft_atoi_long(tab_char[i]) < INT_MIN
			|| ft_atoi_long(tab_char[i]) > INT_MAX)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
// _____________________________________________________________________________
//
// fonction qui check si il y a un double dans l'ensemble des valeurs.
//
// -----------------------------------------------------------------------------
//
// 1] boucle: tant que le tab de tab existe -> on rentre dans cette boucle
// 2] 2eme boucle: tant que le tableau de tableau existe -> on rentre
// on commence a checker cette condition a i + 1, cad a partir du tableau
// qui suit le tableau[i].
// 3] if qui compare la valeur du 'i' eme tab avec la valeur du tableau suivant.
// valeurs encore convertient en int.

int	ft_has_doublon(char **tab_char)
{
	int	i;
	int	j;

	i = 0;
	while (tab_char[i])
	{
		j = i + 1;
		while (tab_char[j])
		{
			if (ft_atoi_long(tab_char[i]) == ft_atoi_long(tab_char[j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
// _____________________________________________________________________________
//
// Fonction qui acticule les 3 fonctions du parcing.
//
// -----------------------------------------------------------------------------
//
// si l'une des 3 fonctions renvoit 'FAILURE', la fonction renvoie 'FAILURE'
// a son tour. Sinon -> 'SUCCESS'
//
// Un printf qui affiche clairement le resultat de chaque fonction:
//
// printf("ft_has_other_digits[%d]\tft_has_maxs[%d]\tft_has_doublon[%d]",
// ft_has_other_digits(tab_char), ft_has_maxs(tab_char),
// ft_has_doublon(tab_char));

int	ft_parsing(char **tab_char)
{
	if (ft_has_other_digits(tab_char) == FAILURE
		|| ft_has_maxs(tab_char) == FAILURE
		|| ft_has_doublon(tab_char) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
