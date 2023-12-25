/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:39:36 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:31:01 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cp;
	t_list	*save;

	if (!lst || !del)
		return ;
	cp = *lst;
	while (cp != NULL)
	{
		save = cp->next;
		del(cp->content);
		free(cp);
		cp = save;
	}
	*lst = NULL;
}
