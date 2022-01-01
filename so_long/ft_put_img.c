/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:28:11 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:28:12 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_game *game)
{
	int	k[2];

	k[0] = -1;
	while (++k[0] < game->size_y)
	{
		k[1] = -1;
		while (++k[1] < game->size_x)
		{
			if (game->map[k[0]][k[1]] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall, k[1] * PIX, k[0] * PIX);
			if (game->map[k[0]][k[1]] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->back, k[1] * PIX, k[0] * PIX);
			if (game->map[k[0]][k[1]] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_r, k[1] * PIX, k[0] * PIX);
			if (game->map[k[0]][k[1]] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->coin, k[1] * PIX, k[0] * PIX);
			if (game->map[k[0]][k[1]] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit, k[1] * PIX, k[0] * PIX);
		}
	}
}
