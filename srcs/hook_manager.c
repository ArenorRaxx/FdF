/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:18:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/05/17 17:05:04 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	hook_setup(t_env *env)
{
	mlx_hook(env->vars.win, 2, 1L << 0, hook_manage_key, env);
	mlx_hook(env ->vars.win, 17, 0, env_destroy, env);
	mlx_loop_hook(env->vars.mlx, text_manager, env);
}

int	hook_manage_key(int keycode, t_env *env)
{
	int	inc;

	inc = 0;
	if (keycode == KEY_ESC)
		env_destroy(env);
	else
	{
		if (keycode == KEY_UP)
			inc = 1;
		else if (keycode == KEY_DOWN)
			inc = -1;
		env->map.amp += inc;
		env->map.amp = env->map.amp % 500;
		img_reload(env);
	}
	return (0);
}
