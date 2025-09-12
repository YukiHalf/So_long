/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:42:31 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/11 21:24:31 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_cols(char *line)
{
	char	*temp;
	int		i;

	temp = ft_strtrim(line, "\n");
	if (!temp)
		display_error(MALLOC, 1);
	i = ft_strlen(temp);
	free(temp);
	return (i);
}

void	get_dimensions(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		display_error(INVALID_MAP, 1);
	map->cols = get_cols(line);
	map->rows = 1;
	free(line);
	if (map->cols == 0)
		display_error(INVALID_MAP, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (map->cols != get_cols(line))
		{
			free(line);
			display_error(INVALID_MAP, 1);
		}
		map->rows++;
		free(line);
	}
}

void	parse_map(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < map->rows)
	{
		line = get_next_line(fd);
		if (!line)
			display_error(MALLOC, 1);
		j = 0;
		while (line[j] && line[j] != '\n')
		{
			if (!valid_elements(line[j]))
				display_error(INVALID_MAP, 1);
			if (line[j] != ' ')
			{
				parse_count_map(map, line[j], j, i);
				map->map_grid[i][j] = line[j];
			}
			j++;
		}
		free(line);
	}
	map_check(map);
}
