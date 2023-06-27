/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:50:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/27 09:46:44 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

void	ft_reset_fractal(t_data *data)
{
	data->x_min = -2.0;
	data->x_max = 2.0;
	data->y_min = -2.0;
	data->y_max = 2.0;
	data->move_x = 0;
	data->move_y = 0;
	data->coord.max_iter = MAX_ITER_GENERAL;
	data->color_man = 0x0003FF;
	data->color_jul = 0x00FF00;
	data->color_burn = 0xFF0000;
}

void	ft_zoom_in(t_data *data, int px, int py)
{
	data->mouse_x = data->x_min + (px + data->move_x)
		* (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_max - (data->move_y + py)
		* (data->y_max - data->y_min) / data->small_side;
	data->x_min = data->mouse_x
		- (data->mouse_x - data->x_min) * ZOOM_IN_FACTOR;
	data->y_min = data->mouse_y
		- (data->mouse_y - data->y_min) * ZOOM_IN_FACTOR;
	data->x_max = data->mouse_x
		+ (data->x_max - data->mouse_x) * ZOOM_IN_FACTOR;
	data->y_max = data->mouse_y
		+ (data->y_max - data->mouse_y) * ZOOM_IN_FACTOR;
	data->coord.max_iter += 10;
}

void	ft_zoom_out(t_data *data, int px, int py)
{
	data->mouse_x = data->x_min + (px + data->move_x)
		* (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_max - (data->move_y + py)
		* (data->y_max - data->y_min) / data->small_side;
	data->x_min = data->mouse_x
		- (data->mouse_x - data->x_min) * ZOOM_OUT_FACTOR;
	data->y_min = data->mouse_y
		- (data->mouse_y - data->y_min) * ZOOM_OUT_FACTOR;
	data->x_max = data->mouse_x
		+ (data->x_max - data->mouse_x) * ZOOM_OUT_FACTOR;
	data->y_max = data->mouse_y
		+ (data->y_max - data->mouse_y) * ZOOM_OUT_FACTOR;
	data->coord.max_iter -= 10;
}

int	ft_mouse_handler(int keycode, int px, int py, t_data *data)
{
	if (keycode == 4)
		ft_zoom_in(data, px, py);
	else if (keycode == 5)
		ft_zoom_out(data, px, py);
	else
		return (0);
	ft_draw(data);
	return (1);
}

int	ft_key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		ft_destroy_fractal(data);
		return (0);
	}
	else if (keycode == XK_Up)
		data->move_y -= (WIN_HEIGHT / 20);
	else if (keycode == XK_Left)
		data->move_x -= (WIN_HEIGHT / 20);
	else if (keycode == XK_Down)
		data->move_y += (WIN_HEIGHT / 20);
	else if (keycode == XK_Right)
		data->move_x += (WIN_HEIGHT / 20);
	else if (keycode == XK_c)
	{
		if (data->launch == 1)
			data->color_man *= 2;
		else if (data->launch == 2)
			data->color_jul *= 2;
		else if (data->launch == 3)
			data->color_burn *= 2;
	}
	else if (keycode == XK_b)
	{
		if (data->launch == 1)
			data->color_man /= 2;
		else if (data->launch == 2)
			data->color_jul /= 2;
		else if (data->launch == 3)
			data->color_burn /= 2;
	}
	else if (keycode == XK_r)
		ft_reset_fractal(data);
	ft_draw(data);
	return (0);
}
