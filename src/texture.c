/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:29:42 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/03 14:30:17 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 例: src/texture.c
#include "cub3d.h"

static int	load_one_tex(t_game *g, int idx)
{
	t_img	*tex;
	char	*path;

	tex = &g->gfx.tex[idx];
	path = g->config.tex_path[idx];
	tex->ptr = mlx_xpm_file_to_image(g->gfx.mlx, path, &tex->w, &tex->h);
	if (!tex->ptr)
		return (fatal(g, ERR_IMG, path));
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->addr)
		return (fatal(g, ERR_IMG, path));
	return (0);
}

int	load_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < TEX_MAX)
	{
		if (load_one_tex(g, i) != 0)
			return (1);
		i++;
	}
	return (0);
}

