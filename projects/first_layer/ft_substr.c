/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:49:13 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/12 16:29:29 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

static size_t	ft_minmem(size_t s_len, size_t len, unsigned int start)
{
	if (len < s_len)
		return (len);
	else
	{
		if (start > s_len)
			return (0);
		return (s_len);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		s_len;
	size_t		shorter;

	i = 0;
	s_len = ft_strlen(s);
	shorter = ft_minmem(s_len, len, start);
	str = (char *)malloc(sizeof(char) * shorter + 1);
	if (str == NULL)
		return (NULL);
	while (i < shorter && start < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
