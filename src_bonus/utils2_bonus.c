/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:00:00 by narrospi          #+#    #+#             */
/*   Updated: 2025/02/03 11:00:02 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_balls2(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(BALL4);
	if (!texture)
		error_free("Error converting ball4 texture", game);
	game->images->balls[3] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->balls[3])
		error_free("Error converting ball4 images", game);
	mlx_delete_texture(texture);
}

void	load_balls(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(BALL1);
	if (!texture)
		error_free("Error converting ball1 texture", game);
	game->images->balls[0] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->balls[0])
		error_free("Error converting ball1 images", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(BALL2);
	if (!texture)
		error_free("Error converting ball2 texture", game);
	game->images->balls[1] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->balls[1])
		error_free("Error converting ball2 images", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(BALL3);
	if (!texture)
		error_free("Error converting ball3 texture", game);
	game->images->balls[2] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->balls[2])
		error_free("Error converting ball3 images", game);
	mlx_delete_texture(texture);
	load_balls2(game);
}

void	change_ball_sprite(t_game *game, int i)
{
	game->images->collect_img = game->images->balls[i];
	collect_animation(game);
}

void	collect_animation(t_game *game)
{
	int	x;
	int	y;
	int	x_s;
	int	y_s;

	x = 0;
	while (x < game->map.rows)
	{
		y = 0;
		while (y < game->map.cols)
		{
			x_s = x * SIZE;
			y_s = y * SIZE;
			if (game->map.full[x][y] == COLLECTIVES)
				mlx_image_to_window(game->mlx,
					game->images->collect_img, y_s, x_s);
			y++;
		}
		x++;
	}
}
