/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:16:47 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/14 17:20:46 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	env_init(t_env *env, char **argv)
{
	env->vars.mlx = NULL;
	env->vars.win = NULL;
	env->img.img = NULL;
	if (map_init(&env->map, argv[1]) < 0)
		return (-1);
	if (win_init(env) < 0)
		return (-1);
	if (img_init(&env->img, env->vars) < 0)
		return (-1);
	return (0);
}

int	env_destroy(t_env *env)
{
	write(1, "map\n", 4);
	if (env->map.map)
		del_chain(env->map.map);
	write(1, "parsed map\n", 11);
	if (env->map.parsed_map)
		free_parsed_map(&env->map);
	write(1, "img\n", 4);
	if (env->img.img)
		mlx_destroy_image(env->vars.mlx, env->img.img);
	write(1, "mlx & win\n", 10);
	if (env->vars.mlx && env->vars.win)
		mlx_destroy_window(env->vars.mlx, env->vars.win);
	write(1, "mlx\n", 4);
	if (env->vars.mlx)
	{
		mlx_destroy_display(env->vars.mlx);
		free(env->vars.mlx);
	}
	exit(0);
}
