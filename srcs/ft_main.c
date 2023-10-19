/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:49:57 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/17 18:13:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_valid_args(&data, argc, argv))
		ft_error_msg();
	else
	{
		data.fractal = argv[1];
		ft_init(&data);
		ft_draw_handler(&data);
		ft_hooks_init(&data);
	}
	return (0);
}
