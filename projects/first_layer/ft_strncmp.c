/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:24:28 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/11 14:24:06 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			c;

	s_1 = (unsigned char *) s1;
	s_2 = (unsigned char *) s2;
	c = 0;
	if (n == 0)
		return (0);
	while ((c < n && s_1[c] != '\0') || (s_2[c] != '\0'))
	{
		if (s_1[c] != s_2[c])
			return (s_1[c] - s_2[c]);
		c++;
		if (c == n)
			return (0);
	}
	return (0);
}
