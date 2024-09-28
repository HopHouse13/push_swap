/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:35 by pbret             #+#    #+#             */
/*   Updated: 2024/06/08 17:31:41 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ecrit La chaîne de caractères ’s’ sur le 
// descripteur de fichier donné suivie d’un retour à la ligne.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
