/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:50 by pbret             #+#    #+#             */
/*   Updated: 2024/09/23 15:17:23 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// converti un nombre dans une chaine de carac. envaleur entiere int
// 1] gestion des "spaces", tant que ft_isspace est vrai -> incrementation
// 2] definir si notre entier sera positif ou negatif (sign) + incrementation
// 3] conversion en entier -> *10 pour decaler les unites
//    + convertion du carac en valeur (- 48) == (- '0') valeur ASCII

int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	resultat;

	i = 0;
	sign = 1;
	resultat = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		resultat = resultat * 10 + (str[i++] - '0');
	return (resultat * sign);
}

// int	main(void)
// {
// 	char str[] = "\t \n-1687z46fmsh";
// 	printf("[%d]\n", ft_atoi((const char *)str));
// 	return (0);
// }