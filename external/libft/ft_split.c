/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:54:04 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/10 12:31:43 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nword(const char *src, char c)
{
	int	i;
	int	nword;

	if (!*src)
		return (0);
	i = 0;
	nword = 0;
	while (src[i] && src[i] == c)
		i++;
	while (src[i])
	{
		if (src[i] == c)
		{
			nword++;
			while (src[i] && src[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (src[i - 1] != c)
		nword++;
	return (nword);
}

static int	wlen(const char *src, char c)
{
	int	len;

	len = 0;
	while (src[len] != c && src[len] != '\0')
		len++;
	return (len);
}

static char	**freed(char **src, int index)
{
	while (index > 0)
		free(src[--index]);
	free(src);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		nwords;
	char	**strs;

	i = 0;
	j = 0;
	nwords = nword(s, c);
	strs = malloc(sizeof(*strs) * (nwords + 1));
	if (!strs)
		return (NULL);
	while (i < nwords)
	{
		while (s[j] == c)
			j++;
		strs[i] = malloc(sizeof(**strs) * (wlen((s + j), c) + 1));
		if (!strs[i])
			return (freed(strs, i));
		ft_strlcpy(*(strs + i++), (s + j), wlen((s + j), c) + 1);
		j += wlen((s + j), c);
	}
	strs[i] = NULL;
	return (strs);
}
