/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:24:53 by cscelfo           #+#    #+#             */
/*   Updated: 2023/01/11 12:02:07 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

void	*ft_free(char **ptr_s)
{
	if (*ptr_s)
	{
		free(*ptr_s);
		*ptr_s = 0;
	}
	return (*ptr_s);
}

int	found_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cpy(char *dest, char *tmp, char *source, size_t start)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = start;
	if (tmp)
	{
		while (i > 0)
		{
			dest[j] = tmp[j];
			j++;
			i--;
		}
	}
	j = 0;
	while (source[j] != '\0')
	{
		dest[start + j] = source[j];
		j++;
	}
	return (dest);
}

char	*ft_strdup(const char *old_line)
{
	char	*new_l;
	int		size_l;
	int		i;

	size_l = 0;
	i = 0;
	if (!old_line)
		return (NULL);
	while (old_line[size_l] != '\0')
		size_l++;
	new_l = ft_calloc(sizeof(char), size_l + 1);
	while (i < size_l)
	{
		new_l[i] = old_line[i];
		i++;
	}
	ft_free((char **)&old_line);
	return (new_l);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*clean_str;
	size_t	i;
	size_t	nmem_size;

	i = 0;
	nmem_size = nmemb * size;
	if (nmem_size < nmemb)
		return (NULL);
	clean_str = malloc(sizeof(char) * nmem_size);
	if (!clean_str)
		return (NULL);
	while (nmem_size > 0)
	{
		clean_str[i++] = '\0';
		nmem_size--;
	}
	return (clean_str);
}
