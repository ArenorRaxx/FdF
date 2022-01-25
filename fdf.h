/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:50:06 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/25 12:30:51 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Defines
# define WIDTH 1920
# define HEIGHT 1080

// Includes
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./external/mlx_linux/mlx.h"
# include "./external/gnl/get_next_line.h"

// Coords struct
typedef struct s_coord {
	int		index;
	char	*line;
	void	*next;
}				t_coord;

void	print_map(t_coord *first_node);
t_coord	*new_node(char *str, int index);
t_coord	*add_node(t_coord *prev_node, t_coord *new_node);

// Parsing
t_coord	*parsing_file(int fd);

// Window struct
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		win_destroy(t_vars *vars);
int		win_close(int keycode, t_vars *vars);
void	win_init(t_vars *vars);
void	hook_setup(t_vars *vars);

// Image struct
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	put_pixel(t_img *img, int x, int y, int color);

#endif
