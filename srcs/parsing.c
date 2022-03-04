/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:24:43 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/04 23:27:58 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

void	parsing_points(t_map *map)
{
	int			x;
	int			y;
	char		**tmp;
	t_coord		*curr_node;

	x = 0;
	y = 0;
	curr_node = map->map;
	map->parsed_map = malloc(sizeof(map->parsed_map) * map->height);
	while (x < map->height)
		map->parsed_map[x++] = malloc(sizeof(**map->parsed_map) * map->width);
	while (y < map->height)
	{
		x = 0;
		tmp = ft_split(curr_node->line, ' ');
		while (x < map->width)
			calc_xy(map, tmp, x++, y);
		double_tab_free(&tmp);
		curr_node = curr_node->next;
		y++;
	}
}
