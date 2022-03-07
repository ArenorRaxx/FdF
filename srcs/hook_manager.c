/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:18:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/07 11:39:43 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	else
	{
		if (keycode == KEY_UP)
			env->map.amp++;
		else
			env->map.amp--;
		img_reload(env);
	}
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
