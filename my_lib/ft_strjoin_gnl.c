/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:02:10 by mevangel          #+#    #+#             */
/*   Updated: 2023/12/25 23:32:16 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	char	*joined;
	int		i;
	int		j;

	joined = ft_calloc(ft_strlen(stash) + ft_strlen(buffer) + 1, 1);
	if (!joined)
		return (NULL);
	i = -1;
	j = -1;
	while (stash[++i] != '\0')
		joined[i] = stash[i];
	while (buffer[++j] != '\0')
		joined[i + j] = buffer[j];
	free(stash);
	return (joined);
}
