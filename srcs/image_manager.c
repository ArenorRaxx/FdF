/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:38:51 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/10 17:02:13 by mcorso           ###   ########.fr       */
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

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			fill_line(&line.d1, *map, x, y);
			if (x != map->width - 1)
			{
				fill_line(&line.d2, *map, x + 1, y);
				draw_line(img, line, 0xFF0000);
			}
			if (y != map->height - 1)
			{
				fill_line(&line.d2, *map, x, y + 1);
				draw_line(img, line, 0xFF0000);
			}
		}
	}
}

static void	undraw_map(t_img *img, t_map *map)
{
	int		x;
	int		y;
	t_line	line;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			fill_line(&line.d1, *map, x, y);
			if (x != map->width - 1)
			{
				fill_line(&line.d2, *map, x + 1, y);
				draw_line(img, line, 0x000000);
			}
			if (y != map->height - 1)
			{
				fill_line(&line.d2, *map, x, y + 1);
				draw_line(img, line, 0x000000);
			}
		}
	}
}

void	img_reload(t_env *env)
{
	env->map.highest = 0;
	env->map.lowest = 0;
	undraw_map(&env->img, &env->map);
	map_load(&env->map, NULL);
	draw_map_to_img(&env->img, &env->map);
	mlx_put_image_to_window(env->vars.mlx, env->vars.win, env->img.img, 0, 0);
}
