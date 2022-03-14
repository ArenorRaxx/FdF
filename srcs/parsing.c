/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:24:43 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/14 17:46:11 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	parsing_file(int fd, t_map *map)
{
	char	*line;
	char	**split;
	t_coord	*curr_node;

	split = ft_split(get_next_line(fd), ' ');
	if (!split)
		return (-1);
	curr_node = new_node(split, map->map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (add_node(curr_node, line) < 0)
			return (-1);
		curr_node = curr_node->next;
	}
	close(fd);
	return (0);
}

static void	calc_xy(t_map *map, char **row, int x, int y)
{
	int	xa;
	int	ya;
	int	z;
	int	scale;

	z = ft_atoi(row[x]);
	xa = (x - y) * map->tw + map->offset;
	ya = (x + y) * map->th - (map->amp * z);
	ya -= map->highest;
	scale = abs(map->highest) + abs(map->lowest);
	map->parsed_map[y][x].x = xa;
	map->parsed_map[y][x].y = (ya * HEIGHT) / scale;
}

static int	malloc_map(t_map *map)
{
	int	y;

	y = 0;
	if (!map->parsed_map)
	{
		map->parsed_map = malloc(sizeof(map->parsed_map) * map->height);
		if (!map->parsed_map)
			return (-1);
		while (y < map->height)
		{
			map->parsed_map[y] = malloc(sizeof(**map->parsed_map) * map->width);
			if (!map->parsed_map[y++])
			{
				while (y >= 0)
					free(map->parsed_map[--y]);
				free(map->parsed_map);
				return (-1);
			}
		}
	}
	return (0);
}

int	parsing_points(t_map *map)
{
	int			x;
	int			y;
	t_coord		*curr_node;

	y = 0;
	curr_node = map->map;
	if (malloc_map(map) < 0)
		return (-1);
	while (curr_node)
	{
		x = 0;
		while (curr_node->line[x])
			calc_xy(map, curr_node->line, x++, y);
		curr_node = curr_node->next;
		y++;
	}
	return (0);
}
