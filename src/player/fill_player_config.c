/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:27:00 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 18:49:22 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_player_start(t_game *game, int x, int y, char c)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	set_player_dir(&game->player, c);
	game->map.grid[y][x] = '0';
	return (1);
}

int	fill_player_config(t_game *game)
{
	int		x;
	int		y;
	int		found;
	char	c;

	found = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map.grid[y]))
		{
			c = game->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				found += set_player_start(game, x, y, c);
			x++;
		}
		y++;
	}
	if (found == 0)
		return (fatal(game, ERR_MAP, "No player start"));
	if (found > 1)
		return (fatal(game, ERR_MAP, "Multiple player starts"));
	return (0);
}
