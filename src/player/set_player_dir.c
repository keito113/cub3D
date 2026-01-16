/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:02:51 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 18:44:44 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_dir_north(t_player *player);
static void	set_player_dir_south(t_player *player);
static void	set_player_dir_east(t_player *player);
static void	set_player_dir_west(t_player *player);

void	set_player_dir(t_player *player, char c)
{
	if (c == 'N')
		set_player_dir_north(player);
	else if (c == 'S')
		set_player_dir_south(player);
	else if (c == 'E')
		set_player_dir_east(player);
	else if (c == 'W')
		set_player_dir_west(player);
}

static void	set_player_dir_north(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = -1.0;
	player->plane_x = 0.66;
	player->plane_y = 0.0;
}

static void	set_player_dir_south(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = 1.0;
	player->plane_x = -0.66;
	player->plane_y = 0.0;
}

static void	set_player_dir_east(t_player *player)
{
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
}

static void	set_player_dir_west(t_player *player)
{
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = -0.66;
}
