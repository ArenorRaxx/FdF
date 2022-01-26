/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:38:51 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/26 01:31:06 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_init(t_img *img, t_vars vars)
{
	img->img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}

void	draw_map_to_img(t_img *img, t_coord *map)
{
	int		i;
	int		len;
	char	**tmp;
	t_coord	*curr_node;

	curr_node = map;
	while (curr_node)
	{
		i = 0;
		tmp = ft_split(curr_node->line, ' ');
		len = line_length(tmp);
		while (tmp[i])
		{
			put_pixel(img, WIDTH / len * i, \
			HEIGHT / len * curr_node->index, \
			0x00FF0000);
			i++;
		}
		curr_node = curr_node->next;
	}
}