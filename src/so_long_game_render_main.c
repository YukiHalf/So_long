/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_render_main.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:42:02 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/07 16:38:13 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_game(t_so_long *game)
{
	int x;
	int y;
	char tile;
	uint32_t color;
// In your render_game function, add:
printf("Rendering game...\n");
	y = 0;
	while((uint32_t)y < game->image->height)
	{
		x = 0;
		while((uint32_t)x < game->image->width)
		{
			mlx_put_pixel(game->image ,x ,y , COLOR_BORDER);
			x++;
		}
	y++;
	}
	y = 0;
	while(y < game->map->rows)
	{
		x = 0;
		while(x < game->map->cols)
		{
			tile = game->map->map_grid[y][x];
			color = get_tile_color(tile);
			draw_tile(game, x ,y ,color);
			x++;
		}
		y++;
	}
}

