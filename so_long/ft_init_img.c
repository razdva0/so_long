/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:28:34 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:28:35 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_game *game)
{
	char	*rp;
	int		img_w;
	int		img_h;

	rp = "img/p_d.xpm";
	game->player_de = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
	rp = "img/p_r.xpm";
	game->player_r = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
	rp = "img/p_l.xpm";
	game->player_l = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
	rp = "img/p_u.xpm";
	game->player_u = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
	rp = "img/1.xpm";
	game->wall = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
	rp = "img/0.xpm";
	game->back = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
	rp = "img/e.xpm";
	game->exit = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
	rp = "img/c.xpm";
	game->coin = mlx_xpm_file_to_image(game->mlx, rp, &img_w, &img_h);
}
