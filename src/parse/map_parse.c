/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:55:59 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/08 14:47:30 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_tex(t_config *cfg, int idx, char *rest)
{
	char	*path;

	if (cfg->parsed_mask & (1 << idx))
		return (1);
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

static int	tex_wrap(t_config *cfg, int idx, char *rest)
{
	int	err;

	err = parse_tex(cfg, idx, rest);
	if (err != 0)
		return (-1);
	return (0);
}

static int	handle_texture(char *id, int id_len, t_game *g, char *rest)
{
	if (id_len != 2)
		return (1);
	if (ft_strncmp(id, "NO", 2) == 0)
		return (tex_wrap(&g->config, TEX_NO, rest));
	if (ft_strncmp(id, "SO", 2) == 0)
		return (tex_wrap(&g->config, TEX_SO, rest));
	if (ft_strncmp(id, "WE", 2) == 0)
		return (tex_wrap(&g->config, TEX_WE, rest));
	if (ft_strncmp(id, "EA", 2) == 0)
		return (tex_wrap(&g->config, TEX_EA, rest));
	return (1);
}

static int	parse_fc(t_game *g, int id_len, char id, char *rest)
{
	if (id_len != 1)
		return (1);
	if (id == 'F')
	{
		if (g->config.parsed_mask & (1 << 4))
			return (1);
		if (parse_color(&g->config.floor_color, rest))
			return (1);
		g->config.parsed_mask |= (1 << 4);
		return (0);
	}
	if (id == 'C')
	{
		if (g->config.parsed_mask & (1 << 5))
			return (1);
		if (parse_color(&g->config.ceil_color, rest))
			return (1);
		g->config.parsed_mask |= (1 << 5);
		return (0);
	}
	return (1);
}

int	parse_id_line(t_game *g, char *line, int *in_map)
{
	char	*id;
	char	*rest;
	int		id_len;
	int		res;

	line = skip_ws(line);
	if (*line == '\0')
		return (0);
	id = line;
	while (*line && *line != ' ' && *line != '\t')
		line++;
	id_len = line - id;
	rest = skip_ws(line);
	res = handle_texture(id, id_len, g, rest);
	if (res < 0)
		return (1);
	if (res == 0)
		return (0);
	if (parse_fc(g, id_len, *id, rest) == 0)
		return (0);
	*in_map = 1;
	return (0);
}
