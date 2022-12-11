/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:00:18 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/11 02:46:51 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*free_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	return (NULL);
}

char	**ft_nbwords(char const *s, char *c)
{
	int		i;
	int		n;
	char	**split;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(c, s[i]))
			i++;
		if (s[i])
			n++;
		while (s[i] && !ft_strchr(c, s[i]))
			i++;
	}
	split = ((char **)ft_calloc(sizeof(*split), (n + 1)));
	return (split);
}

char	**ft_split_aux(char const *s, char *c, char	**split)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(c, s[i]))
			i++;
		if (s[i] == 0)
			return (split);
		len = 0;
		while (s[i + len] && !ft_strchr(c, s[i + len]))
			len++;
		word = ((char *)ft_calloc(sizeof(*word), (len + 1)));
		if (!word)
			return (free_tab(split));
		len = 0;
		while (s[i] && !ft_strchr(c, s[i]))
			word[len++] = s[i++];
		split[j++] = word;
	}
	return (split);
}

char	**ft_split(char const *s, char *c)
{
	char	**split;

	split = ft_nbwords(s, c);
	if (!split)
		return (NULL);
	return (ft_split_aux(s, c, split));
}
