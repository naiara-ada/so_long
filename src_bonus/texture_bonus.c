/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:39:51 by narrospi          #+#    #+#             */
/*   Updated: 2025/01/15 15:39:54 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_wall(t_game *game, int x, int y)
{
	int				x_size;
	
	x_size = x * SIZE;
	mlx_image_to_window(game->mlx, game->images->wall_img, x_size, y * SIZE);
	game->map.walls++;	
}

void	render_floor(t_game *game, int x, int y)
{
	int				x_size;
	int				y_size;

	x_size = x * SIZE;
	y_size = y * SIZE;
	mlx_image_to_window(game->mlx, game->images->floor_img, x_size, y_size);
	game->map.floor++;
}

void	render_collects(t_game *game, int x, int y)
{
	int				x_siz;
	int				y_siz;

	x_siz = x * SIZE;
	y_siz = y * SIZE;
	mlx_image_to_window(game->mlx, game->images->collect_img, x_siz, y_siz);
	game->map.collects++;
}

void	render_player(t_game *game, int x, int y)
{
	mlx_texture_t	*player_texture;

	player_texture = mlx_load_png(FRONT_PLAYER_SPRITE);
	if (!player_texture)
		error_free("Error converting front player texture", game);
	game->images->front_img = mlx_texture_to_image(game->mlx, player_texture);
	mlx_delete_texture(player_texture);
	player_texture = mlx_load_png(LEFT_PLAYER_SPRITE);
	if (!player_texture)
		error_free("Error converting left player texture", game);
	game->images->left_img = mlx_texture_to_image(game->mlx, player_texture);
	mlx_delete_texture(player_texture);
	player_texture = mlx_load_png(BACK_PLAYER_SPRITE);
	if (!player_texture)
		error_free("Error converting player texture", game);
	game->images->back_img = mlx_texture_to_image(game->mlx, player_texture);
	mlx_delete_texture(player_texture);
	player_texture = mlx_load_png(RIGHT_PLAYER_SPRITE);
	if (!player_texture)
		error_free("Error converting player texture", game);
	game->images->right_img = mlx_texture_to_image(game->mlx, player_texture);
	mlx_delete_texture(player_texture);
	game->player_sprite = game->images->front_img;
	mlx_image_to_window(game->mlx, game->player_sprite, x * SIZE, y * SIZE);
}

void	render_exit(t_game *game, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(EXITE_SPRITE);
	if (!texture)
		error_free("Error converting exit texture", game);
	game->images->exit_close_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(EXITE_SPRITE_OPEN);
	if (!texture)
		error_free("Error converting exit open texture", game);
	game->images->open_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(EXIT_PLAYER_SPRITE);
	if (!texture)
		error_free("Error converting exit player texture", game);
	game->images->exit_player_img = mlx_texture_to_image(game->mlx, texture);
	game->exit_sprite = game->images->exit_close_img;
	mlx_image_to_window(game->mlx, game->exit_sprite, x * SIZE, y * SIZE);
	mlx_delete_texture(texture);
}
