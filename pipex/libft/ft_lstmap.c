/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 01:30:03 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/19 03:44:14 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*new_element;

	if (lst)
	{
		new = ft_lstnew(f(lst->content));
		lst = lst->next;
	}
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
			ft_lstdelone(tmp, del);
		ft_lstadd_back(&new, new_element);
		tmp = lst;
		lst = lst->next;
	}
	return (new);
}
