/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:39:03 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/04 21:31:11 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		return (0);
	map_init(&env.map, argv[1]);
	printf("width : %i ; height : %i\n", env.map.width, env.map.height);
	win_init(&env);
	img_init(&env.img, env.vars);
	draw_map_to_img(&env.img, &env.map);
	mlx_put_image_to_window(env.vars.mlx, env.vars.win, env.img.img, 0, 0);
	mlx_loop(env.vars.mlx);
}
