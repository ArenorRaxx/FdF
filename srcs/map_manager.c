/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:41:41 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/07 12:20:57 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ruler(t_map *map, char *file)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		return ;
	}
	line = get_next_line(fd);
	map->height++;
	split = ft_split(line, ' ');
	while (split[++map->width])
		;
	while (line)
	{
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	define_tile_measurement(map);
	close(fd);
	return (free(line), double_tab_free(&split));
}

static void	high_low(t_map *map)
{
	int			x;
	int			y;
	int			height;
	char		**tmp;
	t_coord		*curr_node;

	y = 0;
	curr_node = map->map;
	while (y < map->height)
	{
		x = -1;
		tmp = ft_split(curr_node->line, ' ');
		while (++x < map->width)
		{
			height = ft_atoi(tmp[x]);
			height = (x + y) * map->th - (map->amp * height);
			if (height < map->highest)
				map->highest = height;
			else if (height > map->lowest)
				map->lowest = height;
		}
		curr_node = curr_node->next;
		double_tab_free(&tmp);
		y++;
	}
}

void	map_load(t_map *map, char *file)
{
	int	fd;

	if (file)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			return (perror(NULL));
		ruler(map, file);
	}
	else
		fd = 0;
	if (!map->map)
		parsing_file(fd, map);
	high_low(map);
	parsing_points(map);
	close (fd);
}

void	map_init(t_map *map, char *file)
{
	map->tw = 0;
	map->th = 0;
	map->amp = 1;
	map->map = NULL;
	map->parsed_map = NULL;
	map->highest = 0;
	map->lowest = 0;
	map->width = -1;
	map->height = -1;
	map_load(map, file);
}
