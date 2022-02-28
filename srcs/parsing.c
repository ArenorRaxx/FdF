/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:24:43 by mcorso            #+#    #+#             */
/*   Updated: 2022/02/28 04:35:41 by mcorso           ###   ########.fr       */
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

static void	null_ending(char **line)
{
	int	i;

	i = 0;
	while (line[0][i] != '\n')
		i++;
	line[0][i] = '\0';
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
		null_ending(&line);
		curr_node = add_node(curr_node, new_node(line));
		line = get_next_line(fd);
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
			map->parsed_map[y][x].x = (WIDTH / 2) + (x - y) * map->tw;
			map->parsed_map[y][x].y = (x + y) * map->th - (2 * z);
		}
		double_tab_free(&tmp);
		curr_node = curr_node->next;
	}
}