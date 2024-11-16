/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:22:40 by pbret             #+#    #+#             */
/*   Updated: 2024/11/16 13:26:56 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// l'enssemble des fonctions des fichiers instructions_x.c sont utiliser pour
// ecrire chaque instructions dans la sortie du terminal.
// ces fonctions font appelle aux fonctions du fichier move_stack.c.
// 
// les fonctions n'ont pas de protections car toutes les fonctions de mouvements
// sont protegees. elles sont uniquement presentes pour ecrire les bonnes
// instructions dans le terminal.
//
// -----------------------------------------------------------------------------
//

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
	ft_swap(head_a);
	ft_swap(head_b);
	write(STDOUT_FILENO, "ss\n", 3);
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
