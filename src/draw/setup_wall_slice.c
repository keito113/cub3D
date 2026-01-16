/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_wall_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:15:03 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 18:44:17 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_tex(t_game *game, t_wall_slice *slice);
static void	setup_tex_x(t_game *game, t_wall_slice *slice);
static void	setup_tex_step(t_game *game, t_wall_slice *slice);
static int	select_tex(t_game *game);

void	setup_wall_slice(t_game *game, t_wall_slice *slice)
{
	setup_tex(game, slice);
	setup_tex_x(game, slice);
	setup_tex_step(game, slice);
}

static void	setup_tex(t_game *game, t_wall_slice *slice)
{
	int	tex_id;

	tex_id = select_tex(game);
	slice->tex = &game->gfx.tex[tex_id];
}

static void	setup_tex_x(t_game *game, t_wall_slice *slice)
{
	if (game->ray.side == 0)
		slice->wall_x = game->player.y + game->ray.perp_wall_dist
			* game->ray.dir_y;
	else
		slice->wall_x = game->player.x + game->ray.perp_wall_dist
			* game->ray.dir_x;
	slice->wall_x -= floor(slice->wall_x);
	slice->tex_x = (int)(slice->wall_x * (double)slice->tex->img_width);
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		slice->tex_x = slice->tex->img_width - slice->tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		slice->tex_x = slice->tex->img_width - slice->tex_x - 1;
}

static void	setup_tex_step(t_game *game, t_wall_slice *slice)
{
	slice->tex_step = 1.0 * slice->tex->img_height / game->ray.line_height;
	slice->tex_y_pos = (game->ray.draw_start - game->gfx.win_h / 2
			+ game->ray.line_height / 2) * slice->tex_step;
}

static int	select_tex(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.dir_x > 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	else
	{
		if (game->ray.dir_y > 0)
			return (TEX_NO);
		return (TEX_SO);
	}
}
