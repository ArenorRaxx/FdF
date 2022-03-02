/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:45:47 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/02 17:38:37 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_img *img, t_line line, int color)
{
	t_point	p0;
	t_point	p1;

	p0 = line.d1;
	p1 = line.d2;
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			low_plot(img, p1, p0, color);
		else
			low_plot(img, p0, p1, color);
	}
	else
	{
		if (p0.y > p1.y)
			high_plot(img, p1, p0, color);
		else
			high_plot(img, p0, p1, color);
	}
}

void	low_plot(t_img *img, t_point p0, t_point p1, int color)
{
	int		big_d;
	int		y_inc;
	t_point	delta;

	y_inc = 1;
	delta.x = p1.x - p0.x;
	delta.y = p1.y - p0.y;
	if (delta.y < 0)
	{
		y_inc *= -1;
		delta.y *= -1;
	}
	big_d = (2 * delta.y) - delta.x;
	while (p0.x != p1.x)
	{
		put_pixel(img, p0.x, p0.y, color);
		if (big_d > 0)
		{
			p0.y += y_inc;
			big_d -= 2 * delta.x;
		}
		big_d += 2 * delta.y;
		p0.x++;
	}
}

void	high_plot(t_img *img, t_point p0, t_point p1, int color)
{
	int		big_d;
	int		x_inc;
	t_point	delta;

	x_inc = 1;
	delta.x = p1.x - p0.x;
	delta.y = p1.y - p0.y;
	if (delta.x < 0)
	{
		x_inc *= -1;
		delta.x *= -1;
	}
	big_d = (2 * delta.x) - delta.y;
	while (p0.y != p1.y)
	{
		put_pixel(img, p0.x, p0.y, color);
		if (big_d > 0)
		{
			p0.x += x_inc;
			big_d -= 2 * delta.y;
		}
		big_d += 2 * delta.x;
		p0.y++;
	}
}
