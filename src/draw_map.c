/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:24:26 by takawagu          #+#    #+#             */
/*   Updated: 2025/12/27 14:59:34 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}


static char	map_char_at(t_game *g, int x, int y)
{
	if (x < (int)ft_strlen(g->map.grid[y]))
		return (g->map.grid[y][x]);
	return (' ');
}

static int	color_for_char(char c)
{
	if (c == '1')
		return (0x333333);
	return (0xBBBBBB);
}

static void	draw_tile(t_game *g, int x, int y, int color, int tile)
{
	int	i;
	int	j;

	j = 0;
	while (j < tile)
	{
		i = 0;
		while (i < tile)
		{
			put_pixel(&g->gfx.screen,
				x * tile + i, y * tile + j, color);
			i++;
		}
		j++;
	}
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	int		tile;
	char	c;
	int		color;

	tile = 16;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			c = map_char_at(g, x, y);
			color = color_for_char(c);
			draw_tile(g, x, y, color, tile);
			x++;
		}
		y++;
	}
}


