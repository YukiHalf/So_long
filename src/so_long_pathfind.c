/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pathfind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:36:51 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/10 21:17:29 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(char **temp_map, int x, int y, int rows, int cols,
		int *collectibles_found)
{
	if (x < 0 || x >= cols || y < 0 || y >= rows || temp_map[y][x] == '1'
		|| temp_map[y][x] == 'V')
		return ;
	if (temp_map[y][x] == 'C')
		(*collectibles_found)++;
	temp_map[y][x] = 'V';
	flood_fill(temp_map, x + 1, y, rows, cols, collectibles_found);
	flood_fill(temp_map, x - 1, y, rows, cols, collectibles_found);
	flood_fill(temp_map, x, y + 1, rows, cols, collectibles_found);
	flood_fill(temp_map, x, y - 1, rows, cols, collectibles_found);
}
