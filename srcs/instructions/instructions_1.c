/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:22:40 by pbret             #+#    #+#             */
/*   Updated: 2024/11/16 13:23:16 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_node **head_a, t_node **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	ft_rra(t_node **head)
{
	ft_reverse_rotate(head);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	ft_rrb(t_node **head)
{
	ft_reverse_rotate(head);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	ft_rrr(t_node **head_a, t_node **head_b)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
	write(STDOUT_FILENO, "rrr\n", 4);
}

void	ft_pa(t_node **head_from, t_node **head_to)
{
	ft_push(head_from, head_to);
	write(STDOUT_FILENO, "pa\n", 3);
}
