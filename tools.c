/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:35:06 by pbret             #+#    #+#             */
/*   Updated: 2024/10/24 15:44:46 by ubuntu           ###   ########.fr       */
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
	printf("\n\n");
}
// En 2 etapes:
// - on trouve la plus petite valeur des node qui n'ont pas encore ete indexes (index enocre a -1 (non indexe)) 
// cette valeur sera stocker dans "val_min"
// - on repart au debut de la liste chainee et on compare chaque data avec la val_min pour
// trouver le node avec la valeur la plus petite. On retourne le pointeur de ce node
t_node	*ft_find_node_not_index_and_val_min(t_node **head)
{
	long int	val_min;
	t_node		*tmp;
	
	if (*head == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	val_min = INT_MAX;
while (tmp != NULL)
	{
		if (val_min > tmp->data && tmp->index == -1) // indiex = -1 veut dire que le node n'a pas encore ete indexe
		{
			val_min = tmp->data;
			tmp = *head;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (val_min != tmp->data)
		tmp = tmp->next;
	return (tmp);
}

// 2 etapes:
// - on trouve le plus petit index de la liste chainee que l'on stock dans "index_max"
// - on reviens au debut pour comparer l'index de chaque node avec index_max pour trouver et renvoyer le node avec le plus grand index
t_node		*ft_find_node_index_max(t_node **head)
{
	long int	index_max;
	t_node		*tmp;
	
	if (*head == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	index_max = INT_MIN;
	while (tmp != NULL)
	{
		if (index_max < tmp->index)
		{
			index_max = tmp->index;
			tmp = *head;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (index_max != tmp->index)
		tmp = tmp->next;
	return (tmp);
}
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
//	boucle_1 : tant qu'il y a un node dans la stack from (b)
//	boucle_2 : tant que val puch est supp que la premiere val de stack_to
//				-> rotate stack_to + nb_node++
//	if : si on a fait le tour de toutes les val de la stack_to
//	cela veut dire qu'on veut push la val la plus haute de toutes les val
//	et comme la stack_to est deja trier, 
//	naturellement la val la plus petite se trouve en 1er
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
void	ft_initialisation_index(t_node **head)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *head;
	if (*head == NULL)
		return ;
	while (i < ft_count_node(head))
	{
		tmp = ft_find_node_not_index_and_val_min(head);
		tmp->index = i;
		i++;
	}
	tmp = *head;
 	// while (tmp != NULL)
	// {
	// 	printf("[%d]\t[%ld]\n", tmp->index, tmp->data);
	// 	tmp = tmp->next;
	// }
}
int	ft_check_if_sort(t_node **head)
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
