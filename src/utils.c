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

#include "../includes/so_long.h"

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
