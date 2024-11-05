/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:35:52 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/05 18:38:00 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_list(t_node **head)
{
	t_node *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("index[%d]\tdata[%ld]\n",tmp->index, tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
void	ft_print(t_node **head_a, t_node **head_b)
{
	static int	i = 1;

	ft_print_list(head_a);
	ft_print_list(head_b);
	printf("-----------%d------------\n", i);
	i++;
}