/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:15:44 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/17 18:42:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finalize_map(t_game *game, t_list *lst)
{
	int		i;
	int		height;
	int		width;
	char	**grid;

	height = ft_lstsize(lst);
	if (height == 0)
		return (fatal(game, ERR_MAP, "Map missing"));
	grid = ft_calloc(height + 1, sizeof(char *));
	if (!grid)
		return (fatal(game, ERR_ALLOC, NULL));
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
	game->map.grid = grid;
	game->map.height = height;
	game->map.width = width;
	return (0);
}
