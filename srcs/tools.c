/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:35:06 by pbret             #+#    #+#             */
/*   Updated: 2024/11/13 18:04:11 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_long(char *str)
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
// _____________________________________________________________________________
// 
// fonction pour liberer la memoire allouee aux tableaux dans tab_brut
// 
// -----------------------------------------------------------------------------
// 
// if le pointeur du tableau principal n'est pas nul -> on rentre
// boucle tant que le sous-tableau existe -> on rentre
// free de chaque pointeur (sous-tableau) puis on passe au suivant
// ne pas oublier de free egalement le pointeur du tableau principal

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return ;
}
// _____________________________________________________________________________
// 
// fonction qui renvoie le nombre dew nooeud dans la liste chainee en parametre.
// 
// -----------------------------------------------------------------------------
//
// 1] la fonction fait pointer tmp sur le 1er noeud de head comme *head.
//    la fonction va manipuler tmp pour garder le pointeur de *head.
// 2] boucle: tant que la liste chainee n'est pas terminer -> on rentre.
//    -> count_node (initialise a 0) est incremente de 1.
//    -> puis la fonction passe au noeud suivant en faisant prendre le pointeur
//    de next (pointeur du noeud suivant) a tmp. (noeud actuel)
// 3] lorsque la boucle se termine, la fonction a parcouru l'entierete
//    des noeuds de la liste chaine et donc la valeur de count_node est
//    le bon nombre de noeuds. cette variable sera retournee.

int	ft_count_node(t_node **head)
{
	t_node	*tmp;
	int		count_node;

	tmp = *head;
	count_node = 0;
	while (tmp != NULL)
	{
		count_node += 1;
		tmp = tmp->next;
	}
	return (count_node);
}

int	ft_stack_a_is_sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

char	*ft_strdup(const char *s_src)
{
	char	*s_dup;
	size_t	i;

	i = 0;
	while (s_src[i])
		i++;
	s_dup = malloc(sizeof(char) * i + 1);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s_src[i])
	{
		s_dup[i] = s_src[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
