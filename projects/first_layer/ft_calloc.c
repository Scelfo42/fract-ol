/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:42:50 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/18 12:13:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*zero_mem;
	size_t	n_s;

	n_s = nmemb * size;
	if (!nmemb || !size)
		return (ft_strdup(""));
	if (n_s < nmemb)
		return (NULL);
	zero_mem = malloc(n_s);
	if (zero_mem == NULL)
		return (NULL);
	ft_bzero(zero_mem, n_s);
	return (zero_mem);
}
/*
#include <stdio.h>
int	main()
{
	size_t	nmemb = 10;
	size_t	size = 1;
	void	*mine = ft_calloc(nmemb, size);
	void	*orig = calloc (nmemb, size);
	printf("\n%p\n", mine); //x/xg to see 0 memory
	printf("\n%p\n\n", orig);
	free(mine);
	free(orig);
}*/
