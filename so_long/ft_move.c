/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:28:03 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:28:05 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_exit(game);
	else if (keycode == W)
		ft_move(game, 'y', UP);
	else if (keycode == A)
		ft_move(game, 'x', LEFT);
	else if (keycode == S)
		ft_move(game, 'y', DOWN);
	else if (keycode == D)
		ft_move(game, 'x', RIGHT);
	if (game->map[game->p_y][game->p_x] == 'E')
		ft_win(game);
	return (0);
}

static void	ft_player_move(t_game *g, char pos, int key)
{
	if (pos == 'y' && key == UP)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->player_u,
			(g->p_x * PIX), (g->p_y * PIX));
	}
	if (pos == 'x' && key == LEFT)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->player_l,
			(g->p_x * PIX), (g->p_y * PIX));
	}
	if (pos == 'y' && key == DOWN)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->player_de,
			(g->p_x * PIX), (g->p_y * PIX));
	}
	if (pos == 'x' && key == RIGHT)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->player_r,
			(g->p_x * PIX), (g->p_y * PIX));
	}
}

static void	ft_coll(t_game *g, char c, int key)
{
	if (g->map[g->p_y][g->p_x] == 'C')
	{
		g->coll++;
		g->map[g->p_y][g->p_x] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->back,
			(g->p_x * PIX), (g->p_y * PIX));
	}
	ft_player_move(g, c, key);
	mlx_do_sync(g->mlx);
}

void	ft_move(t_game *g, char c, int key)
{
	mlx_put_image_to_window(g->mlx, g->win, g->back,
		(g->p_x * PIX), (g->p_y * PIX));
	if ((c == 'y' && g->map[g->p_y + 1 * key][g->p_x] != '1')
				&& ((g->map[g->p_y + 1 * key][g->p_x] != 'E')
				|| g->coll == g->coins))
	{
		g->p_y = g->p_y + 1 * key;
		printf("Move %d times.\n", ++g->steps);
	}
	else if ((c == 'x' && g->map[g->p_y][g->p_x + 1 * key] != '1')
				&& ((g->map[g->p_y][g->p_x + 1 * key] != 'E')
				|| g->coll == g->coins))
	{
		g->p_x = g->p_x + 1 * key;
		printf("Move %d times.\n", ++g->steps);
	}
	else if (c == 'y' && g->map[g->p_y + 1 * key][g->p_x] == 'E'
		&& g->coll != g->coins)
		printf("Collection all diamonds before leaving\n");
	else if (c == 'x' && g->map[g->p_y][g->p_x + 1 * key] == 'E'
		&& g->coll != g->coins)
		printf("Collection all diamonds before leaving\n");
	ft_coll(g, c, key);
}

void	ft_win(t_game *g)
{
	printf("Congratulations, you found all the Diamonds and the exit.\n");
	printf("You won!\n");
	printf("Is %d moves really the best you can do?\n", g->steps);
	exit(EXIT_SUCCESS);
}
