/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprite_load.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:02:45 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/17 20:21:08 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*load_png_safe(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
	{
		display_error("Error: Failed to convert texture to image", 1);
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (img);
}

int	load_basic_sprites(t_so_long *game)
{
	game->sprites.wall = load_png_safe(game->mlx, "textures/Map/wall.png");
	if (!game->sprites.wall)
		return (0);
	game->sprites.floor = load_png_safe(game->mlx, "textures/Map/floor.png");
	if (!game->sprites.floor)
		return (0);
	game->sprites.collectible = load_png_safe(game->mlx,
			"textures/Objects/collectible.png");
	if (!game->sprites.collectible)
		return (0);
	game->sprites.exit = load_png_safe(game->mlx, "textures/Objects/exit.png");
	if (!game->sprites.exit)
		return (0);
	game->sprites.exit_open = load_png_safe(game->mlx,
			"textures/Objects/exit_open.png");
	if (!game->sprites.exit_open)
		return (0);
	return (1);
}

int	load_special_sprites(t_so_long *game)
{
	game->sprites.player->idle = load_png_safe(game->mlx,
			"textures/Character/idle.png");
	if (!game->sprites.player->idle)
		return (0);
	game->sprites.player->up = load_png_safe(game->mlx,
			"textures/Character/up.png");
	if (!game->sprites.player->up)
		return (0);
	game->sprites.player->down = load_png_safe(game->mlx,
			"textures/Character/down.png");
	if (!game->sprites.player->down)
		return (0);
	game->sprites.player->left = load_png_safe(game->mlx,
			"textures/Character/left.png");
	if (!game->sprites.player->left)
		return (0);
	game->sprites.player->right = load_png_safe(game->mlx,
			"textures/Character/right.png");
	if (!game->sprites.player->right)
		return (0);
	return (1);
}

int	validate_all_sprites(t_so_long *game)
{
	if (!game->sprites.wall || !game->sprites.floor)
		return (0);
	if (!game->sprites.exit || !game->sprites.exit_open
		|| !game->sprites.collectible)
		return (0);
	if (!game->sprites.player->down || !game->sprites.player->up
		|| !game->sprites.player->idle || !game->sprites.player->left
		|| !game->sprites.player->right)
		return (0);
	return (1);
}

void	load_sprites(t_so_long *game)
{
	if (!load_basic_sprites(game))
		display_error("Error: Failed to load basic sprites\n", 1);
	if (!load_special_sprites(game))
		display_error("Error: Failed to load special sprites\n", 1);
	if (!validate_all_sprites(game))
		display_error("Error: Some sprites failed to load\n", 1);
}
