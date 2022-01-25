/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:14:02 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/27 18:23:38 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret_pointer;
	size_t	str_size;

	str_size = ft_strlen(s1) + 1;
	ret_pointer = (char *)ft_calloc(str_size, sizeof(char));
	if (!ret_pointer)
		return (NULL);
	ft_strlcpy(ret_pointer, s1, str_size);
	return (ret_pointer);
}
