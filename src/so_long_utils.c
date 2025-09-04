/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:54:09 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/04 15:58:27 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		ValidFilename(char *filename)
{
	int len = ft_strlen(filename);
	if(len < 5)
	display_error(INVALID_FILE,1);
return(ft_strncmp(filename + len - 4 , ".ber" , 4));
}

int   ValidElements(char c)
{
  if(c != '0' && c != '1' && c != 'C' && c != 'E' && c!= 'P')
  return 0
return 1;
}
