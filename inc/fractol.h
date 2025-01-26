/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:59:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/26 14:43:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 800 
# define WINDOW_HEIGHT 800 
# define DEFAULT_COLOR 0xFF
# define MAXIMUX_ITER 1000
# define MINIMUM_ITER 100
# define EPSILON 1e-6

# include "libft.h"
# include "ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>

typedef int (*palette_func)(double, int);

enum e_type
{
	JULIA,
	MANDLEBROT,
	BURNING_SHIP
};

typedef struct
{
    double real;
    double imag;
}	t_complex;

typedef struct s_fractal
{
	double	width;
	double	height;
	double	scale;
	double	cx;
	double	cy;
	int		iterations;
	int		color;
	int		pallet;
	enum e_type type;
}	t_fractal;

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
	void		*mlx;
	void		*win;
	t_img		*img;
	t_fractal	*fr;
}	t_mlx_data;

double	calc_mandlebrot(t_fractal *fr, t_complex *c);
double	calc_julia(t_fractal *fr, t_complex *c);
double	calc_ship(t_fractal *fr, t_complex *c);

#endif
