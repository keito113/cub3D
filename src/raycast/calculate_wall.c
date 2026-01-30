/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:40:05 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:58:11 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	calculate_perp_dist(t_game *game);
static void		calculate_draw_range(t_game *game, double perp_dist);

void	calculate_wall(t_game *game)
{
	double	perp_dist;

	perp_dist = calculate_perp_dist(game);
	game->ray.perp_wall_dist = perp_dist;
	calculate_draw_range(game, perp_dist);
}

static double	calculate_perp_dist(t_game *game)
{
	if (game->ray.side == HIT_X_SIDE)
		return ((game->ray.map_x - game->player.x + (1 - game->ray.step_x)
				/ 2.0) / game->ray.dir_x);
	return ((game->ray.map_y - game->player.y + (1 - game->ray.step_y) / 2.0)
		/ game->ray.dir_y);
}

static void	calculate_draw_range(t_game *game, double perp_dist)
{
	int	wall_height;
	int	draw_start;
	int	draw_end;

	wall_height = (int)(game->gfx.win_h / perp_dist);
	draw_start = -wall_height / 2 + game->gfx.win_h / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = wall_height / 2 + game->gfx.win_h / 2;
	if (draw_end >= game->gfx.win_h)
		draw_end = game->gfx.win_h - 1;
	game->ray.wall_height = wall_height;
	game->ray.draw_start = draw_start;
	game->ray.draw_end = draw_end;
}
