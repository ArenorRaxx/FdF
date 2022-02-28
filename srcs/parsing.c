/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:24:43 by mcorso            #+#    #+#             */
/*   Updated: 2022/02/28 21:07:48 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	double_tab_free(char ***tab)
{
	int	i;

	i = 0;
	while (tab[0][i] != NULL)
		free(tab[0][i++]);
	free(*tab);
}

void	parsing_file(int fd, t_map *map)
{
	char	*line;
	t_coord	*curr_node;

	line = get_next_line(fd);
	if (!line)
		return ;
	map->map = new_node(line);
	curr_node = map->map;
	while (line)
	{
		line = get_next_line(fd);
		curr_node = add_node(curr_node, new_node(line));
	}
	close(fd);
}

void	parsing_points(t_map *map)
{
	int			x;
	int			y;
	int			z;
	char		**tmp;
	t_coord		*curr_node;

	x = 0;
	y = -1;
	curr_node = map->map;
	map->parsed_map = malloc(sizeof(*map->parsed_map) * map->height);
	while (x < map->height)
		map->parsed_map[x++] = malloc(sizeof(**map->parsed_map) * map->width);
	while (++y < map->height)
	{
		x = -1;
		tmp = ft_split(curr_node->line, ' ');
		while (++x < map->width)
		{
			z = ft_atoi(tmp[x]);
			map->parsed_map[y][x].x = (x - y) * map->tw + (WIDTH / 2);
			map->parsed_map[y][x].y = (x + y) * map->th - (1 * z);
		}
		double_tab_free(&tmp);
		curr_node = curr_node->next;
	}
}