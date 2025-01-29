/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:13:54 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/29 17:16:20 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H 
# define RENDER_H 

# include "fractol.h"

double	get_smooth_value(int iterations, double z_real,
			double z_imag, int max_iterations);
void	draw(t_mlx_data *data);
int		fire_color(double smooth_value, int max_iterations);
int		smooth_color(double smooth_value, int max_iterations);
int		rainbow_color(double smooth_value, int max_iterations);
int		calc_fractal(t_fractal *fr, int x, int y);
void	render(t_mlx_data *data);

#endif
