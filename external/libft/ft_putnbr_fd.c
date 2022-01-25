/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:28:24 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/30 21:59:01 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	ft_pow(unsigned int value, unsigned int power)
{
	if (power)
		return (value * ft_pow(value, --power));
	return (1);
}

static int	how_many_digits(long n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	long			num;

	num = n;
	if (num == 0)
		ft_putchar_fd('0', fd);
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	i = how_many_digits(num);
	while (i > 0)
		ft_putchar_fd(((num / ft_pow(10, --i)) % 10) + '0', fd);
}
