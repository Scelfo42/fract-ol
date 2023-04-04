/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:26:28 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/06 16:15:53 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

int	ft_print_hex(unsigned int n, char format)
{
	char	*hex_arr;
	char	arr[16];
	int		i;
	int		len;

	i = 15;
	hex_arr = "0123456789abcdef";
	len = 0;
	while (n > 15)
	{
		arr[i--] = hex_arr[n % 16];
		if (format == 'X' && hex_arr[n % 16] >= 97 && hex_arr[n % 16] <= 122)
			arr[i + 1] -= 32;
		n /= 16;
	}
	if (n <= 15)
		arr[i] = hex_arr[n];
	if (format == 'X' && hex_arr[n % 16] >= 97 && hex_arr[n % 16] <= 122)
		arr[i] -= 32;
	len = 16 - i;
	write(1, &arr[i], len);
	return (len);
}
