/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:55:12 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/07 16:37:17 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int 	is_valid_position(t_so_long *game, int x, int y)
{
	if(x < 0 || x >= game->map->cols || y < 0  || y >= game->map->rows)
		return 0;
	if(game->map->map_grid[y][x] == '1')
		return 0;
	return 1;
}

void	collect_item(t_so_long *game , int x, int y)
{
	if(game->map->map_grid[y][x] == 'C')
	{
		game->collected ++;
		game->map->map_grid[y][x] = '0';
		printf("Treat collected (%d/%d)\n",
		game->collected, game->map->collectible_count);
	}
}

int		try_exit(t_so_long *game)
{
	if(game->collected == game->map->collectible_count)
	{
		game->game_won = 1;
		return 1;
	}
	printf("🚪 Need all items! (%d/%d)\n",
		game->collected, game->map->collectible_count);
	return (0);
}

void	update_player_position(t_so_long *game, int new_x,int new_y)
{
	game->map->map_grid[game->map->player_y][game->map->player_x] = '0';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->map->map_grid[game->map->player_y][game->map->player_x] = 'P';
}

int 	move_player(t_so_long *game, int new_x, int new_y)
{
	char target;
// In your move_player function, add:
printf("Attempting move to (%d, %d)\n", new_x, new_y);
	target = game->map->map_grid[new_y][new_x];
	if(!is_valid_position(game,new_x,new_y))
		return 0;
	if(target == 'C')
		collect_item(game,new_x,new_y);
	else if(target == 'E' && !try_exit(game))
		return 0;
	update_player_position(game,new_x,new_y);
	return 1;
}
