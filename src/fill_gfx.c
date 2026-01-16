/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:48:22 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 18:57:06 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_window(t_game *game);

int	fill_gfx(t_game *game)
{
	game->gfx.mlx = mlx_init();
	if (!game->gfx.mlx)
		return (fatal(game, ERR_MLX, NULL));
	if (init_window(game) != 0)
		return (1);
	game->gfx.screen.ptr = mlx_new_image(game->gfx.mlx,
			game->gfx.win_w, game->gfx.win_h);
	if (!game->gfx.screen.ptr)
		return (fatal(game, ERR_IMG, NULL));
	game->gfx.screen.addr = mlx_get_data_addr(game->gfx.screen.ptr,
			&game->gfx.screen.bpp, &game->gfx.screen.line_len,
			&game->gfx.screen.endian);
	game->gfx.screen.img_width = game->gfx.win_w;
	game->gfx.screen.img_height = game->gfx.win_h;
	return (0);
}

static int	init_window(t_game *game)
{
	game->gfx.win_w = game->map.width * 100;
	game->gfx.win_h = game->map.height * 100;
	game->gfx.win = mlx_new_window(game->gfx.mlx, game->gfx.win_w,
			game->gfx.win_h, "cub3D");
	if (!game->gfx.win)
		return (fatal(game, ERR_MLX, NULL));
	return (0);
}
