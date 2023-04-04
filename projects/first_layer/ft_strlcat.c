/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:47:25 by cscelfo           #+#    #+#             */
/*   Updated: 2022/10/18 18:36:50 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	c;

	d = ft_strlen(dst);
	s = ft_strlen((char *)(src));
	c = 0;
	if (d >= size)
		return (size + s);
	while (src[c] && c < size - d - 1)
	{
		dst[d + c] = src[c];
		c++;
	}
	dst[d + c] = '\0';
	return (d + s);
}
