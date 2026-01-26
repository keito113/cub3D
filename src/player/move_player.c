/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:45:38 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:46:32 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(t_game *game, double x, double y);

void	move_player(t_game *game, double dx, double dy)
{
	double	nx;
	double	ny;

	nx = game->player.x + dx;
	ny = game->player.y + dy;
	if (!is_wall(game, nx, game->player.y))
		game->player.x = nx;
	if (!is_wall(game, game->player.x, ny))
		game->player.y = ny;
}

static int	is_wall(t_game *game, double x, double y)
{
	return (game->map.grid[(int)y][(int)x] == '1');
}
