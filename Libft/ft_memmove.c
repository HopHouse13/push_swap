/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:36:08 by pbret             #+#    #+#             */
/*   Updated: 2024/05/23 12:15:38 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_tempo;
	unsigned char	*dest_tempo;
	unsigned int	i;

	src_tempo = (unsigned char *)src;
	dest_tempo = (unsigned char *)dest;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (dest > src)
		while (n--)
			dest_tempo[n] = src_tempo[n];
	else
	{
		while (i < n)
		{
			dest_tempo[i] = src_tempo[i];
			i++;
		}
	}
	return (dest);
}
