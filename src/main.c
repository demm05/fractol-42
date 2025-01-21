/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:01:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/21 15:20:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(void)
{
	t_mlx_data	data;
	t_img		img;

	if (init_data(&data, &img))
		return (1);
	mlx_key_hook(data.win, intput_handler, &data);
	mlx_pixel_put(data.mlx, data.win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED);
	mlx_loop(data.mlx);
	free_everything(&data);
	return (0);
}
