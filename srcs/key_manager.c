/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:18:44 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/24 17:18:41 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	win_close(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	win_destroy(t_vars *vars)
{
	(void)vars;
	exit(0);
}