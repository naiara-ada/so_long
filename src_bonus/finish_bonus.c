/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:01:55 by narrospi          #+#    #+#             */
/*   Updated: 2025/01/15 12:01:58 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_wall(t_game *game)
{
	int	i;

	i = 0;
	if (game->images->wall_img)
		mlx_delete_image(game->mlx, game->images->wall_img);
	if (game->images->floor_img)
		mlx_delete_image(game->mlx, game->images->floor_img);
	if (game->images->collect_img)
		mlx_delete_image(game->mlx, game->images->collect_img);
	while (i < 10)
	{
		if (game->images->numbers[i])
			mlx_delete_image(game->mlx, game->images->numbers[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (game->images->balls[i])
			mlx_delete_image(game->mlx, game->images->balls[i]);
		i++;
	}
}

void	free_images(t_game *game)
{
	if (!game->images)
		return ;
	free_wall(game);
	if (game->images->front_img)
		mlx_delete_image(game->mlx, game->images->front_img);
	if (game->images->back_img)
		mlx_delete_image(game->mlx, game->images->back_img);
	if (game->images->right_img)
		mlx_delete_image(game->mlx, game->images->right_img);
	if (game->images->left_img)
		mlx_delete_image(game->mlx, game->images->left_img);
	if (game->images->exit_close_img)
		mlx_delete_image(game->mlx, game->images->exit_close_img);
	if (game->images->open_img)
		mlx_delete_image(game->mlx, game->images->open_img);
	if (game->images->exit_player_img)
		mlx_delete_image(game->mlx, game->images->exit_player_img);
	free(game->images);
	if (game->exit_sprite)
		mlx_delete_image(game->mlx, game->exit_sprite);
	if (game->player_sprite)
		mlx_delete_image(game->mlx, game->player_sprite);
	game->images = NULL;
}

void	clean_up(t_game *game)
{
	free_images(game);
	free_game_map(game->map.full);
	mlx_terminate(game->mlx);
	free(game);
}

void	print_counter(t_game *game)
{
	int	digits;
	int	i;
	int	moves;
	int	x_size;

	moves = game->moves;
	digits = count_digits(moves);
	while (digits > 0)
	{
		i = moves % 10;
		x_size = (digits - 1) * SIZE;
		mlx_image_to_window(game->mlx, game->images->numbers[i], x_size, 0);
		moves = moves / 10;
		digits--;
	}
}
