/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:16:23 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/09 18:02:34 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*e_node;

	if (lst && new)
	{
		if (*lst)
		{
			e_node = ft_lstlast(*lst);
			e_node->next = new;
		}
		else
			*lst = new;
	}
}	
