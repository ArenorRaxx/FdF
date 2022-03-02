/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:17:00 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/02 17:38:27 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	win_init(t_vars *vars)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF");
	vars->mlx = mlx;
	vars->win = win;
	hook_setup(vars);
}

void	hook_setup(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, win_close, &vars);
	mlx_hook(vars->win, 17, 0, win_destroy, &vars);
}

int	win_close(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == ESCAPE_KEY)
		exit(0);
	return (0);
}

int	win_destroy(t_vars *vars)
{
	(void)vars;
	exit(0);
}
