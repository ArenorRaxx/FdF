/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:11:05 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/06 19:30:16 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	color_to_int(t_color color)
{
	int	result;

	result |= color.r << 16;
	result |= color.g << 8;
	result |= color.b << 0;
	return (result);
}

t_color	int_to_color(int color)
{
	t_color	result;

	result.r = color >> 16 & 0xFF;
	result.g = color >> 8 & 0xFF;
	result.b = color & 0xFF;
	return (result);
}

int	lerp_rgb(t_fading colors, float t)
{
	t_color	color;

	color.r = colors.from.r + (colors.to.r - colors.from.r) * t;
	color.g = colors.from.g + (colors.to.g - colors.from.g) * t;
	color.b = colors.from.b + (colors.to.b - colors.from.b) * t;
	return (color_to_int(color));
}
