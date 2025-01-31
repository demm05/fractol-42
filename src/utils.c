/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:16:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 15:44:08 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	free_everything(t_mlx_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img->img)
		mlx_destroy_image(data->mlx, data->img->img);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	reset_data(t_fractal *fr)
{
	fr->shift_x = 0;
	fr->shift_y = 0;
	fr->scale = 1;
	fr->julia_x = -0.4;
	fr->julia_y = -0.59;
	fr->julia_lock = 1;
	if (fr->type == MANDLEBROT)
		fr->shift_x = -0.75;
	if (fr->type == BURNING_SHIP)
	{
		fr->scale = 0.026;
		fr->shift_x = -1.75;
		fr->shift_y = -0.039;
	}
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

// [0...799] -> [-2, 2] maps value
double	map(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled - 0) / (old_max - 0) + new_min);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_size) + (x * (img->depth / 8));
	*((unsigned int *)(offset + img->buffer)) = color;
}
