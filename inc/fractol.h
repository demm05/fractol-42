/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:59:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/21 19:44:02 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 1920 
# define WINDOW_HEIGHT 1080 

# define RED 0xFF0000
# define GREEN 0xFF00
# define BLUE 0X00FFFF

# include "libft.h"
# include "ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*img;
	char	*buffer;
	int		depth;
	int		line_size;	
	int		endian;
}	t_img;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_mlx_data;

void	free_everything(t_mlx_data *data);
int		intput_handler(int keysym, t_mlx_data *data);
int		init_data(t_mlx_data *data, t_img *img);

#endif
