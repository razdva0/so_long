/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:29:05 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:29:06 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_isber(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len < 5 || ft_strcmp(av + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("You gave up :(\n");
	printf("Is the map to hard for you?\n");
	exit(EXIT_SUCCESS);
}

t_game	*init_game(void)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	if (!g)
		exit(EXIT_FAILURE);
	g->mlx = NULL;
	g->win = NULL;
	g->map = NULL;
	g->size_x = 0;
	g->size_y = 0;
	g->player_de = NULL;
	g->player_l = NULL;
	g->player_r = NULL;
	g->player_u = NULL;
	g->back = NULL;
	g->wall = NULL;
	g->exit = NULL;
	g->coin = NULL;
	g->coins = 0;
	g->p_x = 0;
	g->p_y = 0;
	g->coll = 0;
	g->steps = 0;
	g->p = 0;
	return (g);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		exit_str("Error\nInvalid arguments, try again!", 0);
	if (ft_isber(av[1]) == 0)
		exit_str("Error\nInvalid map name, try again!", 0);
	game = init_game();
	game->map = ft_map_parsing(game, av[1]);
	if (ft_pars(game, game->map) == 0)
		exit_str("Error\nInvalid map, try another \".ber\" file!", 0);
	game->mlx = mlx_init();
	ft_init_img(game);
	mlx_new_window(game, game->size_x * PIX, game->size_y * PIX, "so_long");
	ft_put_img(game);
	mlx_key_hook(game->win, ft_key_hook, game);
	mlx_hook(game->win, 17, 1L << 2, ft_exit, game);
	mlx_loop(game);
	exit(EXIT_FAILURE);
}
