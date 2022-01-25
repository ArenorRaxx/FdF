/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:45:47 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/25 16:08:31 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_img *img, t_point p0, t_point p1, int color)
{
	int	y;
	int	x;
	int	dx;
	int	dy;
	int	delta;

	y = p0.x;
	x = p0.y;
	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	delta = 2 * dy - dx;
	while (x != p1.x)
	{
		put_pixel(img, x, y, color);
		if (delta > 0)
		{
			y += 1;
			delta -= 2 * dx;
		}
		delta += 2 * dy;
		x++;
	}
}