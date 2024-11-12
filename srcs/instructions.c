/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:22:40 by pbret             #+#    #+#             */
/*   Updated: 2024/11/05 16:29:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **head)
{
	ft_swap(head);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	ft_sb(t_node **head)
{
	ft_swap(head);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	ft_ss(t_node **head_a, t_node **head_b)
{
	if (*head_a != NULL && (*head_a)->next != NULL
		&& *head_b != NULL && (*head_b)->next != NULL)
	{
		ft_swap(head_a);
		ft_swap(head_b);
		write(STDOUT_FILENO, "ss\n", 3);
	}
	else
		write(STDOUT_FILENO, "error\n", 6);
}

void	ft_ra(t_node **head)
{
	ft_rotate(head);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	ft_rb(t_node **head)
{
	ft_rotate(head);
	write(STDOUT_FILENO, "rb\n", 3);
}
