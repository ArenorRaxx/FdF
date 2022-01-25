/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:09 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/30 17:53:18 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;
	char	*ret_str;

	str = (char *)s;
	len = ft_strlen(str);
	ret_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret_str)
		return (NULL);
	while (len--)
		ret_str[len] = f(len, str[len]);
	return (ret_str);
}
