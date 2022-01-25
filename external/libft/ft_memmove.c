/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:21:38 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/26 19:24:54 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*dest;

	str = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dest < str)
	{
		while (len--)
			*dest++ = *str++;
	}
	else if (dest > str)
	{
		str += len - 1;
		dest += len - 1;
		while (len--)
			*dest-- = *str--;
	}
	return (dst);
}
