/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:50:06 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/02 17:14:34 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*		Defines		*/
# define WIDTH 1920
# define HEIGHT 1080
# ifdef __APPLE__
#  define ESCAPE_KEY 53
# endif
# ifdef __linux__
#  define ESCAPE_KEY 65307
# endif


/*		Includes	*/
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./external/mlx_linux/mlx.h"
# include "./external/gnl/get_next_line.h"
# include "./external/libft/libft.h"

/*		Mapping		*/
struct	s_point;

typedef struct s_coord {
	char	*line;
	void	*next;
}				t_coord;

typedef struct s_map {
	int				width;
	int				height;
	int				offset;
	int				lowest;
	int				highest;
	int				amp;
	int				tw;
	int				th;
	t_coord			*map;
	struct s_point	**parsed_map;
}				t_map;

// Basics
void	print_map(t_coord *first_node);
t_coord	*new_node(char *str);
t_coord	*add_node(t_coord *prev_node, t_coord *new_node);
// Managing
void	manage_map(t_map *map, char *file);
// Parsing
int		line_length(char **split);
void	parsing_points(t_map *map);
void	parsing_file(int fd, t_map *map);
void	double_tab_free(char ***tab);

/*	Window managing	*/
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		win_destroy(t_vars *vars);
int		win_close(int keycode, t_vars *vars);
void	win_init(t_vars *vars);
void	hook_setup(t_vars *vars);

/*	Image managing	*/
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	img_init(t_img *img, t_vars vars);

/*	Drawing	*/
typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_line {
	t_point	d1;
	t_point	d2;
}				t_line;

void	draw_map_to_img(t_img *img, t_map *map);
void	put_pixel(t_img *img, int x, int y, int color);
void	low_plot(t_img *img, t_point p0, t_point p1, int color);
void	high_plot(t_img *img, t_point p0, t_point p1, int color);
void	draw_line(t_img *img, t_line line, int color);

static inline void	fill_line(t_point *point, t_map map, int x, int y)
{
	point->x = map.parsed_map[y][x].x;
	point->y = map.parsed_map[y][x].y;
}

#endif
