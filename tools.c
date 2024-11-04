/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:35:06 by pbret             #+#    #+#             */
/*   Updated: 2024/11/04 16:44:08 by ubuntu           ###   ########.fr       */
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

int	ft_count_node(t_node **head)
{
	t_node	*tmp;
	int	count_node;

	tmp = *head;
	count_node = 0;
	while (tmp != NULL)
	{
		count_node += 1;
		tmp = tmp->next;
	}
	return (count_node);
}
void	ft_print_list(t_node **head)
{
	t_node *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("index[%d]\tdata[%ld]\n",tmp->index, tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

// fonction uniquement pour ft_sort_4
// 2 etapes:
// - on trouve le plus petit index de la liste chainee que l'on stock dans "index_min"
// - on reviens au debut pour comparer l'index de chaque node avec index_min pour trouver et renvoyer le node avec le plus petit index

t_node		*ft_find_node_index_min(t_node **head)
{
	long int	index_min;
	t_node		*tmp;
	
	if (*head == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	index_min = INT_MAX;
	while (tmp != NULL)
	{
		if (index_min > tmp->index)
		{
			index_min = tmp->index;
			tmp = *head;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (index_min != tmp->index)
		tmp = tmp->next;
	return (tmp);
}
// fonction uniquement pour ft_sort_4
//	boucle_1 : tant qu'il y a un node dans la stack from (b)
//	boucle_2 : tant que val puch est supp que la premiere val de stack_to
//				-> rotate stack_to + nb_node++
//	if : si on a fait le tour de toutes les val de la stack_to
//	cela veut dire qu'on veut push la val la plus haute de toutes les val
//	et comme la stack_to est deja trier, 
//	naturellement la val la plus petite se trouve en 1er
//	while (ft_count_node(head_from)) cette condition fonctionne car cette fonction est appelee une seule fois, dans la ft_sort_4.
//	Dans cette fonction on push un seul node dans la stack_b.
//	Cette fonction a pour role de de push la seule valeur de la stack_b a la stack_a a la bonne place.
//	Temps que la stack_a n'est pas a la bonne position -> ft_ra et
//	la val seule de la stack_b est tjs en B donc la condition de la boucle principale est bonnne.

void	ft_push_to_good_position(t_node **head_from, t_node **head_to)
{
	int	nb_node;

	while (ft_count_node(head_from))
	{
		nb_node = 0;
		while ((*head_from)->data > (*head_to)->data)
		{
			if (nb_node == ft_count_node(head_to))
				break ;
			ft_ra(head_to);
			nb_node++;
		}
		ft_pa(head_from, head_to);
	}
}

int	ft_head_a_is_sorted(t_node **head)
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
