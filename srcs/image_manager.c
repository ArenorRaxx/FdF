/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:38:51 by mcorso            #+#    #+#             */
/*   Updated: 2022/02/28 05:18:19 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_init(t_img *img, t_vars vars)
{
	img->img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}

void	draw_map_to_img(t_img *img, t_map *map)
{
	int		x;
	int		y;
	t_line	line;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			line.d1.x = map->parsed_map[y][x].x;
			line.d1.y = map->parsed_map[y][x].y;
			if (x != map->width - 1)
			{
				line.d2.x = map->parsed_map[y][x + 1].x;
				line.d2.y = map->parsed_map[y][x + 1].y;
				draw_line(img, line, 0x00FF0000);
			}
			if (y != map->height - 1)
			{
				line.d2.x = map->parsed_map[y + 1][x].x;
				line.d2.y = map->parsed_map[y + 1][x].y;
				draw_line(img, line, 0x00FF0000);
			}
			x++;
		}
		y++;
	}
}