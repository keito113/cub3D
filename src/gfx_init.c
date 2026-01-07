/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:48:22 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/05 18:57:51 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gfx_init(t_game *g)
{
	g->gfx.mlx = mlx_init();
	if (!g->gfx.mlx)
		return (fatal(g, ERR_MLX, NULL));
	g->gfx.win_w = g->map.width * 100;
	g->gfx.win_h = g->map.height * 100;
	g->gfx.win = mlx_new_window(g->gfx.mlx, g->gfx.win_w,
			g->gfx.win_h, "cub3D");
	if (!g->gfx.win)
		return (fatal(g, ERR_MLX, NULL));
	g->gfx.screen.ptr = mlx_new_image(g->gfx.mlx,
			g->gfx.win_w, g->gfx.win_h);
	if (!g->gfx.screen.ptr)
		return (fatal(g, ERR_IMG, NULL));
	g->gfx.screen.addr = mlx_get_data_addr(g->gfx.screen.ptr,
			&g->gfx.screen.bpp, &g->gfx.screen.line_len,
			&g->gfx.screen.endian);
	g->gfx.screen.img_width = g->gfx.win_w;
	g->gfx.screen.img_height = g->gfx.win_h;
	return (0);
}



