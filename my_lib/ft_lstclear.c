/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:39:36 by mevangel          #+#    #+#             */
/*   Updated: 2023/04/12 20:05:09 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
