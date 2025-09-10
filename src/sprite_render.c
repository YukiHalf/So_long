/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:26:41 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/10 21:17:47 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_background(t_so_long *game)
{
	int			x;
	int			y;
	mlx_image_t	*floor_sprite;

	floor_sprite = (mlx_image_t *)game->sprites.floor;
	if (!floor_sprite)
		return ;
	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			draw_sprite_at_cords(game, floor_sprite, x, y);
			x++;
		}
		y++;
	}
}

void	render_game_objects(t_so_long *game)
{
	int			y;
	int			x;
	mlx_image_t	*sprite;
	char		tile;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			tile = game->map->map_grid[y][x];
			if (tile != '0')
			{
				sprite = get_tile_sprite(game, tile);
				if (sprite)
					draw_sprite_at_cords(game, sprite, x, y);
			}
			x++;
		}
		y++;
	}
}

void	render_player_only(t_so_long *game)
{
	mlx_image_t	*player_sprite;

	clear_player_sprites(game);
	player_sprite = get_player_direction(game);
	if (player_sprite)
		draw_sprite_at_cords(game, player_sprite, game->map->player_x,
			game->map->player_y);
}

void	render_collectibles_only(t_so_long *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			tile = game->map->map_grid[y][x];
			if (tile == 'C')
				draw_sprite_at_cords(game,
					(mlx_image_t *)game->sprites.collectible, x, y);
			x++;
		}
		y++;
	}
}
