/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:11:35 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/29 18:13:30 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/events.h"

int	key_event_move(int key, t_fractal *fr)
{
	if (key == XK_Up || key == XK_w)
		fr->shift_y += fr->scale * SHIFT_STEP;
	else if (key == XK_Down || key == XK_s)
		fr->shift_y -= fr->scale * SHIFT_STEP;
	else if (key == XK_Left || key == XK_a)
		fr->shift_x -= fr->scale * SHIFT_STEP;
	else if (key == XK_Right || key == XK_d)
		fr->shift_x += fr->scale * SHIFT_STEP;
	else if (key == XK_j || key == XK_k)
		scale(fr, key - XK_j);
	else if (key == XK_l)
		fr->julia_lock = !fr->julia_lock;
	else if (key == XK_q && fr->iterations < MAXIMUX_ITER)
		fr->iterations += 70;
	else if (key == XK_e && fr->iterations > MINIMUM_ITER)
		fr->iterations -= 70;
	else if (key >= XK_1 && key <= XK_3)
	{
		fr->type = key - 49;
		reset_data(fr);
	}
	else
		return (0);
	return (1);
}

int	key_event(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
		destroy_event(data);
	else if (key == XK_0)
		reset_data(data->fr);
	else if (key_event_move(key, data->fr))
		;
	else
		return (0);
	data->draw(data);
	return (0);
}
