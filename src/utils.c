/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:16:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/26 15:11:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

double get_smooth_value(int iterations, double z_real, double z_imag, int max_iterations)
{
	if (iterations == max_iterations)
		return 0.0;

	double log_zn = log(z_real * z_real + z_imag * z_imag) / 2.0;
	double nu = log(log_zn / log(2.0)) / log(2.0);
	return (iterations + 1 - nu);
}

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

void	reset_data(t_mlx_data *data)
{
	data->fr->color = DEFAULT_COLOR;
	data->fr->cx = -0.75;
	data->fr->cy = 0;
	data->fr->iterations = 50;
	data->fr->scale = 2;
	data->fr->width = WINDOW_WIDTH;
	data->fr->height = WINDOW_HEIGHT;
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_size) + (x * (img->depth / 8));
	*((unsigned int *)(offset + img->buffer)) = color;
}
