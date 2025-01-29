/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:12:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/29 17:16:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/render.h"
#include <pthread.h>

void	*render_thread(void *r)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)r;
	y = HEIGHT / THREADS * t->id;
	while (y < HEIGHT / THREADS * (t->id + 1))
	{
		x = -1;
		while (++x < WIDTH)
			my_pixel_put(t->data->img, x, y, calc_fractal(t->data->fr, x, y));
		y++;
	}
	return (NULL);
}

void	render(t_mlx_data *data)
{
	t_render	*r;
	int			i;

	r = data->r;
	i = 0;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].data = data;
		pthread_create(r->threads + i, NULL, render_thread, &(r->args[i]));
		i++;
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(r->threads[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

