/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:45:34 by mcorso            #+#    #+#             */
/*   Updated: 2022/05/17 16:12:29 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coord	*new_node(char **line, t_coord *node)
{
	node->line = line;
	node->next = NULL;
	return (node);
}

int	add_node(t_coord *prev_node, char *line)
{
	char	**split;

	split = NULL;
	prev_node->next = malloc(sizeof(*prev_node));
	if (!prev_node->next)
	{
		free(line);
		return (-1);
	}
	split = ft_split(line, ' ');
	if (!split)
	{
		free(line);
		return (-1);
	}
	new_node(split, prev_node->next);
	return (0);
}

void	del_chain(t_coord *map)
{
	int		x;
	t_coord	*curr_node;

	while (map)
	{
		x = 0;
		curr_node = map;
		while (curr_node->line[x])
			free(curr_node->line[x++]);
		map = map->next;
		free(curr_node->line);
		free(curr_node);
	}
}
