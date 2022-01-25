/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:44:25 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/26 20:58:45 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	char			patt;
	int				len;

	len = ft_strlen(s);
	patt = (char)c;
	str = (char *)s;
	while (len >= 0)
		if (str[len--] == patt)
			return (&str[len + 1]);
	return (NULL);
}
