/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:26:37 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/01 19:03:02 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	pretty_func(size_t slen, size_t len)
{
	if (slen < len)
		return (slen + 1);
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	char	*ret_pointer;
	size_t	slen;
	size_t	size;

	src = (char *)s;
	if (!src)
		return (NULL);
	slen = ft_strlen(src);
	if (slen < start)
		return ((char *)ft_calloc(sizeof(char), 1));
	size = pretty_func(slen, len);
	ret_pointer = (char *)ft_calloc(size, sizeof(char));
	if (!ret_pointer)
		return (NULL);
	ft_strlcpy(ret_pointer, src + start, size);
	return (ret_pointer);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *s= ft_substr("tripouille", 0, 42000);
// 	printf("%s\n", s);
// }