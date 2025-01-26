/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:08:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/25 19:02:29 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H 

#include "fractol.h"

void	free_everything(t_mlx_data *data);
void	reset_data(t_mlx_data *data);
int		init_data(t_mlx_data *data, int argc, char *argv[]);
void	my_pixel_put(t_img *img, int x, int y, int color);
int		encode_rgb(unsigned char red, unsigned char green, unsigned char blue);

#endif
