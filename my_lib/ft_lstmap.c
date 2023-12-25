/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:44:00 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:31:13 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	temp = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (!new_lst)
			new_lst = new_node;
		else
			temp->next = new_node;
		temp = new_node;
		lst = lst->next;
	}
	return (new_lst);
}
