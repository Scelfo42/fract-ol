/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:42:55 by cscelfo           #+#    #+#             */
/*   Updated: 2022/10/13 00:08:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			c;

	s_1 = (unsigned char *) s1;
	s_2 = (unsigned char *) s2;
	c = 0;
	if (c == n)
		return (0);
	while (c < n)
	{
		if (s_1[c] != s_2[c])
			return (s_1[c] - s_2[c]);
		c++;
	}
	return (0);
}
