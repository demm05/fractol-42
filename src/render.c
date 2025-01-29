/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:15:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/29 17:36:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/render.h"
#include <math.h>

int	calc_fractal(t_fractal *fr, int x, int y)
{
	t_complex	c;
	double		color;

	c.real = (map(x, -2, 2, WIDTH - 1) * fr->scale) + fr->shift_x;
	c.imag = (map(y, 2, -2, HEIGHT - 1) * fr->scale) + fr->shift_y;
	color = 0;
	if (fr->type == MANDLEBROT)
		color = calc_mandlebrot(fr, &c);
	else if (fr->type == JULIA)
		color = calc_julia(fr, c);
	else if (fr->type == BURNING_SHIP)
		color = calc_ship(fr, &c);
	color = smooth_color(color, fr->iterations);
	return (color);
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
