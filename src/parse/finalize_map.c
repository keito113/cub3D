/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:15:44 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:08:52 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_max_width(t_list *lst);
static int	pad_map_lines(t_list *lst, int width);
static void	fill_grid_from_list(char **grid, t_list *lst);
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
	width = get_map_max_width(lst);
	if (pad_map_lines(lst, width) != 0)
		return (1);
	grid = ft_calloc(height + 1, sizeof(char *));
	if (!grid)
		return (fatal(game, ERR_ALLOC, NULL));
	fill_grid_from_list(grid, lst);
	game->map.grid = grid;
	game->map.height = height;
	game->map.width = width;
	if (check_map_enclosed(game) != 0)
		return (fail_map_enclosed(game, grid));
	return (0);
}

static int	get_map_max_width(t_list *lst)
{
	int	width;

	width = 0;
	while (lst)
	{
		if ((int)ft_strlen(lst->content) > width)
			width = ft_strlen(lst->content);
		lst = lst->next;
	}
	return (width);
}

static int	pad_map_lines(t_list *lst, int width)
{
	char	*line;
	char	*padded;
	int		len;

	while (lst)
	{
		line = lst->content;
		len = (int)ft_strlen(line);
		padded = ft_calloc(width + 1, sizeof(char));
		if (!padded)
			return (fatal(NULL, ERR_ALLOC, NULL));
		ft_memset(padded, ' ', width);
		if (len > 0)
			ft_memcpy(padded, line, len);
		free(line);
		lst->content = padded;
		lst = lst->next;
	}
	return (0);
}

static void	fill_grid_from_list(char **grid, t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		grid[i++] = lst->content;
		lst = lst->next;
	}
}

static int	fail_map_enclosed(t_game *game, char **grid)
{
	game->map.grid = NULL;
	game->map.height = 0;
	game->map.width = 0;
	free(grid);
	return (fatal(game, ERR_MAP, "Map not enclosed"));
}
