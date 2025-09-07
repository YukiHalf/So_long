/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:54:09 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/06 20:06:03 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		ValidFilename(char *filename)
{
	int len;

	if(!filename)
		return 0;
  	len = ft_strlen(filename);
	if(len < 5)
		display_error(INVALID_FILE,1);
	return(ft_strncmp(filename + len - 4 , ".ber" , 4) == 0);
}

int   ValidElements(char c)
{
  if(c != '0' && c != '1' && c != 'C' && c != 'E' && c!= 'P')
  return 0;
return 1;
}

void parse_count_map(t_map *map,char c,int j,int i)
{
	if(c == 'P')
	{
		map->player_count++;
		map->player_x = j;
		map->player_y = i;
	}
	else if(c == 'C')
		map->collectible_count++;
	else if(c == 'E')
		map->exit_count++;
}

void free_map(t_map *map)
{
	int i;

	if(!map)
		return;

	if(map->map_grid)
	{
		i = 0;
		while(i < map->rows)
		{
			if(map->map_grid[i])
			{
				free(map->map_grid[i]);
				map->map_grid[i] = NULL;
			}
			i++;
		}
		free(map->map_grid);
		map->map_grid = NULL;
	}
	free(map);
}
