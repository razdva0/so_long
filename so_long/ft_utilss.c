/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:28:56 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:28:59 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_background(t_game *g)
{
	int		y;
	int		x;

	y = 0;
	while (y < g->size_y)
	{
		x = 0;
		while (x < g->size_x)
		{
			mlx_put_image_to_window(g->mlx, g->win, g->back, x, y);
			x += PIX;
		}
		y += PIX;
	}
}

void	ft_player_coord(t_game *g, int i, int j)
{
	g->p += 1;
	g->p_x = j;
	g->p_y = i;
}

void	exit_str(char *str, int i)
{
	printf("%s", str);
	if (i == 0)
		printf("\n");
	exit(EXIT_FAILURE);
}
