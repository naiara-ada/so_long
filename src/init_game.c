/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:35:57 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/10 14:35:59 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_render_map(t_game *game, int x, int y)
{
	if (game->map.full[x][y] == WALL)
		render_wall(game, y, x);
	if (game->map.full[x][y] == FLOOR)
		render_floor(game, y, x);
	if (game->map.full[x][y] == COLLECTIVES)
		render_collects(game, y, x);
	if (game->map.full[x][y] == PLAYER)
	{
		render_player(game, y, x);
		game->player.x = x;
		game->player.y = y;
	}
	if (game->map.full[x][y] == EXIT)
	{
		render_exit(game, y, x);
		game->exit.x = x;
		game->exit.y = y;
	}
}

void	player_moves(t_game *game, int new_x, int new_y, mlx_image_t *sprite)
{
	game->player_sprite = sprite;
	if (game->map.full[new_x][new_y] == EXIT)
		handle_exit(game, new_x, new_y);
	else if (game->map.full[new_x][new_y] == FLOOR
			|| game->map.full[new_x][new_y] == COLLECTIVES)
		handle_floor_or_collective(game, new_x, new_y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->images = malloc(sizeof(t_images));
	if (!game->images)
		error_free("Error allocating memory for images", game);
	load_images(game);
	while (x < game->map.rows)
	{
		y = 0;
		while (y < game->map.cols)
		{
			check_render_map(game, x, y);
			y++;
		}
		x++;
	}
	game->map.collects_total = game->map.collects;
}

void	init_game(t_game *game)
{
	int	col_size;

	col_size = game->map.cols * SIZE;
	game->mlx = mlx_init(col_size, game->map.rows * SIZE, "so_long", true);
	if (!game->mlx)
		error_free("error loading mlx", game);
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.collects = 0;
	render_map(game);
}
