/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:08:41 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/09 18:28:45 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_2/ft_first_layer.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst->content)
		del(lst->content);
	free(lst);
}
