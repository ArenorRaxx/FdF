/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:14:37 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/27 17:48:53 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_isblank(const char *src)
{
	unsigned char	*str;

	str = (unsigned char *)src;
	while ((*str <= '\r' && *str >= '\t') || *str == ' ')
		str++;
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long		ret_val;
	char		*src;

	sign = 1;
	ret_val = 0;
	src = ft_isblank(str);
	if (*src == '-' || *src == '+')
		if (*src++ == '-')
			sign *= -1;
	if (!ft_strncmp(src, "99999999999999999999999999", 26))
	{
		if (sign < 0)
			return (0);
		return (-1);
	}
	while (*src >= '0' && *src <= '9')
		ret_val = (ret_val * 10) + *src++ - 48;
	return ((int)(ret_val * sign));
}
