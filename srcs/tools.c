/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:35:06 by pbret             #+#    #+#             */
/*   Updated: 2024/11/17 18:19:58 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction qui convertit et renvoie un long int a partir d'une chaine de carac.
// 
// -----------------------------------------------------------------------------
// 
// if au 1er carac chaine il ya une + ou un - -> on rentre.
// -> if c'est un - -> sign devient -1
// -> incrementation de l'index d'avancement
// boucle: tant que le carac est un digits -> on rentre.
// -> resultat (0) + *10 (pour se decaler de 1) + le carac - '0' (pour convetir
//  carac digits en valeur)
// '0' = +48 dans la table ASCII
// enfin revoie de la valeur de la variable resultat (qui est une valeur par
// des carac) * sign (qui est soit 1 ou -1. ce qui definit si la valeur est
// negative ou positive)

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
// 1] la fonction fait pointer tmp sur le 1er noeud comme le pointeur head.
//    la fonction va manipuler tmp pour conserver le pointeur head.
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

// _____________________________________________________________________________
// 
// fonction qui controle si les noeud de la liste chainee passee en parametre
// est dans l'ordre croissant par rapport a la valeur de la variable index.
// 
// -----------------------------------------------------------------------------
//
// boucle: tant que la fonction n'est pas au dernier noeud, on reste dans
// la boucle et on avance au noeud suivant. (tmp = tmp->next)
// -> if la valeur de index st superieur a la val de index du noeud suivant ->
// la fonction retourne 'FAILURE' (1)
// si la boucle se termine -> l'ensemble des noeuds ont ete compares et que
// la totalite des noeuds sont dans l'odre croissants.
// la fonction renvoie 'SUCCESS' (0)

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

// _____________________________________________________________________________
// 
// fonction pour dupliquer une chaine de carac rentree en parametre d'entree
// et renvoyer la copie.
// 
// -----------------------------------------------------------------------------
//
// elle est utlisee pour remplir le tableau tab_brut lors que les parametres
// d'entree du programme sont un parametre par valeur. le programme a besoin de
// rentrer chaque valeur dans une chaine de carc dans un double tableau pour
// verifier si la liste de valeurs d'entre soit bien conforme.

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
