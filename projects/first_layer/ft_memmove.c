/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:49:41 by cscelfo           #+#    #+#             */
/*   Updated: 2022/10/24 18:05:39 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*source;

	if (!dest && !src)
		return (NULL);
	dst = (char *) dest;
	source = (char *) src;
	if (source <= dst)
	{
		while (n--)
			dst[n] = source[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
