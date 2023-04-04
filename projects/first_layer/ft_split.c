/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:30:19 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/17 17:08:45 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

static int	ft_countstr(char *s, char c)
{
	int	num_str;
	int	i;

	num_str = 0;
	i = 0;
	if (!s)
		return (num_str);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		num_str += 1;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num_str);
}

char	**ft_split(char const *s, char c)
{
	t_var		var;

	var.i = 0;
	var.k = 0;
	var.j = 0;
	var.trim = ft_strtrim(s, &c);
	if (!var.trim)
		return (NULL);
	var.nb_str = ft_countstr(var.trim, c);
	var.arr_p = (char **)malloc(sizeof(char *) * (var.nb_str + 1));
	if (!var.arr_p)
		return (NULL);
	while (var.i < var.nb_str)
	{
		if (var.trim[++var.j] == c || var.trim[var.j] == '\0')
		{
			var.arr_p[var.i++] = ft_substr(var.trim, var.k, var.j - var.k);
			while (var.trim[var.j] == c)
				var.j++;
			var.k = var.j;
		}
	}
	var.arr_p[var.i] = 0;
	free(var.trim);
	return (var.arr_p);
}
/*
#include <stdio.h>
int	main()
{
	int	nbstr = ft_countstr(0, 0);
	char	**arr_of_pointers = ft_split(0, 0);
	for (int i = 0; i < nbstr; i++)
	{
		printf("%s\n", arr_of_pointers[i]);
		free(arr_of_pointers[i]);
	}
	free(arr_of_pointers);
}*/
