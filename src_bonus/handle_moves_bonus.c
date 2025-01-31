/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:23:10 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/17 11:23:12 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_map_cell(t_game *game, int x, int y)
{
	int	x_size;

	x_size = x * SIZE;
	if (game->map.full[x][y] == PLAYER)
		mlx_image_to_window(game->mlx, game->player_sprite, y * SIZE, x_size);
	else if (game->map.full[x][y] == FLOOR)
		render_floor(game, y, x);
	else if (game->map.full[x][y] == EXIT)
		mlx_image_to_window(game->mlx, game->exit_sprite, y * SIZE, x_size);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = game->player.x;
	last_y = game->player.y;
	game->player.x = new_x;
	game->player.y = new_y;
	if (game->map.full[last_x][last_y] != EXIT)
		game->map.full[last_x][last_y] = FLOOR;
	render_map_cell(game, last_x, last_y);
	if (game->map.full[new_x][new_y] != EXIT)
		game->map.full[new_x][new_y] = PLAYER;
	else
		game->exit_sprite = game->images->exit_player_img;
	render_map_cell(game, new_x, new_y);
	game->moves++;
	ft_printf("moves: %d\n", game->moves);
}

void	handle_exit(t_game *game, int new_x, int new_y)
{
	if (game->map.collects == 0)
		victory_game(game);
	else
		update_player_position(game, new_x, new_y);
}

void	handle_collective(t_game *game, int new_x, int new_y)
{
	int	x_s;
	int	y_s;

	x_s = game->exit.x * SIZE;
	y_s = game->exit.y * SIZE;
	if (game->map.full[new_x][new_y] == COLLECTIVES)
	{
		game->map.collects--;
		if (game->map.collects == 0)
			mlx_image_to_window(game->mlx, game->images->open_img, y_s, x_s);
	}
}

void	handle_floor_or_collective(t_game *game, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = game->player.x;
	last_y = game->player.y;
	if (game->map.full[last_x][last_y] == EXIT && game->map.collects > 0)
		game->exit_sprite = game->images->exit_close_img;
	else
		game->map.full[last_x][last_y] = FLOOR;
	handle_collective(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
}
