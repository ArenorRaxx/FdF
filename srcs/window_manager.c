/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:00 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/04 23:36:02 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	win_init(t_env *env)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF");
	env->vars.mlx = mlx;
	env->vars.win = win;
	hook_setup(env);
}

void	hook_setup(t_env *env)
{
	mlx_key_hook(env->vars.win, win_close, env);
	mlx_hook(env ->vars.win, 17, 0, win_destroy, env);
}

int	win_close(int keycode, t_env *env)
{
	(void)env;
	if (keycode == KEY_ESC)
		win_destroy(env);
	return (0);
}

int	win_destroy(t_env *env)
{
	del_chain(env->map.map);
	free_parsed_map(&env->map);
	mlx_destroy_image(env->vars.mlx, env->img.img);
	mlx_destroy_window(env->vars.mlx, env->vars.win);
	mlx_destroy_display(env->vars.mlx);
	free(env->vars.mlx);
	exit(0);
}
