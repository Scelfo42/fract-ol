/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:12:46 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/08 15:05:29 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		counter += 1;
		lst = lst->next;
	}
	return (counter);
}
