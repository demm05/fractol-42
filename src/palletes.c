/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palletes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 16:19:03 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include <math.h>

int	fire_color(double smooth_value, t_fractal *fr)
{
	double	t;

	t = smooth_value / fr->iterations;
	return (encode_rgb(
			t * 255,
			t * t * 255,
			t * t * t * 255));
}

int	fire_color_shift(double smooth_value, t_fractal *fr)
{
	double	t;

	t = smooth_value / fr->iterations + fr->gradient_shift;
	return (encode_rgb(
			t * 255,
			t * t * 255,
			t * t * t * 255));
}

int	smooth_color(double smooth_value, t_fractal *fr)
{
	double	t;

	t = smooth_value / fr->iterations;
	return (encode_rgb(
			9 * (1 - t) * t * t * t * 255,
			15 * (1 - t) * (1 - t) * t * t * 255,
			8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255
		));
}

int	mono_color(double smooth_value, t_fractal *fr)
{
	double	t;
	int		intesity;

	t = smooth_value / fr->iterations;
	intesity = (int)(t * 255);
	return (encode_rgb(intesity, intesity, intesity));
}

int	pastel_color(double smooth_value, t_fractal *fr)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = smooth_value / fr->iterations + fr->gradient_shift;
	r = (0.5 + 0.5 * sin(t * 6.28 + 0)) * 127 + 128;
	g = (0.5 + 0.5 * sin(t * 6.28 + 2.09)) * 127 + 128;
	b = (0.5 + 0.5 * sin(t * 6.28 + 4.18)) * 127 + 128;
	return (encode_rgb(r, g, b));
}
