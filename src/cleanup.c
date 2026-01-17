/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:03:53 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/17 18:39:04 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_game *game);
static void	free_config(t_game *game);

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
	free_config(game);
	if (game->gfx.mlx)
	{
		mlx_destroy_display(game->gfx.mlx);
		free(game->gfx.mlx);
		game->gfx.mlx = NULL;
	}
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

static void	free_config(t_game *game)
{
	int	i;

	i = 0;
	while (i < TEX_MAX)
	{
		free(game->config.tex_path[i]);
		game->config.tex_path[i] = NULL;
		i++;
	}
}
