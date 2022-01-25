/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:55:38 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/01 16:04:51 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cur_node;

	i = 0;
	while (lst != NULL)
	{
		cur_node = lst;
		lst = (t_list *) cur_node->next;
		i++;
	}
	return (i);
}
