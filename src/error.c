/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:40:04 by narrospi          #+#    #+#             */
/*   Updated: 2024/12/12 12:40:07 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_free(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	if (game->map.full)
		free_game_map(game->map.full);
	free_images(game);
	if (game->map.copy != NULL)
		free_map_copy(game->map.copy, game->map.cols);
	exit(1);
}

void	error_general(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	error_list(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	free(game);
	exit(1);
}

void	error_map(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	free_game_map(game->map.full);
	free(game);
	exit(1);
}
