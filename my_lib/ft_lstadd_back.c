/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:04:49 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:30:56 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	cp = *lst;
	while (cp->next != NULL)
		cp = cp->next;
	cp->next = new;
}
