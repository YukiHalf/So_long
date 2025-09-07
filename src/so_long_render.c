/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:08:48 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/07 16:30:12 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

uint32_t get_tile_color(char tile)
{
	if (tile == '1')
		return (COLOR_WALL);
	else if (tile == 'P')
		return (COLOR_PLAYER);
	else if (tile == 'C')
		return (COLOR_COLLECT);
	else if (tile == 'E')
		return (COLOR_EXIT);
	return (COLOR_FLOOR);
}

void 	fill_tile_area(t_so_long *game, int start_x , int start_y, uint32_t color)
{
	int x;
	int y;

	y = start_y;
	while(y < start_y + TILE_SIZE && y < HEIGHT)
	{
		x =start_x;
		while(x < start_x * TILE_SIZE  && x < WIDTH)
		{
			if(x >= 0 && y >= 0)
				mlx_put_pixel(game->image,x,y,color);
			x++;
		}
		y++;
	}
}

void 	draw_tile_border(t_so_long *game , int start_x, int start_y)
{
	int i;

	i = 0;
	while(i < TILE_SIZE && start_x + i < WIDTH)
	{
		if(start_x + i >= 0 && start_y >= 0 && start_y < HEIGHT)
			mlx_put_pixel(game->image, start_x + i,start_y , COLOR_BORDER);
		if(start_x + i >= 0 && start_y + TILE_SIZE - 1 < HEIGHT)
			mlx_put_pixel(game->image, start_x +i, start_y + TILE_SIZE - 1,COLOR_BORDER);
		i++;
		}
	i = 0;
	while(i < TILE_SIZE && start_y + i < HEIGHT)
	{
		if(start_y + i >= 0 && start_x >= 0 && start_y < WIDTH)
			mlx_put_pixel(game->image,start_x, start_y + i , COLOR_BORDER);
		if(start_y + i >= 0 && start_x + TILE_SIZE - 1 < WIDTH)
			mlx_put_pixel(game->image,start_x + TILE_SIZE - 1 ,start_y +i ,COLOR_BORDER);
		i++;
		}
}

void	calculate_map_offset(t_so_long *game , int *offset_x, int *offset_y)
{
	int game_img_height = game->map->rows * TILE_SIZE;
	int game_img_width = game->map->cols * TILE_SIZE;
	*offset_x = (HEIGHT - game_img_height ) / 2;
	*offset_y = (WIDTH - game_img_width) / 2;
	if(*offset_x < 0)
		*offset_x = 0;
	if(*offset_y < 0)
		*offset_y = 0;
}

void	draw_tile(t_so_long *game, int map_x, int map_y,uint32_t color)
{
	int start_x;
	int start_y;
	int offset_x;
	int offset_y;

	calculate_map_offset(game, &offset_x,&offset_y);
	start_x = offset_x + (map_x * TILE_SIZE);
	start_y = offset_y + (map_y * TILE_SIZE);
	fill_tile_area(game, start_x, start_y,color);
	draw_tile_border(game,start_x,start_y);
}
