/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/21 15:25:41 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

void	color_screen(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_pixel_put(data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	intput_handler(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
	{
		free_everything(data);
		exit(0);
	}
	else if (key == XK_r)
		color_screen(data, encode_rgb(255, 0, 0));
	else if (key == XK_g)
		color_screen(data, encode_rgb(0xff, 255, 0));
	else if (key == XK_b)
		color_screen(data, encode_rgb(0, 0, 255));
	return (0);
}
