/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:44:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/07 15:49:09 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(t_game *game, double x, double y)
{
	return (game->map.grid[(int)y][(int)x] == '1');
}

static void	move_player(t_game *game, double dx, double dy)
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

static void	rotate_player(t_game *game, double rot)
{
	double	old_dir_x;
	double	old_plane_x;
	double	c;
	double	s;

	c = cos(rot);
	s = sin(rot);
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * c - game->player.dir_y * s;
	game->player.dir_y = old_dir_x * s + game->player.dir_y * c;
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * c - game->player.plane_y * s;
	game->player.plane_y = old_plane_x * s + game->player.plane_y * c;
}

int	game_update(t_game *g)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.05;
	rot_speed = 0.04;
	if (g->input.key_w)
		move_player(g, g->player.dir_x * move_speed,
			g->player.dir_y * move_speed);
	if (g->input.key_s)
		move_player(g, -g->player.dir_x * move_speed,
			-g->player.dir_y * move_speed);
	if (g->input.key_d)
		move_player(g, g->player.plane_x * move_speed,
			g->player.plane_y * move_speed);
	if (g->input.key_a)
		move_player(g, -g->player.plane_x * move_speed,
			-g->player.plane_y * move_speed);
	if (g->input.key_left)
		rotate_player(g, -rot_speed);
	if (g->input.key_right)
		rotate_player(g, rot_speed);
	raycast_frame(g);
	mlx_put_image_to_window(g->gfx.mlx, g->gfx.win,
		g->gfx.screen.ptr, 0, 0);
	return (0);
}
