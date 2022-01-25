/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:41:03 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/29 14:36:56 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	patt;
	unsigned char	*str;

	patt = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == patt)
			return (str);
		str++;
	}
	return (NULL);
}
