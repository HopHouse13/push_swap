/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:56:42 by pbret             #+#    #+#             */
/*   Updated: 2024/05/22 13:40:51 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_tempo;
	unsigned char	*dest_tempo;

	src_tempo = (unsigned char *)src;
	dest_tempo = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (n--)
		dest_tempo[n] = src_tempo[n];
	return (dest);
}
