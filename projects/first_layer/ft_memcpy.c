/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:38 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/18 12:04:47 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cast_dest;
	char		*cast_src;

	i = 0;
	cast_dest = (char *)dest;
	cast_src = (char *)src;
	while (i < n)
	{
		cast_dest[i] = cast_src[i];
		i++;
	}
	if (!cast_dest && !cast_src)
		return (NULL);
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
//	size_t	s_len = 0;
//	void	*new_s = malloc(5);
//	const void	*s = malloc(10);
	void	*m_memcpy = ft_memcpy(((void*)0), ((void*)0), 3);
	printf("%p\n", m_memcpy);
	printf("%p\n", memcpy(((void*)0), ((void*)0), 3));
}*/
