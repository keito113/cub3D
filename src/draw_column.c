/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:32:59 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/03 14:37:01 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

static int	get_tex_pixel(t_img *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= tex->w || y >= tex->h)
		return (0);
	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

static int	select_tex(t_game *g)
{
	if (g->ray.side == 0)
	{
		if (g->ray.ray_dir_x > 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	else
	{
		if (g->ray.ray_dir_y > 0)
			return (TEX_NO);
		return (TEX_SO);
	}
}

void	draw_column(t_game *g, int x)
{
	int		y;
	int		tex_id;
	t_img	*tex;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;

	y = 0;
	while (y < g->ray.draw_start)
	{
		put_pixel(&g->gfx.screen, x, y, g->config.ceil_color);
		y++;
	}
	tex_id = select_tex(g);
	tex = &g->gfx.tex[tex_id];
	if (g->ray.side == 0)
		wall_x = g->player.y + g->ray.perp_wall_dist * g->ray.ray_dir_y;
	else
		wall_x = g->player.x + g->ray.perp_wall_dist * g->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->w);
	if (g->ray.side == 0 && g->ray.ray_dir_x > 0)
		tex_x = tex->w - tex_x - 1;
	if (g->ray.side == 1 && g->ray.ray_dir_y < 0)
		tex_x = tex->w - tex_x - 1;
	step = 1.0 * tex->h / g->ray.line_height;
	tex_pos = (g->ray.draw_start - g->gfx.win_h / 2
			+ g->ray.line_height / 2) * step;
	while (y <= g->ray.draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->h)
			tex_y = tex->h - 1;
		tex_pos += step;
		color = get_tex_pixel(tex, tex_x, tex_y);
		put_pixel(&g->gfx.screen, x, y, color);
		y++;
	}
	while (y < g->gfx.win_h)
	{
		put_pixel(&g->gfx.screen, x, y, g->config.floor_color);
		y++;
	}
}
