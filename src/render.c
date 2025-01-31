/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:15:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 19:28:24 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/render.h"

int	(*get_color_func(enum e_colors col))(double sv, t_fractal *fr)
{
	if (col == MONO)
		return (mono_color);
	if (col == FIRE)
		return (fire_color);
	if (col == SMOOTH)
		return (smooth_color);
	if (col == PASTEL)
		return (pastel_color);
	if (col == CUSTOM_GRADIENT)
		return (gradient_color);
	if (col == FIRE_SHIFT)
		return (fire_color_shift);
	if (col == BURNING_SHIP_FIRE)
		return (burning_ship_fire);
	return (smooth_color);
}

int	calc_fractal(t_fractal *fr, int x, int y)
{
	t_complex	c;
	double		color;

	c.real = (map(x, -2, 2, WIDTH - 1) * fr->scale) + fr->shift_x;
	c.imag = (map(y, -2, 2, HEIGHT - 1) * fr->scale) + fr->shift_y;
	color = 0;
	if (fr->type == MANDLEBROT)
		color = calc_mandlebrot(fr, &c);
	else if (fr->type == JULIA)
		color = calc_julia(fr, c);
	else if (fr->type == BURNING_SHIP)
		color = calc_ship(fr, &c);
	else if (fr->type == SPIDER)
		color = calc_spider(fr, &c);
	else if (fr->type == TRICORN)
		color = calc_tricorn(fr, &c);
	if (color <= 0)
		return (0);
	return (get_color_func(fr->color_mode)(color, fr));
}

void	draw(t_mlx_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			my_pixel_put(data->img, x, y, calc_fractal(data->fr, x, y));
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
