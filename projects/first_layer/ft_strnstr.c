/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:12:41 by cscelfo           #+#    #+#             */
/*   Updated: 2022/10/13 18:21:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	c1;
	size_t	c2;

	b = (char *)big;
	l = (char *)little;
	c1 = 0;
	if (l[c1] == '\0')
		return (b);
	while (b[c1] != '\0')
	{
		c2 = 0;
		while (b[c1 + c2] == l[c2] && c1 + c2 < len)
		{	
			if (b[c1 + c2] == '\0' || l[c2++] == '\0')
				break ;
		}
		if (l[c2++] == '\0')
			return (&b[c1]);
		c1++;
	}
	return (0);
}
