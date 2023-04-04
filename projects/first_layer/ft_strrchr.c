/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:17:44 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/12 15:08:17 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

char	*ft_strrchr(const char *s, int c)
{
	int	end_to_st;

	end_to_st = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[end_to_st]);
	c %= 256;
	while (end_to_st >= 0)
	{
		if (s[end_to_st] == c)
			return ((char *)&s[end_to_st]);
		end_to_st--;
	}
	return (NULL);
}
