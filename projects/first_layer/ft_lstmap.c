/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:14:24 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/11 17:12:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;

	if (!lst)
		return (0);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (0);
	last = first;
	lst = lst->next;
	while (lst)
	{
		if (lst->content)
		{
			last->next = ft_lstnew(f(lst->content));
			last = last->next;
			lst = lst->next;
		}
		else
		{
			del(lst->content);
			free(lst);
		}
	}
	return (first);
}
