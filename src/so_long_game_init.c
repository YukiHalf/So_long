/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:14:38 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/10 21:17:07 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game_default(t_so_long *game)
{
	game->collected = 0;
	game->moves = 0;
	game->game_won = 0;
	game->sprites.player = malloc(sizeof(t_player));
	if (!game->sprites.player)
	{
		free_map(game->map);
		mlx_close_window(game->mlx);
		display_error(MALLOC, 1);
	}
}

void	clear_image_black(t_so_long *game)
{
	int	x;
	int	y;

	y = 0;
	while ((uint32_t)y < game->image->height)
	{
		x = 0;
		while ((uint32_t)x < game->image->width)
		{
			mlx_put_pixel(game->image, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	print_game_info(t_so_long *game)
{
	printf("`.......                        `..                                   `..                 \n"
			"`..    `..                      `..                                   `..                 \n"
			"`..    `..`..  `..   `..        `..`.. `..  `..     `..   `..         `..   `..    `. `...\n"
			"`.......  `..  `.. `..  `..     `.. `..  `.. `..   `..  `..  `..  `.. `.. `.   `..  `..   \n"
			"`..       `..  `..`..   `..     `.. `..  `..  `.. `..  `..   `.. `.   `..`..... `.. `..   \n"
			"`..       `..  `.. `..  `..     `.. `..  `..   `.`..   `..   `.. `.   `..`.         `..   \n"
			"`..         `..`..     `..      `..`...  `..    `..      `.. `... `.. `..  `....   `...   \n"
			"                    `..                                                                  \n");
	printf("Map size: %dx%d\n", game->map->cols, game->map->rows);
	printf("Player at: (%d, %d)\n", game->map->player_x, game->map->player_y);
	printf("Collectibles: %d\n", game->map->collectible_count);
	printf("Controls: WASD or Arrow Keys, ESC to quit\n");
}

void	display_image(t_so_long *game)
{
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
	{
		free_map(game->map);
		mlx_close_window(game->mlx);
		display_error((char *)mlx_strerror(mlx_errno), 1);
	}
}

void	setup_game(t_so_long *so_long)
{
	init_game_default(so_long);
	clear_image_black(so_long);
	display_image(so_long);
	load_sprites(so_long);
	mlx_key_hook(so_long->mlx, &handle_input, so_long);
	initial_render(so_long);
	print_game_info(so_long);
}
