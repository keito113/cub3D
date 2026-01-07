/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:07:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/07 15:31:52 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

static void	draw_wall_slice(t_game *game, t_wall_slice *slice);
static int	get_tex_pixel(t_img *tex, int x, int y);

void	draw_wall(t_game *game, t_wall_slice *slice)
{
	while (slice->screen_y <= game->ray.draw_end)
	{
		draw_wall_slice(game, slice);
		slice->screen_y++;
	}
}

static void	draw_wall_slice(t_game *game, t_wall_slice *slice)
{
	int		tex_y;
	int		color;

	tex_y = (int)(slice->tex_y_pos);
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= slice->tex->img_height)
		tex_y = slice->tex->img_height - 1;
	slice->tex_y_pos += slice->tex_step;
	color = get_tex_pixel(slice->tex, slice->tex_x, tex_y);
	put_pixel(&game->gfx.screen, slice->screen_x, slice->screen_y, color);
}

static int	get_tex_pixel(t_img *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= tex->img_width || y >= tex->img_height)
		return (0);
	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->img_width || y >= img->img_height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}
