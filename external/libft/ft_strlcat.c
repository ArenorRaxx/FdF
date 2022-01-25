/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:50:31 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/01 20:42:48 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;
	size_t	dsize;

	dsize = ft_strlen(dst);
	i = dsize;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < dsize)
		return (dstsize + ft_strlen(src));
	s = 0;
	if (dstsize > i)
	{
		while (src[s] && dstsize - i > 1)
		{
			dst[i] = src[s];
			i++;
			s++;
		}
	}
	dst[i] = '\0';
	while (src[s] != '\0')
		s++;
	return (dsize + s);
}
