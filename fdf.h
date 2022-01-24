/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:50:06 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/24 13:24:27 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "./external/mlx_linux/mlx.h"
# include "./external/gnl/get_next_line.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	win_close(int keycode, t_vars *vars);

#endif
