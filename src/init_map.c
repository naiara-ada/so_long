/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:41:16 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/09 13:41:19 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_game *game, char *file_map)
{
	int		map_fd;
	char	*map_temp;
	char	*line;

	map_fd = open(file_map, O_RDONLY);
	if (map_fd < 0)
		error_list("Error opening file", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		if (ft_strlen(line) < 3)
			game->map.flag = 1;
		map_temp = ft_strjoin_gnl(map_temp, line);
		free(line);
		game->map.rows++;
		line = get_next_line(map_fd);
	}
	free(line);
	close(map_fd);
	game->map.full = ft_split(map_temp, '\n');
	free(map_temp);
	if (game->map.flag == 1)
		error_map("error size map", game);
}

void	init_vars(t_game *game)
{
	game->map.collects = 0;
	game->map.cols = ft_strlen(game->map.full[0]);
	game->map.players = 0;
	game->map.exit = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->moves = 0;
}

static void	check_cols_size(t_game *game)
{
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(game->map.full[0]);
	while (game->map.full[i])
	{
		if (size != ft_strlen(game->map.full[i]))
			error_free("Error. Rows has different sizes", game);
		i++;
	}
}

void	check_map(t_game *game)
{
	check_cols_size(game);
	check_rows_cols(game);
	check_colectables(game);
	check_map_size(game);
	copy_map(game);
	check_gameable(game);
}
