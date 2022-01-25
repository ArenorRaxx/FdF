/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:02:57 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/27 18:12:46 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_pointer;
	size_t	amount;

	amount = count * size;
	ret_pointer = malloc(amount);
	if (!ret_pointer)
		return (NULL);
	ft_bzero(ret_pointer, amount);
	return (ret_pointer);
}
