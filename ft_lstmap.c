/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:24:36 by junjun            #+#    #+#             */
/*   Updated: 2024/11/12 23:44:13 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list *new_node;
	t_list *new_lst;
	
	new_node = NULL;
	if (!lst ||!f)
	{
		return (NULL);
	}
	while (lst)
	{
		f(lst->content);
		new_node = ft_lstnew(lst);
		if (!new_node)
		{
			ft_lstdelone(new_node, del);
			return (NULL);
		}
		
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}