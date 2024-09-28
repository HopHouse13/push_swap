/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:35:06 by pbret             #+#    #+#             */
/*   Updated: 2024/09/27 16:16:00 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_long(char *str) //valider
{
	int			i;
	long int	sign;
	long int	resultat;

	i = 0;
	sign = 1;
	resultat = 0;
	
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		resultat = resultat * 10 + (str[i++] - '0');
	return (resultat * sign);
}

long int *ft_init_tab_int(long int *tab_int, char **tab_char)
{
	int i;
    int nb_elements;
	
	i = 0;
	nb_elements = ft_count_elem(tab_char);
	tab_int = malloc(sizeof(long int) * nb_elements);
	// tab_int = ft_calloc(nb_elements + 1, sizeof(long int));
	if (!tab_int)
		return (NULL);
	i = 0;
	while (i < nb_elements)
	{
		tab_int[i] = ft_atoi_long(tab_char[i]);
		i++;
	}
	return (tab_int);
}
int	ft_count_elem(char **tab_char)
{
    int nb_elements;
	
    nb_elements = 0;
	if (tab_char == NULL)
		return (1);
    while (tab_char[nb_elements] != NULL)
		nb_elements++;
	return (nb_elements + 1);
}
