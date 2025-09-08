/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_render_main.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:42:02 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/08 21:09:30 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clear_sprite_instances(mlx_image_t *sprite)
{
	size_t i;

	if (!sprite)
		return;
	i = 0;
	while (i < sprite->count)
	{
		sprite->instances[i].enabled = false;
		i++;
	}
}

void	clear_player_sprites(t_so_long *game)
{
	clear_sprite_instances((mlx_image_t *)game->sprites.player->idle);
	clear_sprite_instances((mlx_image_t *)game->sprites.player->up);
	clear_sprite_instances((mlx_image_t *)game->sprites.player->down);
	clear_sprite_instances((mlx_image_t *)game->sprites.player->left);
	clear_sprite_instances((mlx_image_t *)game->sprites.player->right);
}



void	initial_render(t_so_long *game)
{
	printf("Initial rendering...\n");
	render_background(game);
	render_game_objects(game);
	render_player_only(game);
}



void	render_exits_only(t_so_long *game)
{
	int y = 0;
	while(y < game->map->rows)
	{
		int x = 0;
		while(x < game->map->cols)
		{
			char tile = game->map->map_grid[y][x];
			if(tile == 'E')
			{
				mlx_image_t *exit_sprite = get_tile_sprite(game, tile);
				if(exit_sprite)
					draw_sprite_at_cords(game, exit_sprite, x, y);
			}
			x++;
		}
		y++;
	}
}

void	render_game(t_so_long *game)
{
	printf("Rendering game...\n");
	clear_sprite_instances((mlx_image_t *)game->sprites.collectible);
	render_collectibles_only(game);
	clear_sprite_instances((mlx_image_t *)game->sprites.exit);
	clear_sprite_instances((mlx_image_t *)game->sprites.exit_open);
	render_exits_only(game);
	render_player_only(game);
}
