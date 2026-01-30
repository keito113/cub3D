/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:35:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_step(t_game *game);
static int	is_hit_cell(t_game *game, int map_x, int map_y);

void	dda(t_game *game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0)
	{
		dda_step(game);
		if (is_hit_cell(game, game->ray.map_x, game->ray.map_y))
			game->ray.hit = 1;
	}
}

static void	dda_step(t_game *game)
{
	if (game->ray.side_dist_x < game->ray.side_dist_y)
	{
		game->ray.side_dist_x += game->ray.delta_dist_x;
		game->ray.map_x += game->ray.step_x;
		game->ray.side = 0;
	}
	else
	{
		game->ray.side_dist_y += game->ray.delta_dist_y;
		game->ray.map_y += game->ray.step_y;
		game->ray.side = 1;
	}
}

static int	is_hit_cell(t_game *game, int map_x, int map_y)
{
	char	cell;

	if (map_y < 0 || map_y >= game->map.height || map_x < 0
		|| map_x >= game->map.width)
		return (1);
	cell = game->map.grid[map_y][map_x];
	return (cell == '1' || cell == ' ');
}
