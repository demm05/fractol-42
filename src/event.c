/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:01:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/26 14:44:15 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/render.h"

void	change_color(t_mlx_data *data, int key)
{
	if (key == XK_h)
		data->fr->pallet -= 1;
	if (key == XK_l)
		data->fr->pallet += 1;
}

int	destroy_event(t_mlx_data *data)
{
	free_everything(data);
	exit(EXIT_SUCCESS);
}

int	mouse_event(int key, int x, int y, t_mlx_data *data)
{
	if (key == 4)
		data->fr->scale *= 0.9;
	else if (key == 5)
		data->fr->scale *= 1.1;
	else
		return (0);
	data->fr->cx = data->fr->cx + data->fr->scale * ((double)x / data->fr->width * 4.0 - 2.0);
	data->fr->cy = data->fr->cy + data->fr->scale * (2.0 - (double)y / data->fr->height * 4.0);
	draw(data);	
	return (0);
}

int	key_event(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
		destroy_event(data);
	else if (key == XK_Up || key == XK_w)
		data->fr->cy += data->fr->scale * 0.1;
	else if (key == XK_Down || key == XK_s)
		data->fr->cy -= data->fr->scale * 0.1;
	else if (key == XK_Left || key == XK_a)
		data->fr->cx -= data->fr->scale * 0.1;
	else if (key == XK_Right || key == XK_d)
		data->fr->cx += data->fr->scale * 0.1;
	else if (key == XK_0)
		reset_data(data);
	else if (key == XK_1)
		data->fr->type = MANDLEBROT;
	else if (key == XK_2)
		data->fr->type = JULIA;
	else if (key == XK_3)
		data->fr->type = BURNING_SHIP;
	else if (key == XK_h || key == XK_l)
		change_color(data, key);
	else
		return (0);
	draw(data);
	return (0);
}

int	mouse_move_event(int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	return (0);
}
