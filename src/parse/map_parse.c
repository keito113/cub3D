/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:55:59 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/17 18:21:02 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_tex(t_config *config, int i, char *rest)
{
	char	*path;

	if (config->parsed.tex[i])
		return (1);
	rest = skip_space(rest);
	if (*rest == '\0')
		return (1);
	path = ft_strdup(rest);
	if (!path)
		return (1);
	config->tex_path[i] = path;
	config->parsed.tex[i] = 1;
	return (0);
}

static int	tex_wrap(t_config *config, int idx, char *rest)
{
	int	err;

	err = parse_tex(config, idx, rest);
	if (err != 0)
		return (-1);
	return (0);
}

static int	handle_texture(char *key, int key_len, t_game *game, char *rest)
{
	if (key_len != 2)
		return (1);
	if (ft_strncmp(key, "NO", 2) == 0)
		return (tex_wrap(&game->config, TEX_NO, rest));
	if (ft_strncmp(key, "SO", 2) == 0)
		return (tex_wrap(&game->config, TEX_SO, rest));
	if (ft_strncmp(key, "WE", 2) == 0)
		return (tex_wrap(&game->config, TEX_WE, rest));
	if (ft_strncmp(key, "EA", 2) == 0)
		return (tex_wrap(&game->config, TEX_EA, rest));
	return (1);
}

static int	parse_fc(t_game *game, int key_len, char key, char *rest)
{
	if (key_len != 1)
		return (1);
	if (key == 'F')
	{
		if (game->config.parsed.floor)
			return (1);
		if (parse_color(&game->config.floor_color, rest))
			return (1);
		game->config.parsed.floor = 1;
		return (0);
	}
	if (key == 'C')
	{
		if (game->config.parsed.ceil)
			return (1);
		if (parse_color(&game->config.ceil_color, rest))
			return (1);
		game->config.parsed.ceil = 1;
		return (0);
	}
	return (1);
}

int	parse_config_line(t_game *game, char *line, int *in_map)
{
	char	*key;
	char	*rest;
	int		key_len;
	int		res;

	line = skip_space(line);
	if (*line == '\0')
		return (0);
	key = line;
	while (*line && *line != ' ' && *line != '\t')
		line++;
	key_len = line - key;
	rest = skip_space(line);
	res = handle_texture(key, key_len, game, rest);
	if (res < 0)
		return (1);
	if (res == 0)
		return (0);
	if (parse_fc(game, key_len, *key, rest) == 0)
		return (0);
	*in_map = 1;
	return (0);
}
