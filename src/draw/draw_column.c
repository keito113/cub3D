/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:32:59 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 19:01:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_game *game, int x, int end_y);
static void	draw_floor(t_game *game, int x, int start_y);

void	draw_column(t_game *game, t_wall_slice *slice)
{
	draw_ceiling(game, slice->screen_x, game->ray.draw_start);
	setup_wall_slice(game, slice);
	slice->screen_y = game->ray.draw_start;
	draw_wall(game, slice);
	draw_floor(game, slice->screen_x, game->ray.draw_end + 1);
}

static void	draw_ceiling(t_game *game, int x, int end_y)
{
	int	y;

	y = 0;
	while (y < end_y)
	{
		put_pixel(&game->gfx.screen, x, y, game->config.ceil_color);
		y++;
	}
}

static void	draw_floor(t_game *game, int x, int start_y)
{
	int	y;

	y = start_y;
	while (y < game->gfx.win_h)
	{
		put_pixel(&game->gfx.screen, x, y, game->config.floor_color);
		y++;
	}
}
