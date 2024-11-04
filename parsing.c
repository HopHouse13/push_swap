/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:20:14 by pbret             #+#    #+#             */
/*   Updated: 2024/11/04 15:47:55 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pas de + 1 pour '\0' sur le malloc 
// car il prend la place du nom de l'executable("./push_swap")

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
// Vérifie s'il y a un signe au début
// "if (!is_digit)" -> Vérifie s'il y avait au moins un chiffre.
// si uniquement '-'/'+', il sort de la fonction

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
		if ((tab[i][j]) && (ft_is_plus_moins(tab[i][j]) == 1))
			j++;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]))
				is_digit = 1;
			else
				return (FAILURE);
			j++;
		}
		if (!is_digit)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
//tab_char pour pouvoir compter le nombre d'elements dans mon tableau de char

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

// printf("ft_has_other_digits[%d]\tft_has_maxs[%d]\tft_has_doublon[%d]",
// ft_has_other_digits(tab_char), ft_has_maxs(tab_char),
// ft_has_doublon(tab_char));

int	ft_parsing(char **tab_char)
{
	if (ft_has_other_digits(tab_char)
		|| ft_has_maxs(tab_char)
		|| ft_has_doublon(tab_char))
		return (FAILURE);
	return (SUCCESS);
}
