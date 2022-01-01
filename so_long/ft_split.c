/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:28:47 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:28:48 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		len = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && i - start < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

size_t	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	const char	*start;
	char		**split;

	split = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split || !s)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		i = 0;
		while (*s && *s != c)
		{
			s++;
			i++;
		}
		if (*(s - 1) != c)
			split[j++] = ft_substr(start, 0, i);
	}
	split[j] = NULL;
	return (split);
}
