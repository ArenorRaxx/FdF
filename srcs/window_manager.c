/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:00 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/13 15:50:23 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	win_init(t_env *env)
{
	env->vars.mlx = mlx_init();
	if (!env->vars.mlx)
		return (-1);
	env->vars.win = mlx_new_window(env->vars.mlx, WIDTH, HEIGHT, "FdF");
	if (!env->vars.win)
		return (-1);
	hook_setup(env);
	return (0);
}
