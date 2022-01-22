/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:39:03 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/22 06:13:31 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_circle(t_data *data, int x, int y, int rad)
{
	int	i;
	int	j;

	i = y;
	while (i < rad + y)
	{
		j = x;
		while (j != (i - y) + x)
		{
			my_mlx_pixel_put(data, j, i, 0x00FF0000 - (0x00010000 * j) + (0x00000100 * j));
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	put_circle(&img, 500, 500, 500);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
