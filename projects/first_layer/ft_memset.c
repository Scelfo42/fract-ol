/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:27:15 by cscelfo           #+#    #+#             */
/*   Updated: 2022/10/10 16:15:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cast_s;

	cast_s = (char *)s;
	while (n > 0)
	{
		cast_s[n - 1] = c;
		n--;
	}
	return (s);
}
