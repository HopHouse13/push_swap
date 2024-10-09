/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:43:33 by pbret             #+#    #+#             */
/*   Updated: 2024/10/09 17:52:03 by pbret            ###   ########.fr       */
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
/* 	if ((ft_count_node(head_a)) == 5)
		ft_sort_5(head_a, head_b); */
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
void	ft_sort_4(t_node **head_a, t_node **head_b)
{
	t_node	*tmp_a;

	tmp_a = *head_a;
	ft_pb(head_a, head_b);
	// checker si ca a bien push en b  !!!!! seg fault !!!!!!!!!
	ft_sort_3(head_a);
	while ((*head_b)->data > tmp_a->data)
		ft_ra(head_a);
	ft_pa(head_b, head_a);	
}
/* void	ft_sort_5(t_node **head_a, t_node **head_b)
{
	
} */

