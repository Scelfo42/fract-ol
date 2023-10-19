/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:38:50 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/16 12:48:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

static void	ft_check_mouse_coord(t_data *data)
{
	if (data->mouse_x > WIN_WIDTH)
		data->mouse_x = WIN_WIDTH;
	if (data->mouse_y > WIN_HEIGHT)
		data->mouse_y = WIN_HEIGHT;
	if (data->mouse_y < 0)
		data->mouse_y = 0;
	if (data->mouse_x < 0)
		data->mouse_x = 0;
}

static char	*ft_calculate_iterations(t_data *data)
{
	char	*str;
	char	*iterations;
	char	*result;

	str = "Current iterations are ";
	iterations = ft_itoa(data->coord.max_iter);
	result = ft_strjoin(str, iterations);
	free(iterations);
	return (result);
}

static void	ft_window_label(t_data *data)
{
	int	color;

	color = 0xffffff;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 60, color, "Zoom in and out with mouse wheel");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 40, color, "Press Arrow Keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 80, color, "Press 'C' to change color");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 100, color, "Press 'R' to reset fractal");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 120, color, "Press 'Esc' to exit");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 140, color, "Press '1' for Mandelbrot");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 160, color, "Press '2' for Julia");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 180, color, "Press '3' for Burning Ship");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 200, color, ft_calculate_iterations(data));
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}

void	ft_draw(t_data *data)
{
	ft_check_mouse_coord(data);
	if (data->launch < 3)
	{
		if (data->launch == 1)
			ft_mandelbrot_decorator(data);
		else
			ft_julia_decorator(data);
	}
	else
	{
		if (data->launch == 3)
			ft_burningship_decorator(data);
		else
			ft_newton_decorator(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	ft_window_label(data);
}
