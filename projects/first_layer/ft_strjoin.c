/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:16:29 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/14 21:05:04 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		k;
	char	*new;

	c = 0;
	k = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[c] != '\0')
	{
		new[c] = s1[c];
		c++;
	}
	while (s2[k] != '\0')
	{
		new[c + k] = s2[k];
		k++;
	}
	new[c + k] = '\0';
	return (new);
}
/*
#include <stdio.h>
int	main()
{
	char	*s = "hey ";
	char	*ss = "bob";
	char	*sss = ft_strjoin(s, ss);
	printf("%s\n", sss);
	free(sss);
}*/
