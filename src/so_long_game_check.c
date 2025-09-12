/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:52:54 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/12 18:45:35 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_check(t_map *map)
{
	if (!map || !map->map_grid)
		display_error(INVALID_MAP, 1);
	if (map->rows < 3 || map->cols < 3)
		display_error("Map to small (minimum 3x3)", 1);
	walls_check(map);
	elements_check(map);
	if (!path_check(map))
		display_error("No valid path to exit or collectibles", 1);
}

void	elements_check(t_map *map)
{
	if (map->player_count != 1)
		display_error("Map must have exactly one player (P)", 1);
	if (map->exit_count != 1)
		display_error("Map must have exactly one exit (E)", 1);
	if (map->collectible_count < 1)
		display_error("Map must have at least one collectible (C)", 1);
}

void	walls_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if ((i == 0 || i == map->rows - 1) && map->map_grid[i][j] != '1')
				display_error("Map must be surrounded by walls", 1);
			if ((j == 0 || j == map->cols - 1) && map->map_grid[i][j] != '1')
				display_error("Map must be surrounded by walls", 1);
			j++;
		}
		i++;
	}
}

char	**create_temp_map(t_map *map)
{
	char	**temp_map;
	int		i;
	int		j;

	temp_map = malloc(sizeof(char *) * map->rows);
	if (!temp_map)
		display_error(MALLOC, 1);
	i = -1;
	while (++i < map->rows)
	{
		temp_map[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!map->map_grid[i])
		{
			while (--i >= 0)
				free(map->map_grid[i]);
			free(map->map_grid);
			display_error(MALLOC, 1);
		}
		j = -1;
		while (++j < map->cols)
			temp_map[i][j] = map->map_grid[i][j];
		temp_map[i][j] = '0';
	}
	return (temp_map);
}

int	path_check(t_map *map)
{
	t_flood_data	flood_data;
	int				collectibles_found;
	int				exit_reachable;
	int				i;
	int				j;

	collectibles_found = 0;
	if (map->player_x == -1 || map->player_y == -1)
		return (0);
	fill_data_flood(&flood_data, map);
	flood_fill(&flood_data, map->player_x, map->player_y, &collectibles_found);
	i = -1;
	while (++i < map->rows && !exit_reachable)
	{
		j = -1;
		while (++j < map->cols && !exit_reachable)
		{
			if (map->map_grid[i][j] == 'E' && flood_data.temp_map[i][j] == 'V')
				exit_reachable = 1;
		}
	}
	free2d(flood_data.temp_map);
	return (collectibles_found == map->collectible_count && exit_reachable);
}
