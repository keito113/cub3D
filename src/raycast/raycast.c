/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:38:05 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 19:21:27 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_ray(t_game *g, int x);
static void	setup_step(t_game *g);

void	raycast_frame(t_game *game)
{
	int				x;
	t_wall_slice	slice;

	x = 0;
	while (x < game->gfx.win_w)
	{
		setup_ray(game, x);
		setup_step(game);
		dda(game);
		calculate_wall(game);
		slice.screen_x = x;
		draw_column(game, &slice);
		x++;
	}
}

static void	setup_ray(t_game *g, int x)
{
	g->ray.camera_x = 2.0 * x / (double)g->gfx.win_w - 1.0;
	g->ray.dir_x = g->player.dir_x + g->player.plane_x * g->ray.camera_x;
	g->ray.dir_y = g->player.dir_y + g->player.plane_y * g->ray.camera_x;
	g->ray.map_x = (int)g->player.x;
	g->ray.map_y = (int)g->player.y;
	if (g->ray.dir_x == 0)
		g->ray.delta_dist_x = 1e30;
	else
		g->ray.delta_dist_x = fabs(1.0 / g->ray.dir_x);
	if (g->ray.dir_y == 0)
		g->ray.delta_dist_y = 1e30;
	else
		g->ray.delta_dist_y = fabs(1.0 / g->ray.dir_y);
}

static void	setup_step(t_game *g)
{
	if (g->ray.dir_x < 0)
	{
		g->ray.step_x = -1;
		g->ray.side_dist_x = (g->player.x - g->ray.map_x) * g->ray.delta_dist_x;
	}
	else
	{
		g->ray.step_x = 1;
		g->ray.side_dist_x = (g->ray.map_x + 1.0 - g->player.x)
			* g->ray.delta_dist_x;
	}
	if (g->ray.dir_y < 0)
	{
		g->ray.step_y = -1;
		g->ray.side_dist_y = (g->player.y - g->ray.map_y) * g->ray.delta_dist_y;
	}
	else
	{
		g->ray.step_y = 1;
		g->ray.side_dist_y = (g->ray.map_y + 1.0 - g->player.y)
			* g->ray.delta_dist_y;
	}
}
