/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:20:14 by pbret             #+#    #+#             */
/*   Updated: 2024/09/27 16:25:05 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    **ft_management_av(int ac, char  **av)
{
    int		i;
	char **tab_brut;
    
	if(ac == 2)
		tab_brut = ft_split(av[1], ' ');
	if (ac > 2)
	{
        tab_brut = malloc (sizeof(char*) * ac - 1);
		if (!tab_brut)
			return (0);
		i = 0;	
		while (i < ac - 1) // -1 pour le nom de l 'exe.
		{
			tab_brut[i] = ft_strdup(av[i + 1]);
			i++;
		}
	}
    return (tab_brut);
}
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
        if ((tab[i][j]) && (ft_is_plus_moins(tab[i][j]))) // Vérifie s'il y a un signe au début
            j++;
        while (tab[i][j])
        {
            if (ft_isdigit(tab[i][j]))
                is_digit = 1;
            else
                return EXIT_FAILURE;
            j++;
        }
        if (!is_digit) // Vérifie s'il y avait au moins un chiffre. si uniquement '-' ou '+' il ne rentre pas dans la boucle
            return EXIT_FAILURE;
        i++;
    }
    return (EXIT_SUCCESS);
}

int ft_has_maxs(long int *tab_int, char **tab_char) //tab_char pour pouvoir compter le nombre d'elements dans mon tableau de char
{
    int i;
    int nb_elements;

    i = -1;
    nb_elements = ft_count_elem(tab_char);
    while(++i <= nb_elements)
    {
        if (tab_int[i] < INT_MIN || tab_int[i] > INT_MAX)
            return (EXIT_FAILURE);       
    }
    return (EXIT_SUCCESS);
}

int ft_has_doublon(long int *tab_int, char **tab_char)
{
    int i;
    int j;
    int nb_elements;

    nb_elements = ft_count_elem(tab_char);
    i = 0;
    while(i < nb_elements)
    {
        j = i + 1; // pas de -1 car j a un indixe decale de 1 par rapport au i, faut check le dernier element de la chaine
        while (j < nb_elements && tab_int[j])
        {
            if (tab_int[i] == tab_int[j])
                return (EXIT_FAILURE);
            printf("[%d]\n", j);
            j++;
        }
        i++;    
    }
    return (EXIT_SUCCESS);
}

long int *ft_parsing(char **tab_char)
{
    long int    *tab_int;
    
    tab_int = NULL;
    tab_int = ft_init_tab_int(tab_int, tab_char);
    //printf("ft_has_other_digits[%d]\tft_has_maxs[%d]\tft_has_doublon[%d]\t", ft_has_other_digits(tab_char), ft_has_maxs(tab_int, tab_char), ft_has_doublon(tab_int, tab_char));
	if (ft_has_other_digits(tab_char) || ft_has_maxs(tab_int, tab_char) || ft_has_doublon(tab_int, tab_char))
    {
        free(tab_int);
        return (NULL);
    }
    return (tab_int);
}

