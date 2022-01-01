/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:28:41 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:28:42 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_map_check(t_game *g, char **str)
{
	size_t	i;
	size_t	j;
	int		sim;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				g->coins += 1;
			if (str[i][j] == 'E')
				sim = 1;
			if (str[i][j] == 'P')
				ft_player_coord(g, i, j);
			j++;
		}
		i++;
	}
	if (g->coins == 0 || sim != 1 || g->p != 1)
		return (0);
	return (1);
}

static int	ft_one(char **str)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[0][j] != '1' && str[i][0] != '1' && str[i][len] != '1')
				return (0);
			j++;
		}
		i++;
	}
	j = 0;
	while (str[i - 1][j])
	{
		if (str[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	ft_search(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_pars(t_game *g, char **str)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_search("01CEP", str[i][j]) == 0)
				return (0);
			if (ft_one(str) == 0)
				return (0);
			j++;
		}
		if (ft_strlen(str[i]) != len)
			return (0);
		i++;
	}
	if (ft_map_check(g, str) == 0)
		return (0);
	return (1);
}

char	**ft_map_parsing(t_game *game, char *av)
{
	int		fd;
	char	**str;
	char	*line;
	char	c;

	fd = open(av, O_RDONLY);
	line = ft_strdup("");
	while (read(fd, &c, 1) > 0)
		line = ft_charjoin(line, c);
	str = ft_split(line, '\n');
	game->size_x = (ft_strlen(str[0]));
	game->size_y = (ft_count_words(line, '\n'));
	close(fd);
	free(line);
	return (str);
}
