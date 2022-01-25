/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:04:11 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/01 19:13:19 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret_pointer;
	size_t	size_pref;
	size_t	size_suff;

	size_pref = ft_strlen(s1) + 1;
	size_suff = ft_strlen(s2) + 1;
	ret_pointer = (char *)malloc((size_suff + size_pref) * sizeof(char));
	if (!ret_pointer)
		return (NULL);
	ft_strlcpy(ret_pointer, s1, size_pref);
	ft_strlcat(ret_pointer, s2, size_pref + size_suff);
	return (ret_pointer);
}
