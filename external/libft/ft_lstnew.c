/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:40:01 by mcorso            #+#    #+#             */
/*   Updated: 2021/11/30 23:10:05 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cur_nod;

	cur_nod = (t_list *)malloc(sizeof(t_list));
	if (!cur_nod)
		return (NULL);
	cur_nod->content = content;
	cur_nod->next = NULL;
	return (cur_nod);
}
