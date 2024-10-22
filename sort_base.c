/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:43:33 by pbret             #+#    #+#             */
/*   Updated: 2024/10/21 15:27:45 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_base(t_node **head_a, t_node **head_b)
{
	if ((ft_count_node(head_a)) == 2)
		ft_sort_2(head_a);
	if ((ft_count_node(head_a)) == 3)
		ft_sort_3(head_a);
	if ((ft_count_node(head_a)) == 4)
		ft_sort_4(head_a, head_b);
	if ((ft_count_node(head_a)) == 5)
		ft_sort_5(head_a, head_b);
}

void	ft_sort_2(t_node **head_a)
{
	if ((*head_a)->data > (*head_a)->next->data)
		ft_sa(head_a);
}

void	ft_sort_3(t_node **head_a)
{
	t_node	*tmp;

	tmp = *head_a;
	//  a < b et b < c = a b c
	if (tmp->data < tmp->next->data && tmp->next->data < tmp->next->next->data)
		return ;
	// a > b et a > c
	if (tmp->data > tmp->next->data && tmp->data > tmp->next->next->data)
		ft_ra(head_a);
	// b > a et b > c
	if (tmp->next->data > tmp->data && tmp->next->data > tmp->next->next->data)
		ft_rra(head_a);
	// a > b et c > a et c > b
	if (tmp->data > tmp->next->data && tmp->next->next->data > tmp->data
		&& tmp->next->next->data > tmp->next->data)
		ft_sa(head_a);
}

//	boucle 1 -> tant que val_b est supp a val du 1er noeud -> rotate a
//	nb_node est un compteur pour savoir si on a fait le tour des val a.
//	si nb_node == ft_count_node -> on a fait le tour,
//	comme la stack_a est deja trier, la val_b peut etre push dans a 
//	car c'est la valeur la plus haut.
//	------
//	boucle 2 -> rotate_a tant que la val du 1er noeud_a est differente 
//	a la val minimum de la stack_a jusqu'a la plus petite val soit au premier noeud
void	ft_sort_4(t_node **head_a, t_node **head_b)
{
	ft_pb(head_a, head_b);
	ft_sort_3(head_a);
	ft_push_to_good_position(head_b, head_a);
	while (((*head_a)->data != ft_find_val_min(head_a)->data))
		ft_ra(head_a);
	//ft_test(head_a, head_b);
}

/*void	ft_sort_5(t_node **head_a, t_node **head_b)
{
	ft_pb(head_a, head_b);
	ft_pb(head_a, head_b);
	ft_sort_3(head_a);
	//ft_sort_2(head_b);
	ft_push_to_good_position(head_b, head_a);
	//printf("val_min[%ld]\n", ft_find_val_min(head_a)->data);
	v
	//ft_test(head_a, head_b);
}*/
void	ft_sort_5(t_node **head_a, t_node **head_b)
{
	while (*head_a != ft_find_val_max(head_a))
		ft_ra(head_a);
	ft_push(head_a, head_b);
	while (*head_a != ft_find_val_max(head_a))
		ft_ra(head_a);
	ft_push(head_a, head_b);
	ft_sort_3(head_a);
	while (*head_b != ft_find_val_max(head_b))
		ft_rb(head_b);
	ft_push(head_b, head_a);
	ft_push(head_b, head_a);
	while (*head_a != ft_find_val_min(head_a))
	{
		printf("SEARCHING: %ld, NOW: %ld\n", ft_find_val_min(head_a)->data, (*head_a)->data);
		sleep(1);
		ft_ra(head_a);
	}
	ft_test(head_a, head_b); //
}
void	ft_test(t_node **head_a, t_node **head_b)
{
	static int	i = 1;

	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("-----------%d------------\n", i);
	i++;
}	