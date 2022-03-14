/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:41:41 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/14 17:44:38 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ruler(t_map *map)
{
	t_coord	*node;

	node = map->map;
	while (node->line[++map->width])
		;
	while (node)
	{
		node = node->next;
		map->height++;
	}
	define_tile_measurement(map);
	return (0);
}

static int	high_low(t_map *map)
{
	int			x;
	int			y;
	int			height;
	t_coord		*curr_node;

	y = 0;
	curr_node = map->map;
	while (curr_node)
	{
		x = 0;
		while (curr_node->line[x])
		{
			height = ft_atoi(curr_node->line[x]);
			height = (x + y) * map->th - (map->amp * height);
			if (height < map->highest)
				map->highest = height;
			else if (height > map->lowest)
				map->lowest = height;
			x++;
		}
		curr_node = curr_node->next;
		y++;
	}
	return (0);
}

int	map_load(t_map *map, char *file)
{
	int	fd;

	if (file)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			return (-1);
		if (parsing_file(fd, map) < 0)
		{
			close(fd);
			return (-1);
		}
		ruler(map);
	}
	if (high_low(map) < 0)
		return (-1);
	if (parsing_points(map) < 0)
		return (-1);
	return (0);
}

int	map_init(t_map *map, char *file)
{
	map->width = -1;
	map->height = 0;
	map->offset = 0;
	map->lowest = 0;
	map->highest = 0;
	map->amp = 1;
	map->tw = 0;
	map->th = 0;
	map->map = malloc(sizeof(*map->map));
	map->parsed_map = NULL;
	if (!map->map)
		return (-1);
	if (map_load(map, file) < 0)
		return (-1);
	return (0);
}
