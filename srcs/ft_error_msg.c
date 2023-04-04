/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:34:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/24 15:57:19 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

void	ft_error_msg(void)
{
	ft_printf("Available fractals: mandelbrot, julia, burningship\n\n");
	ft_printf("To launch -> Mandelbrot || burningship: ./fractol fractal\n\n");
	ft_printf("To launch -> Julia: ./fractol julia x y coordinates ");
	ft_printf("(x and y being complex numbers between -2.000 and 2.000)\n\n");
}
