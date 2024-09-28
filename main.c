/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/09/28 18:15:23 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char		**tab_brut;
	/* t_node		**head_a = NULL;
	int 			i;

	i = 0; */
	tab_brut = ft_management_av(ac, av); // ft qui met les argv dans un tableau e tableau de char (brut)
	if (ft_parsing(tab_brut)) // retour 1 >>> error, 0 >>> validé
		write(2,"\n\n[error]\n", 10);
	else
	{
		/* while (tab_brut[i])
		{
			ft_add_back(ft_atoi_long(tab_brut[i]), head_a);
			i++;
		} */
		write(1,"\n[v]\n\n", 6);
	}

/* 	t_node *tempo = *head_a;
	while (tempo->next != NULL)
	{
		printf("\n\n[%ld]", tempo->data);
		tempo = tempo->next;
	} */
	return (0);
}

/* int	main(void)
{
	t_node	*head;

	ft_init_lst(10, &head);
	ft_add_back(20, &head);
	ft_add_back(30, &head);
	ft_add_back(40, &head);
	ft_add_back(50, &head);

	t_node	*tempo;

	tempo = head;
	while (tempo != NULL)
	{
		printf("value [%d]\n", tempo->data);
		tempo = tempo->next;
	}
	ft_free(&head);
	return (0);
} */

