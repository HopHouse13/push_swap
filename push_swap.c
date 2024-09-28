/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:35 by pbret             #+#    #+#             */
/*   Updated: 2024/09/27 14:56:40 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
	char		**tab_brut;
	//t_node		**head_a = NULL;

	
	tab_brut = ft_management_av(ac, av); // ft qui met les argv dans un tableau e tableau de char (brut)
	if (ft_parsing(tab_brut)) //ft_parsing renvoie soit un tab de int si conforme ou NULL si non conforme
	{
		//ft_init_stack(head_a, ft_parsing(tab_brut), tab_brut); // le retour de ft_parsing est une tablaeau de int
		write(1,"\n[v]\n\n", 6);
	}
	else
	{
		//>>> while (condition pour free le **tab_brut, maybe une ft pour)
		write(2,"\n\n[error]\n", 10);
	}

	/* t_node *tempo = *head_a;
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

