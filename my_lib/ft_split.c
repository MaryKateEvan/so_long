/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:56:12 by mevangel          #+#    #+#             */
/*   Updated: 2023/10/27 05:20:31 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substrings(char *s, char c)
{
	size_t	num;
	size_t	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

static size_t	ft_substring_length(char *sub, char c)
{
	size_t	len;

	len = 0;
	while (sub[len] != '\0' && sub[len] != c)
		len++;
	return (len);
}

static void	ft_free_final(char **final)
{
	int	i;

	i = 0;
	while (final[i] != NULL)
	{
		free(final[i]);
		i++;
	}
	free(final);
}

static char	**ft_main_part(char const *s, char c, char **final)
{
	int		i;
	int		j;
	size_t	sub_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		sub_len = ft_substring_length((char *)(s + i), c);
		final[j] = ft_substr((s + i), 0, sub_len);
		if (final[j] == NULL)
		{
			ft_free_final(final);
			return (NULL);
		}
		i = i + sub_len;
		j++;
	}
	final[j] = NULL;
	return (final);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	num_cal;

	if (s == NULL)
		return (NULL);
	num_cal = ft_count_substrings((char *)s, c) + 1;
	final = (char **)ft_calloc(num_cal, sizeof(char *));
	if (final == NULL)
		return (NULL);
	return (ft_main_part(s, c, final));
}
