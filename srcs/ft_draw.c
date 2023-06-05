/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:38:50 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/24 15:18:49 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}

void	ft_check_mouse_coord(t_data *data)
{
	if (data->mouse_x > WIN_WIDTH)
		data->mouse_x = WIN_WIDTH;
	if (data->mouse_y > WIN_HEIGHT)
		data->mouse_y = WIN_HEIGHT;
	if (data->mouse_y < 0)
		data->mouse_y = 0;
}

void	ft_draw(t_data *data)
{
	ft_check_mouse_coord(data);
	if (data->launch != 3)
	{
		if (data->launch == 1)
			ft_mandelbrot_decorator(data);
		else
			ft_julia_decorator(data);
	}
	else
		ft_burningship_decorator(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	ft_window_label(data);
}

void	ft_window_label(t_data *data)
{
	int	color;

	color = 0xffffff;
	if (data->color_man >= color - 0x080808 && data->color_man <= 0x080808)
		color = 0x000000;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 60,
		color, "Zoom in and out with mouse wheel");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 40,
		color, "Press Arrow Keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 80,
		color, "Press 'C' to change color");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 100,
		color, "Press 'R' to reset fractal");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 120,
		color, "Press 'Esc' to exit");
}
