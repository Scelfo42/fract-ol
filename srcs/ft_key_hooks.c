/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:50:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/11 19:25:37 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

bool	ft_isarrow(int keycode)
{
	return (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT);
}

bool	ft_isfractal_change(int keycode)
{
	return (keycode == XK_1 || keycode == XK_2 || keycode == XK_3);
}

void	ft_arrow_handler(int keycode, t_data *data)
{
	if (keycode == UP)
		data->move_y -= (WIN_HEIGHT / 20);
	else if (keycode == LEFT)
		data->move_x -= (WIN_HEIGHT / 20);
	else if (keycode == DOWN)
		data->move_y += (WIN_HEIGHT / 20);
	else if (keycode == RIGHT)
		data->move_x += (WIN_HEIGHT / 20);
}

static int	ft_random_color(int color)
{
	if (color <= 0x000FFF)
		color = rand() % 4095;
	else if (color > 0x000FFF && color <= 0x00FFFF)
		color = rand() % 65535 + 4095;
	else if (color > 0x00FFFF && color < 0xFFFFFF)
		color = rand() % 1048575 + 65535;
	else if (color == 0xFFFFFF)
		color = rand() % 0xFFFFFF + 1048575;
	return (color);
}

void	ft_change_color(t_data *data)
{
	if (data->launch == 1)
		data->color_man = ft_random_color(data->color_man);
	else if (data->launch == 2)
		data->color_jul = ft_random_color(data->color_jul);
	else if (data->launch == 3)
		data->color_burn = ft_random_color(data->color_burn);
}

void	ft_change_fractal(int keycode, t_data *data)
{
	if (keycode == XK_1)
	{
		data->launch = 1;
		ft_reset_fractal(data);
	}
	else if (keycode == XK_2)
	{
		data->launch = 2;
		data->coord.julia.re = -0.7;
		data->coord.julia.im = 0.27015;
		ft_reset_fractal(data);
	}
	else if (keycode == XK_3)
	{
		data->launch = 3;
		ft_reset_fractal(data);
	}
}

void	ft_adjust_color(t_data *data, int sign, int fractal)
{
	int	color;

	color = data->color_man;
	if (fractal != 3)
	{
		if (fractal == 2)
			color = data->color_jul;
	}
	else
		color = data->color_burn;
	if (color == 0xFFFFFF)
		data->coord.max_iter += 1000000;
	else if (color >= 255 && color < 4095)
	{
		if (sign == PLUS)
		{
			data->coord.max_iter += 750;
			color = ceil(color * 16.058823529411);
		}
		else if (sign == XK_minus && data->coord.max_iter > 1255)
			data->coord.max_iter -= 1000;
	}
	else if (color >= 4095 && color < 65535)
	{
		if (sign == PLUS)
		{
			data->coord.max_iter += 10000;
			color *= 16.003663004;
		}
		else if (sign == XK_minus)
		{
			data->coord.max_iter -= 1000;
			color /= 16.058823529411;
		}
	}
	else if (color >= 65535 && color < 1048575)
	{
		if (sign == PLUS)
		{
			data->coord.max_iter += 100000;
			color = ceil(color * 16.000228885);
		}
		else if (sign == XK_minus)
		{
			data->coord.max_iter -= 10000;
			color = ceil(color / 16.003663004);
		}
	}
	else if (color >= 1048575 && color < 0xFFFFFF)
	{
		if (sign == PLUS)
		{
			data->coord.max_iter += 1000000;
			color = ceil(color * 16.000014305);
		}
		else if (sign == XK_minus)
		{
			data->coord.max_iter -= 100000;
			color /= 16.000228885;
		}		
	}
	if (fractal == 1)
		data->color_man = color;
	if (fractal == 2)
		data->color_jul = color;
	else if (fractal == 3)
		data->color_burn = color;
}
