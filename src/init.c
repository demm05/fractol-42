/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:43:16 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/21 19:43:25 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_data(t_mlx_data *data, t_img *img)
{
	if (!data || !img)
		return (1);
	data->mlx = mlx_init();
	data->img = img;
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, \
								WINDOW_HEIGHT, "mlx 42");
	if (!data->win)
	{
		free_everything(data);
		return (1);
	}
	img->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img->img)
	{
		free_everything(data);
		return (1);
	}
	img->buffer = mlx_get_data_addr(img->img, &img->depth, \
							&img->line_size, &img->endian);
	return (0);
}
