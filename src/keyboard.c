/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:11:35 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 19:42:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/events.h"

void	set_correct_color(t_fractal *fr)
{
	int					i;
	static const int	valid_modes[3][COLOR_MODES] = {
	{FIRE, SMOOTH, MONO, FIRE_SHIFT, -1},
	{FIRE, SMOOTH, MONO, PASTEL, CUSTOM_GRADIENT, FIRE_SHIFT, -1},
	{SMOOTH, FIRE_SHIFT, BURNING_SHIP_FIRE, -1}
	};

	while (1)
	{
		i = 0;
		fr->color_mode = (fr->color_mode + 1) % COLOR_MODES;
		while (valid_modes[fr->type][i] != -1)
			if ((int)fr->color_mode == valid_modes[fr->type][i++])
				return ;
	}
}

int	key_event_move(int key, t_fractal *fr)
{
	if (key == XK_Up || key == XK_w)
		fr->shift_y -= fr->scale * SHIFT_STEP;
	else if (key == XK_Down || key == XK_s)
		fr->shift_y += fr->scale * SHIFT_STEP;
	else if (key == XK_Left || key == XK_a)
		fr->shift_x -= fr->scale * SHIFT_STEP;
	else if (key == XK_Right || key == XK_d)
		fr->shift_x += fr->scale * SHIFT_STEP;
	else if (key == XK_j || key == XK_k)
		scale(fr, key - XK_j);
	else if (key == XK_l)
		fr->julia_lock = !fr->julia_lock;
	else if (key == XK_q && fr->iterations < MAXIMUX_ITER)
		fr->iterations += 50;
	else if (key == XK_e && fr->iterations > MINIMUM_ITER)
		fr->iterations -= 50;
	else if (key >= XK_1 && key <= XK_5)
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
	else if (key == XK_r)
		reset_data(data->fr);
	else if (key == XK_0)
		ft_memset(data->fr, 0, sizeof(*data->fr));
	else if (key == XK_f)
		set_correct_color(data->fr);
	else if (key == XK_g)
		data->fr->gradient_shift += 0.1;
	else if (!key_event_move(key, data->fr))
		return (0);
	data->draw(data);
	return (0);
}
