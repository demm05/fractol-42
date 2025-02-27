/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:01:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 16:06:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/events.h"
#include "../inc/utils.h"
#include "../inc/render.h"

int	main(int argc, char *argv[])
{
	t_fractal	fr;
	t_mlx_data	data;
	t_img		img;
	t_render	r;	

	fr.iterations = 50;
	fr.color_mode = SMOOTH;
	fr.gradient_shift = 0;
	data.fr = &fr;
	data.img = &img;
	data.r = &r;
	data.draw = render;
	if (init_data(&data, argc, argv))
		return (1);
	mlx_key_hook(data.win, key_event, &data);
	mlx_mouse_hook(data.win, mouse_event, &data);
	mlx_hook(data.win, 17, 0, destroy_event, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move_event, &data);
	data.draw(&data);
	mlx_loop(data.mlx);
	return (0);
}
