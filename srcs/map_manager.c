/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:41:41 by mcorso            #+#    #+#             */
/*   Updated: 2022/02/28 04:37:40 by mcorso           ###   ########.fr       */
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
	map->tw = WIDTH / (2 * map->width);
	map->th = HEIGHT / (2 * map->height) / 2;
	close(fd);
	return (free(line), double_tab_free(&split));
}

void	manage_map(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		return ;
	}
	map->tw = 0;
	map->th = 0;
	map->width = -1;
	map->height = -1;
	ruler(map, file);
	parsing_file(fd, map);
	parsing_points(map);
	close(fd);
}
