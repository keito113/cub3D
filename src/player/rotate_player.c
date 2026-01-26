/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:47:21 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:48:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, double rot)
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
