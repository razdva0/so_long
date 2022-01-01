/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:28:29 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/30 23:28:30 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "mlx/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define PIX 40

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		size_x;
	int		size_y;
	void	*player_u;
	void	*player_l;
	void	*player_r;
	void	*player_d;
	void	*player_de;
	void	*back;
	void	*wall;
	void	*exit;
	void	*coin;
	int		coins;
	int		p_x;
	int		p_y;
	int		coll;
	int		steps;
	int		p;
}				t_game;

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *s);
char	*ft_charjoin(char *s1, char c);
char	**ft_map_parsing(t_game *game, char *av);
int		ft_pars(t_game *g, char **str);
void	ft_player_coord(t_game *g, int i, int j);
char	**ft_split(char const *s, char c);
size_t	ft_count_words(char const *s, char c);
void	ft_init_img(t_game *game);
void	ft_put_img(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
void	ft_move(t_game *g, char c, int key);
int		ft_exit(t_game *game);
void	exit_str(char *str_error, int i);
void	ft_win(t_game *g);
void	ft_put_background(t_game *data);

#endif
