/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:45:34 by mcorso            #+#    #+#             */
/*   Updated: 2022/02/28 02:12:40 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coord	*new_node(char *str)
{
	t_coord	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (0);
	new_node->line = str;
	new_node->next = NULL;
	return (new_node);
}

t_coord	*add_node(t_coord *prev_node, t_coord *new_node)
{
	if (prev_node)
		prev_node->next = new_node;
	return (new_node);
}

void	print_map(t_coord *first_node)
{
	t_coord	*curr_node;

	curr_node = first_node;
	while (curr_node)
	{
		printf("%s", curr_node->line);
		curr_node = curr_node->next;
	}
}