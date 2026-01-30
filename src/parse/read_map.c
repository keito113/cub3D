/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:48:36 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/30 19:30:43 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	push_line(t_list **lst, char *str)
{
	t_list	*node;

	node = ft_lstnew(str);
	if (!node)
	{
		free(str);
		return (fatal(NULL, ERR_ALLOC, NULL));
	}
	ft_lstadd_back(lst, node);
	return (0);
}

static int	handle_line(t_game *game, char *line, int *in_map, t_list **map)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (*in_map)
		return (push_line(map, line));
	if (parse_config_line(game, line, in_map) == 0)
	{
		if (*in_map)
			return (push_line(map, line));
		free(line);
		return (0);
	}
	free(line);
	return (fatal(game, ERR_PARSE, "Invalid line"));
}

static int	cleanup_err(int fd, t_list **map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static void	free_list_nodes(t_list **lst)
{
	t_list	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	read_map(t_game *game, const char *path)
{
	int		fd;
	char	*line;
	int		in_map;
	t_list	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fatal(game, ERR_OPEN, path));
	in_map = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (handle_line(game, line, &in_map, &map))
			return (cleanup_err(fd, &map));
		line = get_next_line(fd);
	}
	close(fd);
	if (finalize_map(game, map) != 0)
	{
		ft_lstclear(&map, free);
		return (1);
	}
	free_list_nodes(&map);
	return (0);
}
