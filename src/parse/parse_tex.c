/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:09:01 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:11:26 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_tex(t_config *config, int i, char *rest);
static int	tex_wrap(t_config *config, int idx, char *rest);

int	handle_texture(char *key, int key_len, t_game *game, char *rest)
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
