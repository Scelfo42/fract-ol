/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:23:05 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/19 18:34:27 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

int	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("An error has occured creating mlx_ptr!\n");
		return (MLX_ERROR);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cscelfo - fract-ol");
	if (!data->win_ptr)
	{
		ft_printf("An error has occured creating win_ptr!\n");
		return (MLX_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.mlx_img)
	{
		ft_printf("An error has occured creating mlx_img!\n");
		return (MLX_ERROR);
	}
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	if (!data->img.addr)
	{
		ft_printf("An error has occured getting data address from the img!\n");
		return (MLX_ERROR);
	}
	return (0);
}

int	ft_hooks_init(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 1l << 0, &ft_key_handler, data);
	mlx_mouse_hook(data->win_ptr, &ft_mouse_handler, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &ft_destroy_fractal, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

static int	ft_get_small_side(void)
{
	if (WIN_WIDTH < WIN_HEIGHT)
		return (WIN_WIDTH);
	else
		return (WIN_HEIGHT);
	return (0);
}

void	ft_set_fractal_data(t_data *data)
{
	if (data->launch < 3)
	{
		if (data->launch == 1)
		{
			data->color_man = 0x0000FF;
			data->coord.max_iter = MAX_ITER_MAN;
		}
		else
		{
			data->color_jul = 0x0000FF;
			data->coord.max_iter = MAX_ITER_JUL;
		}
	}
	else
	{
		if (data->launch == 3)
		{
			data->color_burn = 0x00000F;
			data->coord.max_iter = MAX_ITER_BURN;
		}
		else if (data->launch == 4)
			data->coord.max_iter = MAX_ITER_NEW;
	}
}

void	ft_draw_handler(t_data *data)
{
	data->x_min = -2.0;
	data->x_max = 2.0;
	data->y_min = -2.0;
	data->y_max = 2.0;
	data->move_x = 0;
	data->move_y = 0;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->small_side = ft_get_small_side();
	ft_set_fractal_data(data);
	ft_draw(data);
}
