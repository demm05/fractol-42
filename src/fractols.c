/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:38:07 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/29 17:36:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/utils.h"
#include <math.h>

double	calc_mandlebrot(t_fractal *fr, t_complex *c)
{
	t_complex	z;
	t_complex	sq;
	int			i;

	i = -1;
	z.real = 0;
	z.imag = 0;
	sq.real = 0;
	sq.imag = 0;
	while (++i < fr->iterations)
	{
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		if (sq.imag * sq.real > 4)
			break ;
		z.imag = 2.0 * z.real * z.imag + c->imag;
		z.real = sq.real - sq.imag + c->real;
	}
	if (i == fr->iterations)
		return (0);
	return (log(log(sq.real + sq.imag) / log(2.0)) / 2.0 + 1 + i);
}

double	calc_julia(t_fractal *fr, t_complex z)
{
	t_complex	c;
	t_complex	sq;
	int			i;

	i = -1;
	sq.real = 0;
	sq.imag = 0;
	c.real = fr->julia_x;
	c.imag = fr->julia_y;
	while (++i < fr->iterations)
	{
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		if (sq.imag * sq.real > 4)
			break ;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = sq.real - sq.imag + c.real;
	}
	if (i == fr->iterations)
		return (0);
	return (log(log(sq.real + sq.imag) / log(2.0)) / 2.0 + 1 + i);
}

double	calc_ship(t_fractal *fr, t_complex *c)
{
	t_complex	z;
	t_complex	sq;
	int			i;

	i = -1;
	sq.real = 0;
	sq.imag = 0;
	z.real = 0;
	z.imag = 0;
	while (++i < fr->iterations)
	{
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
		if (sq.imag * sq.real > 4)
			break ;
		z.imag = fabs(2.0 * z.real * z.imag) - c->imag;
		z.real = sq.real - sq.imag + c->real;
	}
	if (i == fr->iterations)
		return (0);
	return (log(log(sq.real + sq.imag) / log(2.0)) / 2.0 + 1 + i);
}
