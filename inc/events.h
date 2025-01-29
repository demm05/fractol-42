/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:01:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/29 18:12:43 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractol.h"

int		destroy_event(t_mlx_data *data);
int		mouse_event(int key, int x, int y, t_mlx_data *data);
int		key_event(int key, t_mlx_data *data);
int		mouse_move_event(int x, int y, t_mlx_data *data);
void	scale(t_fractal *fr, bool out);

#endif
