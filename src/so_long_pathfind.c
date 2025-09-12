/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pathfind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:36:51 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/12 18:43:32 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	fill_data_flood(t_flood_data *flood_data, t_map *map)
{
	flood_data->temp_map = create_temp_map(map);
	flood_data->rows = map->rows;
	flood_data->cols = map->cols;
}

void	flood_fill(t_flood_data *data, int x, int y, int *collectibles_found)
{
	if (x < 0 || x >= data->cols || y < 0 || y >= data->rows
		|| data->temp_map[y][x] == '1' || data->temp_map[y][x] == 'V')
		return ;
	if (data->temp_map[y][x] == 'C')
		(*(collectibles_found))++;
	data->temp_map[y][x] = 'V';
	flood_fill(data, x + 1, y, collectibles_found);
	flood_fill(data, x - 1, y, collectibles_found);
	flood_fill(data, x, y + 1, collectibles_found);
	flood_fill(data, x, y - 1, collectibles_found);
}
