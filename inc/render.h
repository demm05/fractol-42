/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:13:54 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 16:52:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H 
# define RENDER_H 

# include "fractol.h"

void	draw(t_mlx_data *data);
int		calc_fractal(t_fractal *fr, int x, int y);
void	render(t_mlx_data *data);
int		fire_color(double smooth_value, t_fractal *fr);
int		smooth_color(double smooth_value, t_fractal *fr);
int		mono_color(double smooth_value, t_fractal *fr);
int		pastel_color(double smooth_value, t_fractal *fr);
int		gradient_color(double smooth_value, t_fractal *fr);
int		fire_color_shift(double smooth_value, t_fractal *fr);
int		burning_ship_fire(double smooth_value, t_fractal *fr);

#endif
