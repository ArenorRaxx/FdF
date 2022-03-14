/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:39:03 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/14 17:20:56 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		return (0);
	if (env_init(&env, argv) < 0)
	{
		perror("FDF");
		env_destroy(&env);
	}
	draw_map_to_img(&env.img, &env.map);
	mlx_put_image_to_window(env.vars.mlx, env.vars.win, env.img.img, 0, 0);
	mlx_loop(env.vars.mlx);
}
