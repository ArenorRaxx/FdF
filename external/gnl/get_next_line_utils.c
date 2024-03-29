/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:55:31 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/26 01:25:32 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	chr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*join(char *s1, char *s2)
{
	int		i;
	char	*ret_pointer;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ret_pointer = malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (!ret_pointer)
		return (NULL);
	while (s1[i])
	{
		ret_pointer[i] = s1[i];
		i++;
	}
	while (*s2)
		ret_pointer[i++] = *s2++;
	ret_pointer[i] = '\0';
	free(s1);
	return (ret_pointer);
}
