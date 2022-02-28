/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:39:03 by mcorso            #+#    #+#             */
/*   Updated: 2022/02/28 05:18:17 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	//int 	x;
	//int		y = 0;
	t_img	img;
	t_map	map;
	t_vars	vars;

	if (argc != 2)
		return (0);
	manage_map(&map, argv[1]);
	win_init(&vars);
	img_init(&img, vars);
	draw_map_to_img(&img, &map);
	/*
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			printf("y : %i ", map.parsed_map[y][x].y);
			put_pixel(&img, map.parsed_map[y][x].x, map.parsed_map[y][x].y, 0x00FF0000);
			x++;
		}
		putchar('\n');
		y++;
	}*/
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
