/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:50:06 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/15 02:24:10 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*		Defines		*/
# define WIDTH 1920
# define HEIGHT 1000
# ifdef __APPLE__
#  define ESCAPE_KEY 53
# endif
# ifdef __linux__
#  define KEY_UP 65362
#  define KEY_ESC 65307
#  define KEY_DOWN 65364
# endif

/*		Includes	*/
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./external/mlx_linux/mlx.h"
# include "./external/gnl/get_next_line.h"
# include "./external/libft/libft.h"

/*		Mapping		*/
struct	s_point;

typedef struct s_coord {
	char			**line;
	struct s_coord	*next;
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
int		add_node(t_coord *prev_node, char *line);
void	del_chain(t_coord *map);
void	print_map(t_coord *first_node);
t_coord	*new_node(char **line, t_coord *node);
// Managing
int		map_init(t_map *map, char *file);
int		map_load(t_map *map, char *file);
// Parsing
int		line_length(char **split);
int		parsing_points(t_map *map);
int		parsing_file(int fd, t_map *map);

static inline int	mini(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static inline void	free_parsed_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
		free(map->parsed_map[y++]);
	free(map->parsed_map);
}

static inline void	define_tile_measurement(t_map *map)
{
	int	n;
	int	m;
	int	dia;

	n = mini(map->width, map->height);
	m = map->width - map->height;
	dia = 2 * n + abs(m);
	map->tw = WIDTH / dia;
	map->th = HEIGHT / dia;
	map->offset = (WIDTH - map->tw * m) / 2;
}

/*		Window managing		*/
struct	s_env;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		win_init(struct s_env *env);
int		hook_manage_key(int keycode, struct s_env *env);
void	hook_setup(struct s_env *env);

/*		Image managing		*/
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

int		img_init(t_img *img, t_vars vars);
void	img_reload(struct s_env *env);

/*		Drawing		*/
typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_line {
	t_point	d1;
	t_point	d2;
}				t_line;

typedef struct s_color {
	char	r;
	char	g;
	char	b;
}				t_color;

typedef struct s_fading {
	t_color	from;
	t_color	to;
}				t_fading;

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

/*		Env		*/
typedef struct s_env {
	t_img	img;
	t_map	map;
	t_vars	vars;
}				t_env;

int		env_destroy(t_env *env);
int		text_manager(t_env *env);
int		env_init(t_env *env, char **argv);

#endif
