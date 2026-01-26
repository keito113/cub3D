/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:29:42 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:54:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_one_tex(t_game *game, int i);

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < TEX_MAX)
	{
		if (load_one_tex(game, i) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	load_one_tex(t_game *game, int i)
{
	t_img	*tex;
	char	*path;

	tex = &game->gfx.tex[i];
	path = game->config.tex_path[i];
	tex->ptr = mlx_xpm_file_to_image(game->gfx.mlx, path,
			&tex->img_width, &tex->img_height);
	if (!tex->ptr)
		return (fatal(game, ERR_IMG, path));
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->addr)
		return (fatal(game, ERR_IMG, path));
	return (0);
}
