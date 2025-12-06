/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:55:59 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/06 17:03:57 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_ws(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

static int	parse_tex(t_config *cfg, int idx, char *rest)
{
	char	*path;

	rest = skip_ws(rest);
	if (*rest == '\0')
		return (1);
	path = ft_strdup(rest);
	if (!path)
		return (1);
	cfg->tex_path[idx] = path;
	cfg->parsed_mask |= (1 << idx);
	return (0);
}

int	parse_id_line(t_game *g, char *line, int *in_map)
{
	char	*id;
	char	*rest;
	int		id_len;

	line = skip_ws(line);
	if (*line == '\0')
		return (0);
	id = line;
	while (*line && *line != ' ' && *line != '\t')
		line++;
	id_len = line - id;
	rest = skip_ws(line);
	if (id_len == 2 && ft_strncmp(id, "NO", 2) == 0 && !parse_tex(&g->config,
			TEX_NO, rest))
		return (0);
	if (id_len == 2 && ft_strncmp(id, "SO", 2) == 0 && !parse_tex(&g->config,
			TEX_SO, rest))
		return (0);
	if (id_len == 2 && ft_strncmp(id, "WE", 2) == 0 && !parse_tex(&g->config,
			TEX_WE, rest))
		return (0);
	if (id_len == 2 && ft_strncmp(id, "EA", 2) == 0 && !parse_tex(&g->config,
			TEX_EA, rest))
		return (0);
	if (id_len == 1 && *id == 'F' && !parse_color(&g->config.floor_color, rest))
		return (g->config.parsed_mask |= (1 << 4), 0);
	if (id_len == 1 && *id == 'C' && !parse_color(&g->config.ceil_color, rest))
		return (g->config.parsed_mask |= (1 << 5), 0);
	*in_map = 1;
	return (0);
}
