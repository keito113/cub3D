/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:03:53 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/05 10:12:45 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_game *game);

void	game_destroy(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < TEX_MAX)
	{
		if (game->gfx.tex[i].ptr)
			mlx_destroy_image(game->gfx.mlx, game->gfx.tex[i].ptr);
		i++;
	}
	if (game->gfx.screen.ptr)
		mlx_destroy_image(game->gfx.mlx, game->gfx.screen.ptr);
	if (game->gfx.win)
		mlx_destroy_window(game->gfx.mlx, game->gfx.win);
	free_map(game);
	/* map/config文字列解放などは後で追加 */
}

static void	free_map(t_game *game)
{
	int	y;

	if (!game->map.grid)
		return ;
	y = 0;
	while (game->map.grid[y])
	{
		free(game->map.grid[y]);
		y++;
	}
	free(game->map.grid);
	game->map.grid = NULL;
}
