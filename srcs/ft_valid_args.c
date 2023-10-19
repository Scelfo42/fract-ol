/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:35:04 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/16 12:47:18 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

int	ft_julia_args(t_data *data, char **argv)
{
	data->coord.julia.re = ft_atof(argv[2]);
	data->coord.julia.im = ft_atof(argv[3]);
	if (data->coord.julia.re > -2 && data->coord.julia.re < 2
		&& data->coord.julia.im > -2 && data->coord.julia.im < 2)
		return (1);
	return (0);
}

int	ft_valid_args(t_data *data, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
		{
			data->launch = 1;
			return (1);
		}
		else if (!ft_strncmp(argv[1], "burningship", 11))
		{
			data->launch = 3;
			return (1);
		}
		else if (!ft_strncmp(argv[1], "newton", 7))
		{
			data->launch = 4;
			return (1);
		}
	}
	else if (argc == 4)
	{
		if (!ft_strncmp(argv[1], "julia", 5) && ft_julia_args(data, argv))
		{
			data->launch = 2;
			return (1);
		}
	}
	else
		ft_error_msg();
	return (0);
}
