/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:46:17 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/03 16:03:46 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	config_init(t_config *cfg)
{
	int	i;

	i = 0;
	while (i < TEX_MAX)
	{
		cfg->tex_path[i] = NULL;
		i++;
	}
	cfg->floor_color = -1;
	cfg->ceil_color = -1;
	cfg->parsed_mask = 0;
}

static void	map_init(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

static void	player_init(t_player *p)
{
	p->x = 0.0;
	p->y = 0.0;
	p->dir_x = 0.0;
	p->dir_y = 0.0;
	p->plane_x = 0.0;
	p->plane_y = 0.0;
}

static void	input_init(t_input *in)
{
	in->key_w = 0;
	in->key_s = 0;
	in->key_a = 0;
	in->key_d = 0;
	in->key_left = 0;
	in->key_right = 0;
}

int	game_init(t_game *g, const char *path)
{
	if (!g || !path)
		return (1);
	config_init(&g->config);
	map_init(&g->map);
	player_init(&g->player);
	input_init(&g->input);
	g->gfx.mlx = NULL;
	g->gfx.win = NULL;
	g->gfx.screen.ptr = NULL;
	g->gfx.screen.addr = NULL;
	g->gfx.screen.bpp = 0;
	g->gfx.screen.line_len = 0;
	g->gfx.screen.endian = 0;
	g->gfx.screen.w = 0;
	g->gfx.screen.h = 0;
	g->gfx.tex[TEX_NO].ptr = NULL;
	g->gfx.tex[TEX_SO].ptr = NULL;
	g->gfx.tex[TEX_WE].ptr = NULL;
	g->gfx.tex[TEX_EA].ptr = NULL;
	g->gfx.win_w = 640;
	g->gfx.win_h = 480;
	g->is_running = 1;
	(void)path;
	return (0);
}
