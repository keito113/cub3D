/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:46:17 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/17 18:18:36 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	config_init(t_config *config)
{
	int	i;

	i = 0;
	while (i < TEX_MAX)
	{
		config->tex_path[i] = NULL;
		config->parsed.tex[i] = 0;
		i++;
	}
	config->floor_color = -1;
	config->ceil_color = -1;
	config->parsed.floor = 0;
	config->parsed.ceil = 0;
}

static void	map_init(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

static void	player_init(t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}

static void	input_init(t_input *input)
{
	input->key_w = 0;
	input->key_s = 0;
	input->key_a = 0;
	input->key_d = 0;
	input->key_left = 0;
	input->key_right = 0;
}

int	game_init(t_game *game, const char *path)
{
	if (!game || !path)
		return (1);
	config_init(&game->config);
	map_init(&game->map);
	player_init(&game->player);
	input_init(&game->input);
	init_gfx(&game->gfx);
	game->is_running = 1;
	(void)path;
	return (0);
}
