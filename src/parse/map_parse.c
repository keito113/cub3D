/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:55:59 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/26 19:11:58 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	res = parse_floor_and_ceil(game, key_len, *key, rest);
	if (res < 0)
		return (1);
	if (res == 0)
		return (0);
	*in_map = 1;
	return (0);
}
