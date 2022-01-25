/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:28:37 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/26 21:34:42 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*str;
	unsigned char	*dest;
	size_t			len;

	len = ft_strlen(src);
	str = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dstsize)
	{
		while (dstsize-- > 1 && *str)
			*dest++ = *str++;
		*dest = '\0';
	}
	return (len);
}
