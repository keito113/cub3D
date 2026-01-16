/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:58:27 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 19:02:56 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_gfx_screen(t_img *screen);
static void	init_gfx_tex(t_img *tex);

void	init_gfx(t_gfx *gfx)
{
	gfx->mlx = NULL;
	gfx->win = NULL;
	gfx->win_w = 640;
	gfx->win_h = 480;
	init_gfx_screen(&gfx->screen);
	init_gfx_tex(gfx->tex);
}

static void	init_gfx_screen(t_img *screen)
{
	screen->ptr = NULL;
	screen->addr = NULL;
	screen->bpp = 0;
	screen->line_len = 0;
	screen->endian = 0;
	screen->img_width = 0;
	screen->img_height = 0;
}

static void	init_gfx_tex(t_img *tex)
{
	tex[TEX_NO].ptr = NULL;
	tex[TEX_SO].ptr = NULL;
	tex[TEX_WE].ptr = NULL;
	tex[TEX_EA].ptr = NULL;
}
