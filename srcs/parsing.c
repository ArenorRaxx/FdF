/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:24:43 by mcorso            #+#    #+#             */
/*   Updated: 2022/02/27 23:31:19 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	parsing_file(int fd, t_map *map)
{
	int		i;
	char	*line;
	t_coord	*curr_node;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return ;
	map->map = new_node(line, i++);
	curr_node = map->map;
	while (line)
	{
		line = get_next_line(fd);
		curr_node = add_node(curr_node, new_node(line, i++));
	}
	close(fd);
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
	map->parsed_map = malloc(sizeof(*map->parsed_map) * map->height);
	while (x < map->height)
		map->parsed_map[x++] = malloc(sizeof(**map->parsed_map) * map->width);
	while (y < map->height)
	{
		x = 0;
		tmp = ft_split(curr_node->line, ' ');
		while (x < map->width)
		{
			map->parsed_map[y][x].x = x;
			map->parsed_map[y][x].y = y;
			map->parsed_map[y][x].z = ft_atoi(tmp[x]);
			x++;
		}
		free(tmp);
		y++;
	}
}

t_point	*to_2d(t_3Dpoint **map)
{
}