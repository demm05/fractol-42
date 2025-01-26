/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:15:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/26 15:16:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/render.h"

int	get_color(t_fractal *fr, double smooth_value, int shift)
{
	static palette_func pals[3];
	int					len;

	len = 3;
	if (!pals[0])
	{
		pals[0] = fire_color;
		pals[1] = smooth_color;
		pals[2] = rainbow_color;
	}
	if (fr->pallet >= len)
		fr->pallet = 0;
	else if (fr->pallet < 0)
		fr->pallet = len - 1;
	return (pals[fr->pallet](smooth_value, shift));
}

int	calc_fractal(t_fractal *fr, int x, int y)
{
	static t_complex	c;
	static double		t;
	int					color;

	c.real = fr->cx + fr->scale * ((double)x / fr->width * 4.0 - 2.0);
	c.imag = fr->cy + fr->scale * (2.0 - (double)y / fr->height * 4.0);
	color = 0;
	if (fr->type == MANDLEBROT)
		t = calc_mandlebrot(fr, &c);
	else if (fr->type == JULIA)
		t = calc_julia(fr, &c);
	else if (fr->type == BURNING_SHIP)
		t = calc_ship(fr, &c);
	color = get_color(fr, t, fr->iterations);
	return (color);
}

void	draw(t_mlx_data *data)
{
	int		x;
	int		y;
	int		color;

	y = -1;
	while (++y < data->fr->height)
	{
		x = -1;
		while (++x < data->fr->width)
		{
			color = calc_fractal(data->fr, x, y);
			my_pixel_put(data->img, x, y, color);
		}
	}
    mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
