/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/29 18:16:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	destroy_event(t_mlx_data *data)
{
	free_everything(data);
	exit(EXIT_SUCCESS);
}

void	scale(t_fractal *fr, bool out)
{
	if (out)
		fr->scale *= 1 + ZOOM_STEP;
	else
		fr->scale *= 1 - ZOOM_STEP;
}

int	mouse_event(int key, int x, int y, t_mlx_data *data)
{
	double	map_x;
	double	map_y;
	double	old_scale;

	if (key != 4 && key != 5)
		return (0);
	map_x = map(x, -2, 2, WIDTH - 1);
	map_y = map(y, 2, -2, HEIGHT - 1);
	old_scale = data->fr->scale;
	scale(data->fr, key - 4);
	data->fr->shift_x += map_x * old_scale - map_x * data->fr->scale;
	data->fr->shift_y += map_y * old_scale - map_y * data->fr->scale;
	data->draw(data);
	return (0);
}

int	mouse_move_event(int x, int y, t_mlx_data *data)
{
	if (data->fr->type != JULIA || data->fr->julia_lock)
		return (0);
	data->fr->julia_x = map(x, -2, 2, WIDTH - 1) * data->fr->scale;
	data->fr->julia_y = map(y, 2, -2, HEIGHT - 1) * data->fr->scale;
	data->draw(data);
	return (0);
}
