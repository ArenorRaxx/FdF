/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:48:04 by mcorso            #+#    #+#             */
/*   Updated: 2021/12/01 15:23:19 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*ret_list;

	ret_list = (t_list *)malloc(sizeof(t_list));
	if (!ret_list)
		return (NULL);
	cur_node = ret_list;
	while (lst != NULL)
	{
		cur_node->content = f(lst->content);
		lst = lst->next;
		if (lst != NULL)
		{
			cur_node->next = (t_list *)malloc(sizeof(t_list));
			if (cur_node->content == NULL || cur_node->next == NULL)
			{
				ft_lstclear(&ret_list, del);
				return (NULL);
			}
			cur_node = cur_node->next;
		}
		else
			cur_node->next = NULL;
	}
	return (ret_list);
}
