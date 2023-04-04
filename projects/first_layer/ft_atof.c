/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:39:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/24 16:01:49 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		sign;
	double	dec;

	i = 0;
	sign = 1;
	res = 0.0;
	dec = 1.0;
	if (str[i] == '-')
		sign = -1;
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		dec *= 10;
	}
	return (res / dec * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    double num;

    printf("Converting %d arguments to doubles:\n", argc - 1);

    for (i = 1; i < argc; i++) {
        num = ft_atof(argv[i]);
        printf("%s -> %f\n", argv[i], num);
    }

    // Test with positive and negative numbers
    num = atof("123.456");
    printf("real -- Positive number: %f\n", num);
    num = ft_atof("123.456");
    printf("mine -- Positive number: %f\n", num);

    num = atof("-987.654");
    printf("real -- Negative number: %f\n", num);
    num = ft_atof("-987.654");
    printf("mine -- Negative number: %f\n", num);

    return 0;
}*/
