/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fHea <fHea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:43:33 by pbret             #+#    #+#             */
/*   Updated: 2024/10/15 17:11:08 by fHea             ###   ########.fr       */
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
	/* if ((ft_count_node(head_a)) == 5)
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
	int			nb_node;
	long int	val_min;
	t_node		*tmp_a;
	
	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("-----------1------------\n");
	ft_pb(head_a, head_b);
	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("----------2-------------\n");
	ft_sort_3(head_a);
	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("-----------3------------\n");
	tmp_a = *head_a;
	nb_node = 0;
	while ((*head_b)->data > (*head_a)->data && tmp_a->next != NULL) // Quand je  remplace "tmp_a" par (*head_a), lors des ra, ca supprime mes noeuds
	{		printf("%d\n", nb_node);	
		if (nb_node == ft_count_node(head_a))
		{
		printf("(%d)\n", ft_count_node(head_a));
			ft_ra(head_a);
			break ;
		}
		ft_ra(head_a);
		nb_node++;
		tmp_a = tmp_a->next;
		// printf("data_tmp(%ld)\n", tmp_a->data);
		// printf("data_head_a(%ld)\n", (*head_a)->data);
	}
	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("-----------4------------\n");
	ft_pa(head_b, head_a);
	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("----------5------------\n");
	val_min = ft_find_val_min(head_a);
	tmp_a = *head_a;
	while (tmp_a->next != NULL)
	{
		if (tmp_a->data == val_min)
			break ;
		ft_ra(&tmp_a);
		tmp_a = tmp_a->next;
	}
	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("-----------------------\n");
}
/* void	ft_sort_5(t_node **head_a, t_node **head_b)
{
	
} */

