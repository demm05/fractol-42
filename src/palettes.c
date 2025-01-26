/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:10:11 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/26 13:25:01 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include <math.h>

int	fire_color(double smooth_value, int max_iterations)
{
	double	t;

	t = smooth_value / max_iterations;
	return (encode_rgb(
			t * 255,
			t * t * 255,
			t * t * t * 255));
}

int	smooth_color(double smooth_value, int max_iterations)
{
	double	t;

	t = smooth_value / max_iterations;
	return (encode_rgb(
			9 * (1 - t) * t * t * t * 255,
			15 * (1 - t) * (1 - t) * t * t * 255,
			8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255
		));
}

int	rainbow_color(double smooth_value, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = smooth_value / max_iterations;
	r = sin(t * 6.28 + 0) * 127 + 128;
	g = sin(t * 6.28 + 2.09) * 127 + 128;
	b = sin(t * 6.28 + 4.18) * 127 + 128;
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (encode_rgb(r, g, b));
}
