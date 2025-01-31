/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:43:16 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/31 19:50:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/utils.h"

static int	init_mlx(t_mlx_data *data);
static int	parse_argv(t_fractal *fr, int argc, char *argv[]);
static void	print_help_message(void);

int	init_data(t_mlx_data *data, int argc, char *argv[])
{
	if (parse_argv(data->fr, argc, argv))
	{
		print_help_message();
		return (1);
	}
	if (init_mlx(data))
		return (1);
	return (0);
}

static inline int	set_fractol_type(char *str, enum e_type *type)
{
	int	len;

	len = ft_strlen(str);
	if (!ft_strncmp("mandlebrot", str, len))
		*type = MANDLEBROT;
	else if (!ft_strncmp("julia", str, len))
		*type = JULIA;
	else if (!ft_strncmp("ship", str, len))
		*type = BURNING_SHIP;
	else if (!ft_strncmp("spider", str, len))
		*type = SPIDER;
	else if (!ft_strncmp("tricorn", str, len))
		*type = TRICORN;
	else
		return (1);
	return (0);
}

static int	parse_argv(t_fractal *fr, int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	if (set_fractol_type(argv[1], &fr->type))
		return (1);
	reset_data(fr);
	if (fr->type == JULIA)
	{
		if (argc != 4)
			return (1);
		fr->julia_x = ft_atod(argv[2]);
		fr->julia_y = ft_atod(argv[3]);
	}
	else if (argc > 2)
		return (1);
	return (0);
}

static int	init_mlx(t_mlx_data *data)
{
	if (!data)
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, \
								HEIGHT, "Fractol 42");
	if (!data->win)
	{
		free_everything(data);
		return (1);
	}
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img)
	{
		free_everything(data);
		return (1);
	}
	data->img->buffer = mlx_get_data_addr(data->img->img, &data->img->depth, \
							&data->img->line_size, &data->img->endian);
	return (0);
}

static void	print_help_message(void)
{
	ft_printf("+-----------------Let me help you----------------------+\n");
	ft_printf("|                                                      |\n");
	ft_printf("|Usage: ./fractol [sets] [julia]                       |\n");
	ft_printf("|                                                      |\n");
	ft_printf("|Options:                                              |\n");
	ft_printf("|  sets:    [mandlebrot, julia, ship, spider, tricorn] |\n");
	ft_printf("|  julia:   [real_part, imag_part] for julia set       |\n");
	ft_printf("|                                                      |\n");
	ft_printf("|e.g: ./fratol julia 0.34 -0.05                        |\n");
	ft_printf("|                                                      |\n");
	ft_printf("|--------------------Keyboard--------------------------|\n");
	ft_printf("|                                                      |\n");
	ft_printf("|Press [ESC] to close window                           |\n");
	ft_printf("|Press [1-2] to move to another fractal                |\n");
	ft_printf("|Press [wasd] or arrow keys to move fractal            |\n");
	ft_printf("|Press [l] to lock julia set                           |\n");
	ft_printf("|Press [qe] to change iterations to escape             |\n");
	ft_printf("|Press [jk] to zoom in/out                             |\n");
	ft_printf("|Press [f] to change pallet                            |\n");
	ft_printf("|Press [g] to color shift (only for some palletes)     |\n");
	ft_printf("|Press [r] to reset the fractal                        |\n");
	ft_printf("|Press [0] to set all fractal values to zero           |\n");
	ft_printf("|          then pres [r] to set some values to default |\n");
	ft_printf("+------------------------------------------------------+\n");
}
