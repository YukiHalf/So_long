/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:42:31 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/05 21:40:06 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int 	get_cols(int fd,t_map *map,char *line)
{
	char *temp;
	int i;

	temp = ft_strtrim(line , "\n");
	if(!temp)
		display_error(MALLOC,1);
	i = ft_strlen(temp);
	free(temp);
	return i;
}

void 	get_dimensions(int fd,t_map *map)
{
	char *line;

	line = get_next_line(fd);
	if(!line)
		display_error(INVALID_MAP,1);
	map->cols = get_cols(fd,map,line);
	map->rows = 1;
	free(line);
	if(map->cols == 0)
		display_error(INVALID_MAP,1);
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		if(map->cols != get_cols(fd,maps,line))
			{
				free(line);
				display_error(INVALID_MAP,1);
			}
			map->rows++;
			free(line);
		}
}

void	parse_map(int fd,t_map *map)
{
	int i;
	int j;
	char *line;

	i = -1;
	while(i++ < map->rows)
	{
		line = get_next_line(fd);
		if(!line)
			display_error(MALLOC,1);
		j = 0;
		while(line[j] && line[j] != '\n')
		{
		if(!ValidElements)
			display_error(INVALID_MAP,1);
			if(line[j] != ' ')
			{
				map->map_grid[i][j] = ft_atoi(line[j]);
			}
		j++;
		}
		free(line);
	}
}
