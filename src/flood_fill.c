/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:47:25 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/12 16:47:28 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_map(t_game *game)
{
	int	x;
	int	i;

	i = 0;
	x = game->map.rows + 1;
	game->map.copy = (char **)malloc(sizeof (char *) * x);
	if (!game->map.copy)
		error_free("Error. ", game);
	while (i < game->map.rows)
	{
		game->map.copy[i] = (char *)malloc(game->map.cols + 1 * sizeof(char));
		if (!game->map.copy[i])
			error_free("Error allocating memory", game);
		ft_strlcpy(game->map.copy[i], game->map.full[i], game->map.cols + 1);
		i++;
	}
	game->map.copy[i] = NULL;
}

void	flood_fill(t_game *game, int x, int y, char character)
{
	if (x < 0 || x >= game->map.rows || y < 0 || y >= game->map.cols)
		return ;
	game->map.copy[x][y] = character;
	if (ft_strchr(IS_FILLED, game->map.copy[x - 1][y]) == NULL)
		flood_fill(game, x - 1, y, character);
	if (ft_strchr(IS_FILLED, game->map.copy[x][y - 1]) == NULL)
		flood_fill(game, x, y - 1, character);
	if (ft_strchr(IS_FILLED, game->map.copy[x + 1][y]) == NULL)
		flood_fill(game, x + 1, y, character);
	if (ft_strchr(IS_FILLED, game->map.copy[x][y + 1]) == NULL)
		flood_fill(game, x, y + 1, character);
}

void	find_remain_object(t_game *game, int rows, int cols)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (ft_strchr(CHAR_COPY, game->map.copy[x][y]) != NULL)
				error_free("the game is not playable", game);
			y++;
		}
		x++;
	}
	free_map_copy(game->map.copy, game->map.rows);
}

void	check_gameable(t_game *game)
{
	flood_fill(game, game->player.x, game->player.y, 'X');
	find_remain_object(game, game->map.rows, game->map.cols);
}
