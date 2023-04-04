/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:12:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/06 17:02:06 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

static int	ft_check_flag(va_list args, char flag)
{
	int	size;

	size = 0;
	if (flag == 'c')
		size = ft_putchar(va_arg(args, int));
	else if (flag == 's')
		size = ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		size = ft_print_ptr(va_arg(args, uintptr_t));
	else if (flag == 'd' || flag == 'i')
		size = ft_putnbr(va_arg(args, int));
	else if (flag == 'u')
		size = ft_put_u_nbr(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		size = ft_print_hex(va_arg(args, unsigned int), flag);
	else if (flag == '%')
		size = ft_putchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		space;
	va_list	args;

	i = 0;
	space = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			space += ft_check_flag(args, str[++i]);
		else
		{
			ft_putchar(str[i]);
			space += 1;
		}
		i++;
	}
	va_end(args);
	return (space);
}
