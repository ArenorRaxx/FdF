/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:24:43 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/24 20:32:59 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coord	*parsing_file(int fd)
{
	int		i;
	char	*line;
	t_coord	*curr_node;
	t_coord	*first_node;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	first_node = new_node(line, i++);
	curr_node = first_node;
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break ;
		curr_node = add_node(curr_node, new_node(line, i++));
	}
	return (first_node);
}