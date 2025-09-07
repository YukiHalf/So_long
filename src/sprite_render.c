/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:26:41 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/07 18:27:16 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    *get_sprite_for_tile(t_so_long *game, char tile)
{
    if (tile == '1')
        return (game->sprites.wall);
    else if (tile == '0')
        return (game->sprites.floor);
    else if (tile == 'P')
        return (game->sprites.player->idle);
    else if (tile == 'C')
        return (game->sprites.collectible);
    else if (tile == 'E')
        return (game->sprites.exit);
    return (game->sprites.floor);
}
