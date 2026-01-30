/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:37:45 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 19:31:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_movement(t_game *game)
{
	if (game->input.key_w)
		move_player(game, game->player.dir_x * MOVE_SPEED, game->player.dir_y
			* MOVE_SPEED);
	if (game->input.key_s)
		move_player(game, -game->player.dir_x * MOVE_SPEED, -game->player.dir_y
			* MOVE_SPEED);
	if (game->input.key_d)
		move_player(game, game->player.plane_x * MOVE_SPEED,
			game->player.plane_y * MOVE_SPEED);
	if (game->input.key_a)
		move_player(game, -game->player.plane_x * MOVE_SPEED,
			-game->player.plane_y * MOVE_SPEED);
	if (game->input.key_left)
		rotate_player(game, -ROT_SPEED);
	if (game->input.key_right)
		rotate_player(game, ROT_SPEED);
}
