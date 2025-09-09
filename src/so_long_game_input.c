/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:39:49 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/09 16:08:31 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int get_new_position(mlx_key_data_t keydata, int *new_x, int *new_y, t_so_long *game)
{
	*new_x = game->map->player_x;
	*new_y = game->map->player_y;
	if(keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		(*new_y)--;
	else if(keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		(*new_y)++;
	else if(keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		(*new_x)--;
	else if(keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		(*new_x)++;
	else
		return 0;
	return 1;
}


void	handle_quit_input(t_so_long *game)
{
	if(game->game_won == 0)
	printf("Game quit by user\n");
	mlx_close_window(game->mlx);
}

void 	handle_good_move(t_so_long *game)
{
	game->moves++;
	printf("Moves : %d | Collected : %d/%d\n",
	game->moves,game->collected,game->map->collectible_count);
	render_game(game);
	if(game->game_won)
	{
		printf("you won in %d moves!\n", game->moves);
		handle_quit_input(game);
	}
}
void 	handle_movement_input(mlx_key_data_t keydata, t_so_long *game)
{
	int new_x;
	int new_y;

	if(!get_new_position(keydata,&new_x,&new_y,game))
		return;
	if(game->map->player_x < new_x)
	game->sprites.player->direction = 'R';
	if(game->map->player_x > new_x)
	game->sprites.player->direction ='L';
	if(game->map->player_y > new_y)
	game->sprites.player->direction ='U';
	if(game->map->player_y < new_y)
	game->sprites.player->direction = 'D';
	if(move_player(game,new_x,new_y))
		handle_good_move(game);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
printf("Key pressed: %d\n", keydata.key);
	t_so_long *game;
	game = (t_so_long *)param;
	if(keydata.action != MLX_PRESS)
		return;
	if(keydata.key == MLX_KEY_ESCAPE)
		handle_quit_input(game);
	else if (!game->game_won)
		handle_movement_input(keydata,game);
}
