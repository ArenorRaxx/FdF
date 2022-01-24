/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:50:06 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/24 17:57:32 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./external/mlx_linux/mlx.h"
# include "./external/gnl/get_next_line.h"

//Coords struct
typedef struct s_coord {
	int		index;
	char	*line;
	void	*next;
}				t_coord;

t_coord	*new_node(char *str, int index);

//Window struct
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		win_destroy(t_vars *vars);
int		win_close(int keycode, t_vars *vars);

#endif
