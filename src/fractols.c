/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:10:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/26 15:16:48 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"
#include <math.h>

double	calc_mandlebrot(t_fractal *fr, t_complex *c)
{
	t_complex	z;
	double		temp;
	int			i;

	i = -1;
	z.real = 0;
	z.imag = 0;
	while (++i < fr->iterations && (z.real * z.real + z.imag * z.imag) < 4)
	{
		temp = z.real * z.real - z.imag * z.imag + c->real;
		z.imag = 2 * z.real * z.imag + c->imag;
		z.real = temp;
	}
	return (get_smooth_value(i, z.real, z.imag, fr->iterations));
}

double	calc_julia(t_fractal *fr, t_complex *zz)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			i;

	z = *zz;
	i = -1;
	c.real = -0.7;
	c.imag = 0.27015;
	while (++i < fr->iterations && (z.real * z.real + z.imag * z.imag) < 4)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
	}
	return (get_smooth_value(i, z.real, z.imag, fr->iterations));
}

double	calc_ship(t_fractal *fr, t_complex *c)
{
	t_complex	z;
	t_complex	temp;
	int			i;

	i = -1;
	z.real = 0;
	z.imag = 0;
	while (++i < fr->iterations && (z.real * z.real + z.imag * z.imag) < 4)
	{
		temp.real = fabs(z.real);
		temp.imag = fabs(z.imag);

		z.real = temp.real * temp.real - temp.imag * temp.imag + c->real;
		z.imag = 2.0 * temp.real * temp.imag + c->imag;
	}
	return (get_smooth_value(i, z.real, z.imag, fr->iterations));
}
