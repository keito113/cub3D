/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:27:00 by takawagu          #+#    #+#             */
/*   Updated: 2025/12/29 12:14:40 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_dir(t_player *p, char c)
{
	if (c == 'N')
	{
		p->dir_x = 0.0;
		p->dir_y = -1.0;
		p->plane_x = 0.66;
		p->plane_y = 0.0;
	}
	else if (c == 'S')
	{
		p->dir_x = 0.0;
		p->dir_y = 1.0;
		p->plane_x = -0.66;
		p->plane_y = 0.0;
	}
	else if (c == 'E')
	{
		p->dir_x = 1.0;
		p->dir_y = 0.0;
		p->plane_x = 0.0;
		p->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		p->dir_x = -1.0;
		p->dir_y = 0.0;
		p->plane_x = 0.0;
		p->plane_y = -0.66;
	}
}

int	fill_player_config(t_game *g)
{
	int		x;
	int		y;
	int		found;
	char	c;

	found = 0;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < (int)ft_strlen(g->map.grid[y]))
		{
			c = g->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				found++;
				g->player.x = x + 0.5;
				g->player.y = y + 0.5;
				set_player_dir(&g->player, c);
				g->map.grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (found == 0)
		return (fatal(g, ERR_MAP, "No player start"));
	if (found > 1)
		return (fatal(g, ERR_MAP, "Multiple player starts"));
	return (0);
}



