/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:42:31 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/04 16:02:51 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int 	get_cols(int fd,t_map *map,char *line)
{
	char **grid;
	char *temp;
	int i;

	temp = ft_strtrim(line,"\n");
	if(!temp)
	display_error(MALLOC,1);
	grid = ft_split(temp,' ');
	free(temp);
	if(!grid)
		display_error(MALLOC,1);
	i = 0;
	while(grid[i])
	i++;
	free2d(grid);
	return i;
}

void 	get_dimensions(int fd,t_map *map)
{
	char *line;

	line = get_dimensions(fd);
	if(!line)
		// error
	map->cols = get_cols(fd,map,line);
	if(map->cols == 0)
		// error
	while(1)
	{
		tmp = get_next_line(fd);
		if(!tmp)
			break;
		map->rows++;
		if(map->cols != get_cols(fd,maps,line))
			//error
	}
}

void	parse_map(int fd,t_map *map)
{
	int i;
	int j;
	int k;
	char *line;

	i = -1;
	while(i++ < map->rows)
	{
		line = get_next_line(fd);
		if(!line)
		display_error(MALLOC,1);
		j = 0;
		k = 0;
		while(line[j])
		{
		if(!ValidElements && line[j] != ' ')
			display_error(INVALID_MAP,1);
			if(line[j] != ' ')
			{
				map->map_grid[i][k] = ft_atoi(line[j]);
				k++;
			}
		j++;
		}
	}
}
