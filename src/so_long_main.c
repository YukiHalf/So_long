/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:41:15 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/10 21:17:19 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	malloc_grid(t_map *map)
{
	int	i;

	map->map_grid = malloc(sizeof(char *) * map->rows);
	if (!map->map_grid)
	{
		free_map(map);
		display_error(MALLOC, 1);
	}
	i = -1;
	while (++i < map->rows)
	{
		map->map_grid[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!map->map_grid[i])
		{
			while (--i >= 0)
				free(map->map_grid[i]);
			free(map->map_grid);
			display_error(MALLOC, 1);
		}
	}
}

void	init_map(t_map *map)
{
	map->cols = 0;
	map->rows = 0;
	map->map_grid = NULL;
	map->collectible_count = 0;
	map->exit_count = 0;
	map->player_count = 0;
	map->player_x = -1;
	map->player_y = -1;
}

static t_map	*parse_input(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
		display_error(FILE_ERROR, 1);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		display_error(MALLOC, 1);
	}
	init_map(map);
	get_dimensions(fd, map);
	close(fd);
	malloc_grid(map);
	fd = open(filename, O_RDONLY, 0777);
	parse_map(fd, map);
	close(fd);
	return (map);
}

static t_so_long	*init_so_long(char *filename)
{
	static t_so_long	so_long;

	so_long.map = parse_input(filename);
	so_long.mlx = mlx_init(WIDTH, HEIGHT, "So Long", false);
	if (!so_long.mlx)
	{
		free_map(so_long.map);
		display_error((char *)mlx_strerror(mlx_errno), 1);
	}
	so_long.image = mlx_new_image(so_long.mlx, WIDTH, HEIGHT);
	if (!so_long.image)
	{
		free_map(so_long.map);
		mlx_close_window(so_long.mlx);
		display_error((char *)mlx_strerror(mlx_errno), 1);
	}
	return (&so_long);
}

int	main(int argc, char **argv)
{
	t_so_long	*so_long;

	if (!ValidFilename(argv[1]) || argc != 2)
		display_error(FORMAT, 1);
	so_long = init_so_long(argv[1]);
	setup_game(so_long);
	mlx_loop(so_long->mlx);
	return (0);
}
