/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:59:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 19:27:52 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1080
# define HEIGHT 1080 
# define MAXIMUX_ITER 1000
# define MINIMUM_ITER 50 
# define SHIFT_STEP 0.5
# define ZOOM_STEP .1
# define THREADS 20 
# define COLOR_MODES 7

# include "libft.h"
# include "ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdbool.h>

typedef struct s_fractal	t_fractal;
typedef struct s_mlx_data	t_mlx_data;
typedef void (t_draw)(t_mlx_data*);

enum e_type
{
	MANDLEBROT,
	JULIA,
	BURNING_SHIP,
	SPIDER,
	TRICORN
};

// When you add or delete modes please modify COLOR_MODES
enum e_colors
{
	FIRE,
	SMOOTH,
	MONO,
	PASTEL,
	CUSTOM_GRADIENT,
	FIRE_SHIFT,
	BURNING_SHIP_FIRE
};

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_thread
{
	int			id;
	t_mlx_data	*data;
}	t_thread;

typedef struct s_render
{
	pthread_t	threads[THREADS];
	t_thread	args[THREADS];
}	t_render;

typedef struct s_fractal
{
	double			shift_x;
	double			shift_y;
	double			julia_x;
	double			julia_y;
	double			scale;
	double			gradient_shift;
	int				iterations;
	bool			julia_lock;
	enum e_type		type;
	enum e_colors	color_mode;
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
	t_render	*r;
	t_draw		*draw;
}	t_mlx_data;

double	calc_mandlebrot(t_fractal *fr, t_complex *c);
double	calc_julia(t_fractal *fr, t_complex c);
double	calc_ship(t_fractal *fr, t_complex *c);
double	calc_spider(t_fractal *fr, t_complex *c);
double	calc_tricorn(t_fractal *fr, t_complex *c);

#endif
