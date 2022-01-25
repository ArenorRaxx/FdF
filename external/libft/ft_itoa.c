/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 04:47:15 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/03 15:52:59 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_many_digits(int n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		nbcar;
	char	*int_ret;
	long	num;

	num = (long)n;
	sign = 1;
	nbcar = 0;
	nbcar = how_many_digits(n);
	if (n < 0)
		sign *= -1;
	int_ret = (char *)ft_calloc(nbcar + 1, sizeof(char));
	if (n == 0)
		int_ret[0] = '0';
	if (!int_ret)
		return (NULL);
	while (nbcar && n)
	{
		int_ret[--nbcar] = ((num * sign) % 10) + '0';
		num /= 10;
	}
	if (sign < 0)
		int_ret[nbcar] = '-';
	return (int_ret);
}
