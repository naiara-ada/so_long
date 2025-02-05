/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:48:07 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/12 12:48:09 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_parameters(int ac, char **av, t_game *game)
{
	char	*extension;
	int		len_str;
	int		result;

	if (ac < 2)
		error_list("Error. You have to include a map.", game);
	else if (ac > 2)
		error_list("Error. Too many arguments.", game);
	else
	{
		len_str = ft_strlen(av[1]);
		extension = ft_substr(av[1], len_str - 4, 4);
		result = ft_strncmp(extension, ".ber", 4);
		free(extension);
		if (result != 0)
			error_list("Error. Incorrect extension (.ber)", game);
		extension = ft_substr(av[1], len_str - 5, 5);
		result = ft_strncmp(extension, "/.ber", 5);
		free(extension);
		if (result == 0)
			error_list("Error. file without name", game);
	}
	game->map.flag = 0;
}

void	check_rows_cols(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.cols)
	{
		if (game->map.full[0][i] != WALL)
			error_free("The top edge is not surrounded by walls", game);
		if (game->map.full[game->map.rows - 1][i] != WALL)
			error_free("The bottom edge is not surrounded by walls.", game);
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			error_free("The left edge is not surrounded by walls.", game);
		if (game->map.full[i][game->map.cols - 1] != WALL)
			error_free("The right edge is not surrounded by walls", game);
		i++;
	}
}

void	check_map_size(t_game *game)
{
	if (game->map.cols == game->map.rows)
		error_free("Error. the map must be a rectangle.", game);
	if (game->map.exit != 1)
		error_free("Error. Must be just 1 exit\n", game);
	if (game->map.players != 1)
		error_free("Error. Must be just 1 player\n", game);
	if (game->map.collects < 1)
		error_free("Error. Must be 1 collectables or more\n", game);
	if (game->map.walls < 12)
		error_free("Error. Must be 12 or more walls", game);
}

static void	check_map_colectables(t_game *game, int x, int y)
{
	if (game->map.full[x][y] == WALL)
		game->map.walls++;
	else if (game->map.full[x][y] == FLOOR)
		game->map.floor++;
	else if (game->map.full[x][y] == COLLECTIVES)
		game->map.collects++;
	else if (game->map.full[x][y] == EXIT)
	{
		game->map.exit++;
		game->exit.x = x;
		game->exit.y = y;
	}
	else if (game->map.full[x][y] == PLAYER)
	{
		game->map.players++;
		game->player.x = x;
		game->player.y = y;
	}
	else
		error_free("Error. The map is not valid", game);
}

void	check_colectables(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.rows)
	{
		y = 0;
		while (y < game->map.cols)
		{
			check_map_colectables(game, x, y);
			y++;
		}
		x++;
	}
}
