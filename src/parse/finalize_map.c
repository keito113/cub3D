/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:15:44 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 18:41:15 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_max_width(char **grid, t_list *lst);
static int	fail_map_enclosed(t_game *game, char **grid);

int	finalize_map(t_game *game, t_list *lst)
{
	int		height;
	int		width;
	char	**grid;

	if (!game->config.parsed.floor)
		return (fatal(game, ERR_PARSE, "Missing floor color"));
	if (!game->config.parsed.ceil)
		return (fatal(game, ERR_PARSE, "Missing ceiling color"));
	height = ft_lstsize(lst);
	if (height == 0)
		return (fatal(game, ERR_MAP, "Map missing"));
	grid = ft_calloc(height + 1, sizeof(char *));
	if (!grid)
		return (fatal(game, ERR_ALLOC, NULL));
	width = get_map_max_width(grid,lst);
	game->map.grid = grid;
	game->map.height = height;
	game->map.width = width;
	if (check_map_enclosed(game) != 0)
		return (fail_map_enclosed(game, grid));
	return (0);
}

static int	get_map_max_width(char **grid, t_list *lst)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (lst)
	{
		grid[i] = lst->content;
		if ((int)ft_strlen(grid[i]) > width)
			width = ft_strlen(grid[i]);
		lst = lst->next;
		i++;
	}
	return (width);
}

static int	fail_map_enclosed(t_game *game, char **grid)
{
	game->map.grid = NULL;
	game->map.height = 0;
	game->map.width = 0;
	free(grid);
	return (fatal(game, ERR_MAP, "Map not enclosed"));
}
