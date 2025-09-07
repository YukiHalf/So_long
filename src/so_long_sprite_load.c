/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprite_load.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:02:45 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/07 18:26:04 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*load_xpm_safe(mlx_t *mlx, char *path)
{
	void	*img;
	int		size;

	size = IMG_PXL;
	img = mlx_xpm_file_to_image(mlx, path, &size, &size);
	if (!img)
	{
		printf("Error : Failed to load sprite %s\n", path);
		return (NULL);
	}
	return (img);
}

int	load_basic_sprites(t_so_long *game)
{
	game->sprites.wall = load_xpm_safe(game->mlx, "textures/Map/wall.xpm");
	if (!game->sprites.wall)
		return (0);
	game->sprites.floor = load_xpm_safe(game->mlx, "textures/Map/floor.xpm");
	if (!game->sprites.floor)
		return (0);
	game->sprites.collectible = load_xpm_safe(game->mlx,
			"textures/Objects/Colect1.xpm");
	if (!game->sprites.collectible)
		return (0);
	game->sprites.exit = load_xpm_safe(game->mlx, "textures/Objects/exit.xpm");
	if (!game->sprites.exit)
		return (0);
	return (1);
}

int	load_special_sprites(t_so_long *game)
{
	game->sprites.player->idle = load_xpm_safe(game->mlx,
			"textures/Character/idle.xpm");
	if (!game->sprites.player->idle)
		return (0);
	game->sprites.player->up = load_xpm_safe(game->mlx,
			"textures/Character/up.xpm");
	if (!game->sprites.player->up)
		return (0);
	game->sprites.player->down = load_xpm_safe(game->mlx,
			"textures/Character/down.xpm");
	if (!game->sprites.player->down)
		return (0);
	game->sprites.player->left = load_xpm_safe(game->mlx,
			"textures/Character/left.xpm");
	if (!game->sprites.player->left)
		return (0);
	game->sprites.player->right = load_xpm_safe(game->mlx,
			"textures/Character/right.xpm");
	if (!game->sprites.player->down)
		return (0);
	return (1);
}

int	validate_all_sprites(t_so_long *game)
{
	if (!game->sprites.wall || !game->sprites.floor)
		return (0);
	if (!game->sprites.exit || !game->sprites.collectible)
		return (0);
	if (!game->sprites.player->down || !game->sprites.player->up
		|| !game->sprites.player->idle || !game->sprites.player->left
		|| !game->sprites.player->right)
		return (0);
	return (1);
}

void    load_sprites(t_so_long *game)
{
    if (!load_basic_sprites(game))
    {
        printf("Error: Failed to load basic sprites\n");
        exit(1);
    }
    if (!load_special_sprites(game))
    {
        printf("Error: Failed to load special sprites\n");
        exit(1);
    }
    if (!validate_all_sprites(game))
    {
        printf("Error: Some sprites failed to load\n");
        exit(1);
    }
    printf("✅ All sprites loaded successfully!\n");
}
