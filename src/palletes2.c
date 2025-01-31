/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palletes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:50:28 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 16:52:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include <math.h>

int	gradient_color(double smooth_value, t_fractal *fr)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = smooth_value / fr->iterations + fr->gradient_shift;
	r = (sin(t * 6.28)) * 127 + 128;
	g = (sin(t * 6.28 + 2.09)) * 127 + 128;
	b = (sin(t * 6.28 + 4.18)) * 127 + 128;
	return (encode_rgb(r, g, b));
}

int	burning_ship_fire(double smooth_value, t_fractal *fr)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = smooth_value / fr->iterations;
	r = 255 * (1 - exp(-t * 10));
	g = 255 * (1 - exp(-t * 15)) * 0.5;
	b = 255 * (1 - exp(-t * 20)) * 0.2;
	return (encode_rgb(r, g, b));
}
