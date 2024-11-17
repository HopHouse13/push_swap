/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:17 by pbret             #+#    #+#             */
/*   Updated: 2024/11/17 14:25:02 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// _____________________________________________________________________________
// 
// fonction pour interchanger les variables data et index du premier noeud au
// 2eme noeud et vise et versa de la stack passee en parametre.
// les noeuds ne bougent pas. (les valeurs despointeurs reste les memes)
//
// principe du swap standard *2
// 
// -----------------------------------------------------------------------------
//
// 1] verification si il y a au moins 2 noeuds a swap.
// 2] tmp prend la meme valeur que head pour pouvoir manipuler la liste chainee
//    sans perdre le pointeur de la tete de la liste chainee.
//    la fonction travaillera a partir du pointeur tmp.
//
// 3] tmp_data			->	data(1er noeud)
// 4] data(1er noeud)	->	data(2eme noeud)
// 5] data(2me noeud)	->	tmp_data
//
// 6] tmp_index			->	index(1er noeud)
// 7] index(1er noeud)	->	index(2eme noeud)
// 8] index(2me noeud)	->	tmp_index

void	ft_swap(t_node **head)
{
	t_node	*tmp;
	int		tmp_data;
	int		tmp_index;

	if (*head == NULL && (*head)->next == NULL)
		return ;
	tmp = *head;
	tmp_data = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = tmp_data;
	tmp_index = tmp->index;
	tmp->index = tmp->next->index;
	tmp->next->index = tmp_index;
}
// _____________________________________________________________________________
// 
// fonction pour passer les variables data et index du 1er noeud au dernier
// noeud de la liste chainee. ce sont uniquement les valeurs qui sont deplacees.
// les valeurs du 1er noeud sont stockees dans 2 variables temporaires puis
// chaque valeur de chaque noeud sont decaler de 1 noeud vers le haud.
// enfin les valeurs du dernier noeud prennent les valeurs stockees dans les
// variables temporaires.
// 
// -----------------------------------------------------------------------------
//
// 1] verification head et le 1er noeud de head existe.
// 2] tmp prend *head. (1er noeud de la liste chainee)
// 3] tmp_data et tmp_index prendent les valeurs respectives du 1er noeud.
// 4] boucle: tant que la liste chainee n'est pas terminee :
//    -> les variables data et index du noeud actuel prennent les valeurs
//       respectives du noeud suivant.
//    -> puis le pointeur tmp prend la valeur du noeuf suivant(pour se deplacer)
//       etc
// 5] a la fin de la boucle, la fonction se trouve au dernier noeud. (tmp)
//    les variables data/index de ce noeud prennent les valeurs stockees dans
//    les varibales tamporaires respectives.

void	ft_rotate(t_node **head)
{
	t_node	*tmp;
	int		tmp_data;
	int		tmp_index;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	tmp_data = tmp->data;
	tmp_index = tmp->index;
	while (tmp->next != NULL)
	{
		tmp->data = tmp->next->data;
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	tmp->data = tmp_data;
	tmp->index = tmp_index;
}
// _____________________________________________________________________________
// 
// fonction qui passe les variables data et index du derenier noeud au dernier
// noeud de la liste chainee. ce sont uniquement les valeurs qui sont deplacees.
// les valeurs du dernier noeud sont stockees dans 2 variables temporaires puis
// chaque valeur de chaque noeud sont decaler de 1 noeud vers le bas.
// enfin les valeurs du 1er noeud prennent les valeurs stockees dans les
// variables temporaires.
// 
// -----------------------------------------------------------------------------
//
// 1] verification head et le 1er noeud de head existe.
// 2] tmp prend *head. (1er noeud de la liste chainee)
// 3] boucle: tant que la liste chainee n'est pas terminee:
//    -> tmp prend le pointeur du noeud suivant.
// 4] tmp pointeur vers le dernier noeud, tmp_data/index prennent respectivement
//    les valeurs des varibales du dernier noeud.
// 5] boucle: tant que tmp ne prend pas la valeur du pointeur du 1er noeud:
//    -> les variables data et index du noeud actuel prennent les valeurs
//       respectives du noeud pressedent.
//    -> puis le pointeur tmp prend la valeur du noeud suivant(pour se deplacer)
//       etc
// 6] a la fin de la boucle, la fonction se trouve au 1er noeud. (tmp)
//    les variables data/index de ce noeud prennent les valeurs stockees dans
//    les varibales tamporaires respectives.

void	ft_reverse_rotate(t_node **head)
{
	t_node		*tmp;
	long int	tmp_data;
	int			tmp_index;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_data = tmp->data;
	tmp_index = tmp->index;
	while (tmp != *head)
	{
		tmp->data = tmp->prev->data;
		tmp->index = tmp->prev->index;
		tmp = tmp->prev;
	}
	tmp->data = tmp_data;
	tmp->index = tmp_index;
}

// _____________________________________________________________________________
// 
// fonction qui transfere le 1er noeud de la head_from a la premiere position 
// de head_to.
// les valeurs des variables du noeud sont stockees dans des varibales
// temporaires. le noeud de head_from est supprime puis un nouveau noeud est
// cree avec les valeurs stockees dans les variable tmp et qui est ajoute en
// premiere position de head_to. 
//
// -----------------------------------------------------------------------------
//
// 1] tmp prend le pointeur de 1er noeud de head_from.
// 2] les variables temporaires data/index prennent les valeurs respective du
//    1er noeud de head_from.
// 3] -> if il y qa plusieurs noeuds dans head_from, la fonciton fait pointer
//    le 1er noeud vers le 2eme noeud actuel.
//    nous perdons le lien qu'il y a entre le pointeur principale (head) du
//    head_from au future ancien 1er noeud. (tmp)
//    -> else la focntion fasit pointeur la head vers NULL.
// 4] la fonction libere (free) le noeud que vuet supprimer. (tmp)
// 5] appel de la fonction ft_add_start qui va creer un nouveau noeud,
//    initialiser toutes les valeurs dans la structure du noeud et relier
//    ce noeud a la liste chainee en premiere position.

void	ft_push(t_node **head_from, t_node **head_to)
{
	long int	data_tmp;
	int			index_tmp;
	t_node		*tmp;

	if (head_from == NULL)
		return ;
	tmp = *head_from;
	data_tmp = tmp->data;
	index_tmp = tmp->index;
	if (tmp->next)
		*head_from = tmp->next;
	else
		*head_from = NULL;
	free(tmp);
	ft_add_start(data_tmp, index_tmp, head_to);
}
