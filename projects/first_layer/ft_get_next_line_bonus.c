/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:20:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/01/11 12:41:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

char	*join_buf_to_heap(char *dst, char *src, ssize_t byte, size_t q_mem)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!src || byte == 0)
		return (dst);
	else if (dst != NULL)
	{
		while (dst[i] != '\0')
			i++;
	}
	tmp = ft_strdup(dst);
	dst = ft_calloc(sizeof(char), (q_mem + byte + 1));
	dst = ft_cpy(dst, tmp, src, i);
	ft_free(&tmp);
	return (dst);
}

char	*form_static(char *str)
{
	size_t	c;
	size_t	c_cl;
	char	*clean_line;

	c = 0;
	while (str[c] != '\n')
	{
		if (str[c] == '\0')
			return (NULL);
		c++;
	}
	c_cl = c;
	while (str[c_cl] != '\0')
		c_cl++;
	clean_line = ft_calloc(sizeof(char), (c_cl - c));
	c_cl = 0;
	while (str[c] != '\0')
		clean_line[c_cl++] = str[++c];
	return (clean_line);
}

char	*cut_to_line(char *str_to_cut, char *buf)
{
	int		i;
	int		size;
	char	*cutted;

	if (!buf || !*buf)
		return (str_to_cut);
	i = 0;
	size = 0;
	while (str_to_cut[size] != '\n')
		size++;
	size += 1;
	cutted = ft_calloc(sizeof(char), (size + 1));
	while (i < size)
	{
		cutted[i] = str_to_cut[i];
		i++;
	}
	ft_free(&str_to_cut);
	return (cutted);
}

char	*read_add_to_heap(int fd, char *statica, ssize_t reader)
{
	char	*s;
	int		new_line;
	size_t	count;

	new_line = 0;
	count = 1;
	while (new_line == 0 && reader > 0)
	{
		s = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		reader = read(fd, s, BUFFER_SIZE);
		if (statica)
		{
			while (statica[count] != '\0')
				count++;
		}
		statica = join_buf_to_heap(statica, s, reader, count);
		ft_free(&s);
		if (!statica)
			break ;
		new_line = found_new_line(statica);
		if (reader == 0 && new_line == 0)
			break ;
	}
	return (statica);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;
	ssize_t		reader;

	reader = BUFFER_SIZE;
	if (fd < 0 || reader <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_add_to_heap(fd, buf[fd], reader);
	if (!line || !*line)
	{
		ft_free(&buf[fd]);
		return (NULL);
	}
	buf[fd] = form_static(line);
	if (line)
	{
		if (!buf[fd] || !*buf[fd])
			ft_free(&buf[fd]);
		line = cut_to_line(line, buf[fd]);
		return (line);
	}
	ft_free(&line);
	return (NULL);
}
