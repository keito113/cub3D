/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:03:53 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/03 16:07:35 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_destroy(t_game *g)
{
	int	i;

	if (!g)
		return ;
	i = 0;
	while (i < TEX_MAX)
	{
		if (g->gfx.tex[i].ptr)
			mlx_destroy_image(g->gfx.mlx, g->gfx.tex[i].ptr);
		i++;
	}
	if (g->gfx.screen.ptr)
		mlx_destroy_image(g->gfx.mlx, g->gfx.screen.ptr);
	if (g->gfx.win)
		mlx_destroy_window(g->gfx.mlx, g->gfx.win);
	/* map/config文字列解放などは後で追加 */
}
