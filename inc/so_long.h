#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"


# define HEIGHT 1920
# define WIDTH 1080

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define MALLOC "Malloc failed at " __FILE__ ":" TOSTRING(__LINE__)
# define INVALID_FILE "Filename is invalid"
# define INVALID_MAP  "Map is invalid"
# define FORMAT   "Format:\n\t./fdf maps/filename.ber"
# define FILE_ERROR "Unable to open file"

#define TILE_SIZE 32
#define COLOR_WALL    0xFF0000FF   // Red
#define COLOR_FLOOR   0x808080FF   // Gray
#define COLOR_PLAYER  0x00FF00FF   // Green
#define COLOR_COLLECT 0xFFFF00FF   // Yellow
#define COLOR_EXIT    0x0000FFFF   // Blue
#define COLOR_BORDER  0x000000FF

typedef struct s_map
{
  	 int rows;
  	 int cols;
  	 char **map_grid;
  	 int player_count;
  	 int exit_count;
  	 int collectible_count;
  	 int player_x;
  	 int player_y;
} 		t_map;

typedef struct s_so_long
{
  	 mlx_t  		*mlx;
  	 t_map   		*map;
	 mlx_image_t	*image;
	 int moves;
 	 int collected;
  	 int game_won;
} 		 t_so_long;


// Map/Format/File/Data/Path Checker
int ValidFilename(char *filename);
int ValidElements(char c);
void map_check(t_map *map);
void walls_check(t_map *map);
void elements_check(t_map *map);
int path_check(t_map *map);
void parse_count_map(t_map *map,char c,int j,int i);
void flood_fill(char **temp_map, int x, int y, int rows, int cols, int *collectibles_found);

// Map create functions
void init_map(t_map *map);
void parse_map(int fd, t_map *map);
void get_dimensions(int fd, t_map *map);
int get_cols(char *line);

// Memory functions
void malloc_grid(t_map *map);
char **create_temp_map(t_map *map);
void free_map(t_map *map);

// Game functions
void setup_game(t_so_long *so_long);
void handle_input(mlx_key_data_t keydata, void *param);
int  move_player(t_so_long *game, int new_x, int new_y);
void render_game(t_so_long *game);
void draw_tile(t_so_long *game, int x, int y, uint32_t color);


#endif
