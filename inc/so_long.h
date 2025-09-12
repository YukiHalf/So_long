/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:21:24 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/12 18:41:33 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define HEIGHT 1080
# define WIDTH 1920

# define MALLOC "Malloc failed"
# define INVALID_FILE "Filename is invalid"
# define INVALID_MAP "Map is invalid"
# define FORMAT "Format:\n\t./fdf maps/filename.ber"
# define FILE_ERROR "Unable to open file"

# define IMG_PXL 32

typedef struct s_player
{
	void		*idle;
	void		*up;
	void		*down;
	void		*left;
	void		*right;
	char		direction;
}				t_player;

typedef struct s_sprites
{
	void		*wall;
	void		*floor;
	t_player	*player;
	void		*collectible;
	void		*exit;
	void		*exit_open;
}				t_sprites;

typedef struct s_flood_data
{
	char		**temp_map;
	int			rows;
	int			cols;
}				t_flood_data;

typedef struct s_map
{
	int			rows;
	int			cols;
	char		**map_grid;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	int			player_x;
	int			player_y;
}				t_map;

typedef struct s_so_long
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*image;
	t_sprites	sprites;
	int			moves;
	int			collected;
	int			game_won;
}				t_so_long;

// Map/Format/File/Data/Path Checker
int				valid_filename(char *filename);
int				valid_elements(char c);
void			map_check(t_map *map);
void			walls_check(t_map *map);
void			elements_check(t_map *map);
int				path_check(t_map *map);
void			parse_count_map(t_map *map, char c, int j, int i);
void			flood_fill(t_flood_data *data, int x, int y,
					int *collectibles_found);

// Map create functions
void			init_map(t_map *map);
void			parse_map(int fd, t_map *map);
void			get_dimensions(int fd, t_map *map);
int				get_cols(char *line);
void			fill_data_flood(t_flood_data *flood_data, t_map *map);
// Memory functions
void			malloc_grid(t_map *map);
char			**create_temp_map(t_map *map);
void			free_map(t_map *map);

// Game functions
void			setup_game(t_so_long *so_long);
void			handle_input(mlx_key_data_t keydata, void *param);
int				move_player(t_so_long *game, int new_x, int new_y);
void			clear_entire_image(t_so_long *game);

// Sprite loading functions
void			*load_png_safe(mlx_t *mlx, char *path);
int				load_basic_sprites(t_so_long *game);
int				load_special_sprites(t_so_long *game);
int				validate_all_sprites(t_so_long *game);
void			load_sprites(t_so_long *game);

// Sprite rendering functions
mlx_image_t		*get_tile_sprite(t_so_long *game, char tile);
void			draw_sprite_at_cords(t_so_long *game, mlx_image_t *sprite,
					int map_x, int map_y);
void			render_background(t_so_long *game);
void			render_game_objects(t_so_long *game);
void			render_game(t_so_long *game);
void			render_player_only(t_so_long *game);
void			initial_render(t_so_long *game);

mlx_image_t		*get_player_direction(t_so_long *game);
void			render_collectibles_only(t_so_long *game);
void			render_player_only(t_so_long *game);
void			clear_player_sprites(t_so_long *game);
#endif
