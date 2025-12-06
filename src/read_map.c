/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:48:36 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/06 13:31:18 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	push_line(t_list **lst, char *s)
{
	t_list	*node;

	node = ft_lstnew(s);
	if (!node)
	{
		free(s);
		return (fatal(NULL, ERR_ALLOC, NULL));
	}
	ft_lstadd_back(lst, node);
	return (0);
}

static int	finalize_map(t_game *g, t_list *lst)
{
	int		i;
	int		h;
	int		w;
	char	**grid;

	h = ft_lstsize(lst);
	if (h == 0)
		return (fatal(g, ERR_MAP, "Map missing"));
	grid = ft_calloc(h + 1, sizeof(char *));
	if (!grid)
		return (fatal(g, ERR_ALLOC, NULL));
	i = 0;
	w = 0;
	while (lst)
	{
		grid[i] = lst->content;
		if ((int)ft_strlen(grid[i]) > w)
			w = ft_strlen(grid[i]);
		lst = lst->next;
		i++;
	}
	g->map.grid = grid;
	g->map.height = h;
	g->map.width = w;
	return (0);
}

static int	handle_line(t_game *g, char *line, int *in_map, t_list **map)
{
	if (*in_map)
		return (push_line(map, line));
	if (parse_id_line(g, line, in_map) == 0)
		return (0);
	if (*in_map)
		return (push_line(map, line));
	free(line);
	return (fatal(g, ERR_PARSE, "Invalid line"));
}

static int	cleanup_err(int fd, t_list **map)
{
	close(fd);
	ft_lstclear(map, free);
	return (1);
}

int	parse_file(t_game *g, const char *path)
{
	int		fd;
	char	*line;
	int		in_map;
	t_list	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fatal(g, ERR_OPEN, path));
	in_map = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (handle_line(g, line, &in_map, &map))
			return (cleanup_err(fd, &map));
		line = get_next_line(fd);
	}
	close(fd);
	if (finalize_map(g, map))
		return (cleanup_err(fd, &map));
	return (0);
}
