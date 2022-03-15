/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:39:03 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/15 02:33:29 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int	text_manager(t_env *env)
{
	char	*nb;

	nb = ft_itoa(env->map.amp);
	if (!nb)
	{
		perror("FDF");
		env_destroy(env);
	}
	mlx_string_put(env->vars.mlx, env->vars.win, 3, 9, 0xFF0000, nb);
	free(nb);
	return (0);
}

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
	mlx_do_key_autorepeaton(env.vars.mlx);
	draw_map_to_img(&env.img, &env.map);
	mlx_put_image_to_window(env.vars.mlx, env.vars.win, env.img.img, 0, 0);
	mlx_loop(env.vars.mlx);
}
