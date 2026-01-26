/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_enclosed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:43:10 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 18:20:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	cell_at(char **grid, int y, int x);
static int	is_walkable(char c);
static int	is_open_to_space(char **grid, int y, int x);

int	check_map_enclosed(t_game *game)
{
	int		x;
	int		y;
	int		len;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		len = (int)ft_strlen(game->map.grid[y]);
		while (x < len)
		{
			c = game->map.grid[y][x];
			if (is_walkable(c))
			{
				if (is_open_to_space(game->map.grid, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static char	cell_at(char **grid, int y, int x)
{
	int	len;

	if (y < 0 || x < 0 || !grid[y])
		return (' ');
	len = (int)ft_strlen(grid[y]);
	if (x >= len)
		return (' ');
	return (grid[y][x]);
}

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_open_to_space(char **grid, int y, int x)
{
	if (cell_at(grid, y - 1, x) == ' ')
		return (1);
	if (cell_at(grid, y + 1, x) == ' ')
		return (1);
	if (cell_at(grid, y, x - 1) == ' ')
		return (1);
	if (cell_at(grid, y, x + 1) == ' ')
		return (1);
	return (0);
}
