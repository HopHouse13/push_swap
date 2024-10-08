/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:22:40 by pbret             #+#    #+#             */
/*   Updated: 2024/10/08 10:53:55 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_node **head_a, t_node **head_b)
{
	if (*head_a != NULL && *head_b != NULL)
	{
		ft_rotate(head_a);
		ft_rotate(head_b);
		ft_printf("rr\n");
	}
	else
		ft_printf("error\n");
}

void	ft_rra(t_node **head)
{
	ft_reverse_rotate(head);
	ft_printf("rra\n");
}

void	ft_rrb(t_node **head)
{
	ft_reverse_rotate(head);
	ft_printf("rrb\n");
}

void	ft_rrr(t_node **head_a, t_node **head_b)
{
	if (*head_a != NULL && *head_b != NULL)
	{
		ft_reverse_rotate(head_a);
		ft_reverse_rotate(head_b);
		ft_printf("rrr\n");
	}
	else
		ft_printf("error\n");
}

void	ft_pa(t_node **head_from, t_node **head_to)
{
	ft_push(head_from, head_to);
	ft_printf("pa\n");
}
