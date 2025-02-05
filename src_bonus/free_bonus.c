/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:44:02 by narrospi          #+#    #+#             */
/*   Updated: 2025/02/03 14:44:05 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
