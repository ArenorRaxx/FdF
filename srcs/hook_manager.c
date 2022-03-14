/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:18:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/14 17:17:46 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	hook_setup(t_env *env)
{
	mlx_key_hook(env->vars.win, hook_manage_key, env);
	mlx_hook(env ->vars.win, 17, 0, env_destroy, env);
}

int	hook_manage_key(int keycode, t_env *env)
{
	(void)env;
	if (keycode == KEY_ESC)
		env_destroy(env);
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
