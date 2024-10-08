/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:43:33 by pbret             #+#    #+#             */
/*   Updated: 2024/10/08 19:15:07 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_base_sort(t_node head_a, t_node head_b);
{
	if((ft_count_node(head_a)) == 3);
		ft_sort_3(head_a, head_b);
	
	if((ft_count_node(head_a)) == 5);
		ft_sort_5(head_a, head_b);
}

void	ft_sort_3(t_node **head_a, t_node **head_b)
{
	
}

void	ft_sort_5(t_node **head_a, t_node **head_b)
{
	
}