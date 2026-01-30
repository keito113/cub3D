/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:45:38 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:18:02 by takawagu         ###   ########.fr       */
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
	int		grid_x;
	int		grid_y;
	char	c;

	grid_x = (int)x;
	grid_y = (int)y;
	if (grid_y < 0 || grid_y >= game->map.height || grid_x < 0
		|| grid_x >= game->map.width)
		return (1);
	c = game->map.grid[grid_y][grid_x];
	return (c == '1' || c == ' ');
}
