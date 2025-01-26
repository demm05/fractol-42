/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:43:16 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/26 14:42:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/utils.h"

static int	init_mlx(t_mlx_data *data);
static int	parse_argv(t_mlx_data *data, int argc, char *argv[]);
static void	print_help_message(void);

int	init_data(t_mlx_data *data, int argc, char *argv[])
{
	if (parse_argv(data, argc, argv))
	{
		print_help_message();
		return (1);
	}
	if (init_mlx(data))
		return (1);
	reset_data(data);
	data->fr->pallet = 0;
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
	else
		return (1);
	return (0);
}

static int	parse_argv(t_mlx_data *data, int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	if (set_fractol_type(argv[1], &data->fr->type))
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
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, \
								WINDOW_HEIGHT, "Fractol 42");
	if (!data->win)
	{
		free_everything(data);
		return (1);
	}
	data->img->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
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
	ft_printf("+-----------------Let me help you-----------------+\n");
	ft_printf("|                                                 |\n");
	ft_printf("|Usage: ./fractol [sets]                          |\n");
	ft_printf("|                                                 |\n");
	ft_printf("|e.g: ./fratol mandlebrot                         |\n");
	ft_printf("|                                                 |\n");
	ft_printf("|Options:                                         |\n");
	ft_printf("|  sets:      [julia, mandlebrot, ship]           |\n");
	ft_printf("|                                                 |\n");
	ft_printf("|--------------------Keyboard---------------------|\n");
	ft_printf("|                                                 |\n");
	ft_printf("|Press [ESC] to close window                      |\n");
	ft_printf("|Press [1-2] to move to another fractal           |\n");
	ft_printf("|Press [0] to reset the fractal                   |\n");
	ft_printf("|Press [wasd] or arrow keys to move fractal       |\n");
	ft_printf("|Press [hl] to change color mapping               |\n");
	ft_printf("|Use mouse scroll to zoom in and out              |\n");
	ft_printf("|                                                 |\n");
	ft_printf("+-------------------------------------------------+\n");
}
