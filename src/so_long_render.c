/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:08:48 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/11 21:23:25 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

mlx_image_t	*get_player_direction(t_so_long *game)
{
	if (game->sprites.player->direction == 'R')
		return (game->sprites.player->right);
	if (game->sprites.player->direction == 'L')
		return (game->sprites.player->left);
	if (game->sprites.player->direction == 'U')
		return (game->sprites.player->up);
	if (game->sprites.player->direction == 'D')
		return (game->sprites.player->down);
	return (game->sprites.player->idle);
}

mlx_image_t	*get_tile_sprite(t_so_long *game, char tile)
{
	if (tile == '1')
		return ((mlx_image_t *)game->sprites.wall);
	else if (tile == 'P')
		return (get_player_direction(game));
	else if (tile == 'C')
		return ((mlx_image_t *)game->sprites.collectible);
	else if (tile == 'E' && game->collected == game->map->collectible_count)
		return ((mlx_image_t *)game->sprites.exit_open);
	else if (tile == 'E')
		return ((mlx_image_t *)game->sprites.exit);
	return ((mlx_image_t *)game->sprites.floor);
}

void	calculate_map_offset(t_so_long *game, int *offset_x, int *offset_y)
{
	int	game_img_height;
	int	game_img_width;

	game_img_height = game->map->rows * IMG_PXL;
	game_img_width = game->map->cols * IMG_PXL;
	*offset_x = (WIDTH - game_img_width) / 2;
	*offset_y = (HEIGHT - game_img_height) / 2;
	if (*offset_x < 0)
		*offset_x = 0;
	if (*offset_y < 0)
		*offset_y = 0;
}

void	draw_sprite_at_cords(t_so_long *game, mlx_image_t *sprite, int map_x,
		int map_y)
{
	int	start_x;
	int	start_y;
	int	offset_x;
	int	offset_y;

	if (!sprite)
		return ;
	calculate_map_offset(game, &offset_x, &offset_y);
	start_x = offset_x + (map_x * IMG_PXL);
	start_y = offset_y + (map_y * IMG_PXL);
	if (mlx_image_to_window(game->mlx, sprite, start_x, start_y) < 0)
	{
		printf("Error: Failed to render sprite at position (%d, %d)\n", map_x,
			map_y);
	}
}
