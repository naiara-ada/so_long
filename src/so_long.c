/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:30:44 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/02 14:30:49 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	victory_game(t_game *game)
{
	game->moves++;
	ft_printf("moves: %d\n", game->moves);
	ft_printf("you win");
	clean_up(game);
	exit (0);
}

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = param;
	x = game->player.x;
	y = game->player.y;
	if (keydata.action == MLX_PRESS && (keydata.key == MLX_KEY_W
			|| keydata.key == MLX_KEY_UP))
		player_moves(game, x - 1, y, game->images->back_img);
	else if (keydata.action == MLX_PRESS && (keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_DOWN))
		player_moves(game, x + 1, y, game->images->front_img);
	else if (keydata.action == MLX_PRESS && (keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_LEFT))
		player_moves(game, x, y - 1, game->images->left_img);
	else if (keydata.action == MLX_PRESS && (keydata.key == MLX_KEY_D
			|| keydata.key == MLX_KEY_RIGHT))
		player_moves(game, x, y + 1, game->images->right_img);
	else if ((keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE))
		close_win(game);
}

void	close_win(void	*param)
{
	t_game	*game;

	game = param;
	clean_up(game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	check_parameters(ac, av, game);
	init_map(game, av[1]);
	init_vars(game);
	check_map(game);
	init_game(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_close_hook(game->mlx, &close_win, game);
	mlx_loop(game->mlx);
	clean_up(game);
}
