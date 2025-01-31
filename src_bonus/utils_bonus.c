/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:14:24 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/19 12:14:28 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	load_images(t_game *game)
{
	mlx_texture_t	*texture;
	
	texture = mlx_load_png(WALL_SPRITE);
	if(!texture)
		error_free("Error loading wall texture", game);
	game->images->wall_img = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->wall_img)
		error_free("Error converting wall image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(FLOOR_SPRITE);
	if (!texture)
		error_free("Error loading floor texture", game);
	game->images->floor_img = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->floor_img)
		error_free("Error converting floor image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(CHIP_SPRITE);
	if (!texture)
		error_free("Error loading collective texture", game);
	game->images->collect_img = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->collect_img)
		error_free("Error converting collective image", game);
	mlx_delete_texture(texture);
}

void	load_numbers(t_game *game)
{
	mlx_texture_t	*texture;
	
	texture = mlx_load_png(ZERO_IMG);
	if(!texture)
		error_free("Error loading zero texture", game);
	game->images->numbers[0] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[0])
		error_free("Error converting zero image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(ONE_IMG);
	if(!texture)
		error_free("Error loading one texture", game);
	game->images->numbers[1] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[1])
		error_free("Error converting one image", game);
	mlx_delete_texture(texture);	
	texture = mlx_load_png(TWO_IMG);
	if (!texture)
		error_free("Error loading two texture", game);
	game->images->numbers[2] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[2])
		error_free("Error converting two image", game);
	mlx_delete_texture(texture);	
	texture = mlx_load_png(THREE_IMG);
	if (!texture)
		error_free("Error loading three texture", game);
	game->images->numbers[3] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[3])
		error_free("Error converting three image", game);
	mlx_delete_texture(texture);	
	texture = mlx_load_png(FOUR_IMG);
	if (!texture)
		error_free("Error loading four texture", game);
	game->images->numbers[4] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[4])
		error_free("Error converting four image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(FIVE_IMG);
	if (!texture)
		error_free("Error loading five texture", game);
	game->images->numbers[5] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[5])
		error_free("Error converting five image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(SIX_IMG);
	if (!texture)
		error_free("Error loading six texture", game);
	game->images->numbers[6] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[6])
		error_free("Error converting six image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(SEVEN_IMG);
	if (!texture)
		error_free("Error loading seven texture", game);
	game->images->numbers[7] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[7])
		error_free("Error converting seven image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(EIGHT_IMG);
	if (!texture)
		error_free("Error loading eight texture", game);
	game->images->numbers[8] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[8])
		error_free("Error converting eight image", game);
	mlx_delete_texture(texture);
	texture = mlx_load_png(NINE_IMG);
	if (!texture)
		error_free("Error loading nine texture", game);
	game->images->numbers[9] = mlx_texture_to_image(game->mlx, texture);
	if (!game->images->numbers[9])
		error_free("Error converting nine image", game);
	mlx_delete_texture(texture);
}

void	free_game_map(char **mapi)
{
	int	i;

	if (!mapi || !*mapi)
		error_general("Map data not found or invalid.");
	i = 0;
	while (mapi[i] != NULL)
	{
		free(mapi[i]);
		i++;
	}
	free(mapi);
}

void	free_map_copy(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
