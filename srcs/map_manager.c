/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:41:41 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/01 00:14:37 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	mini(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static void	define_tile_measurement(t_map *map)
{
	int	n;
	int	m;
	int	dia;

	n = mini(map->width, map->height);
	m = map->width - map->height;
	dia = 2 * n + abs(m);
	map->tw = WIDTH / dia;
	map->th = HEIGHT / dia;
	map->offset = (WIDTH - map->tw * m) / 2;
	printf("tw %i, th %i\n", map->tw, map->th);
}

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
