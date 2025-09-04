/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:52:54 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/04 18:16:56 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void map_check(t_map *map)
{
	if(!map || !map->map_grid)
		display_error(INVALID_MAP,1);
	if(map->rows < 3 || map->cols < 3)
		display_error("Map to small (minimum 3x3)",1);
	wall_check(map);
	elements_check(map);
	if(!path_check(map))
		display_error("No valid path to exit or collectibles",1);
}

void elements_check(t_map *map)
{
	if (map->player_count != 1)
        display_error("Map must have exactly one player (P)", 1);
    if (map->exit_count != 1)
        display_error("Map must have exactly one exit (E)", 1);
    if (map->collectible_count < 1)
        display_error("Map must have at least one collectible (C)", 1);
}

void wall_check(t_map *map)
{
	int i;
	int j;

	i = 0;
	while(i < map->rows)
	{
		j = 0;
		while(j < map->cols)
		{
			if((i = 0 || i = map->rows - 1 )map->map_grid[i][j] != '1')
			display_error("Map must be surrounded by walls", 1);
			if((j = 0 || j = map->cols - 1 )map->map_grid[i][j] != '1')
			display_error("Map must be surrounded by walls", 1);
			j++;
		}
		i++;
	}
}
