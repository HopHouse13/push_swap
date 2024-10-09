/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:22:40 by pbret             #+#    #+#             */
/*   Updated: 2024/10/09 15:57:00 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **head)
{
	ft_swap(head);
	ft_printf("sa\n");
}

void	ft_sb(t_node **head)
{
	ft_swap(head);
	ft_printf("sb\n");
}

void	ft_ss(t_node **head_a, t_node **head_b)
{
	if (*head_a != NULL && (*head_a)->next != NULL
		&& *head_b != NULL && (*head_b)->next != NULL)
	{
		ft_swap(head_a);
		ft_swap(head_b);
		ft_printf("ss\n");
	}
	else
		ft_printf("error\n");
}

void	ft_ra(t_node **head)
{
	ft_rotate(head);
	ft_printf("ra\n");
}

void	ft_rb(t_node **head)
{
	ft_rotate(head);
	ft_printf("rb\n");
}
