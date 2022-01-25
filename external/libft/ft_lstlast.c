/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:07:49 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/01 15:38:38 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur_nod;

	if (lst == NULL)
		return (lst);
	while (lst != NULL)
	{
		cur_nod = lst;
		lst = (t_list *)cur_nod->next;
	}
	return (cur_nod);
}
