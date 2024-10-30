/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:43:33 by pbret             #+#    #+#             */
/*   Updated: 2024/10/30 18:43:56 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_base(t_node **head_a, t_node **head_b)
{
	if ((ft_count_node(head_a)) == 2)
		ft_sort_2(head_a);
	if ((ft_count_node(head_a)) == 3)
		ft_sort_3(head_a, head_a);
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

void	ft_sort_3(t_node **head_a, t_node ** head_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = *head_a;
	tmp_b = *head_b;
	//  a < b et b < c = a b c
	if (tmp_a->data < tmp_a->next->data && tmp_a->next->data < tmp_a->next->next->data)
		return ;
	// a > b et a > c
	if (tmp_a->data > tmp_a->next->data && tmp_a->data > tmp_a->next->next->data)
		ft_ra(head_a);
	// b > a et b > c
	if (tmp_a->next->data > tmp_a->data && tmp_a->next->data > tmp_a->next->next->data)
		ft_rra(head_a);
	// a > b et c > a et c > b
	if (tmp_a->data > tmp_a->next->data && tmp_a->next->next->data > tmp_a->data
		&& tmp_a->next->next->data > tmp_a->next->data)
		{
			if (tmp_b && tmp_b->next && tmp_b->index < tmp_b->next->index)
				ft_ss(head_a, head_b);
			else 
				ft_sa(head_a);
		}
}

//	boucle -> rotate_a tant que la val du 1er noeud_a est differente 
//	a la val minimum de la stack_a jusqu'a la plus petite val soit au premier noeud
void	ft_sort_4(t_node **head_a, t_node **head_b)
{
	ft_pb(head_a, head_b); 
	ft_sort_3(head_a, head_b);
	ft_push_to_good_position(head_b, head_a);
	while (((*head_a) != ft_find_node_index_min(head_a)))
		ft_ra(head_a);
	//ft_test(head_a, head_b);
}
// 1)	ft_rotates_for_max_index_first(x2) pour rotate et push(x2) les 2 plus grands index en head_b
//		ft_rotates_for_max_index_first est use pour optimiser les rotations (rotate ou reverse rotate)		
//		selon la position du node en question et le debut de la chainee listee
// 2)	ft_sort_3 trie head_a avec une optimisation pour les ft_sa qui devient
//		ft_ss si besoin de swap head_b pour avoir la plus grande valeur au 1er node
//3)	
//
//
//
void	ft_sort_5(t_node **head_a, t_node **head_b)
{
	//ft_test(head_a, head_b);
	ft_rotates_for_max_index_first(head_a, stack_a);
	ft_pb(head_a, head_b);
	//ft_test(head_a, head_b);
	ft_rotates_for_max_index_first(head_a, stack_a);
	ft_pb(head_a, head_b);
	//ft_test(head_a, head_b);
	ft_sort_3(head_a, head_b);
	//ft_test(head_a, head_b);
	ft_rotates_for_max_index_first(head_b, stack_b);
	//ft_test(head_a, head_b);
	ft_pa(head_b, head_a);
	ft_pa(head_b, head_a);
	//ft_test(head_a, head_b);
	ft_ra(head_a);
	ft_ra(head_a);
	//ft_test(head_a, head_b);
}

void	ft_test(t_node **head_a, t_node **head_b)
{
	static int	i = 1;

	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("-----------%d------------\n", i);
	i++;
}