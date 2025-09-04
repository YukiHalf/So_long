#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../lib/libft/libft.h"
#include "../lib/MLX42/MLX42.h"


# define HEIGHT 1920
# define WIDTH 1080

# define MALLOC 	  "Malloc failed"
# define INVALID_FILE "Filename is invalid"
# define INVALID_MAP  "Map is invalid"
# define FORMAT   "Format:\n\t./fdf maps/filename.ber"
# define FILE_ERROR "Unable to open file"


typedef struct s_map
{
  int rows;
  int cols;
  int **map_grid;
  int player_count;
  int exit_count;
  int collectible_count;
  int player_x;
  int player_y;
} t_map;

typedef struct s_so_long
{
  mlx_t  		*mlx;
  t_map   		*map;
  mlx_image_t	*image;
} t_so_long;


int		ValidFilename(char *filename);
int   	ValidElements(char c);


#endif
