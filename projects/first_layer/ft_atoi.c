/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:05:45 by cscelfo           #+#    #+#             */
/*   Updated: 2022/10/15 18:17:15 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

int	ft_atoi(const char *nptr)
{
	char	*cn;
	int		result;
	int		sign;

	cn = (char *)nptr;
	result = 0;
	sign = 1;
	while ((*cn == ' ') || (*cn >= 9 && *cn <= 13))
		cn++;
	if (*cn == '-')
		sign *= -1;
	if (*cn == '-' || *cn == '+')
		cn++;
	while (*cn >= '0' && *cn <= '9')
	{
		result = (result * 10) + *cn - '0';
		cn++;
	}
	return (result * sign);
}
