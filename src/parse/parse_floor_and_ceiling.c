/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_and_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:52:26 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:17:45 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_color_channel(const char *str, int *out);
static int	parse_color(int *out, char *s);

int	parse_floor_and_ceil(t_game *game, int key_len, char key, char *rest)
{
	if (key_len != 1)
		return (1);
	if (key == 'F')
	{
		if (game->config.parsed.floor)
			return (-1);
		if (parse_color(&game->config.floor_color, rest))
			return (-1);
		game->config.parsed.floor = 1;
		return (0);
	}
	if (key == 'C')
	{
		if (game->config.parsed.ceil)
			return (-1);
		if (parse_color(&game->config.ceil_color, rest))
			return (-1);
		game->config.parsed.ceil = 1;
		return (0);
	}
	return (1);
}

static int	parse_color_channel(const char *str, int *out)
{
	long	n;

	if (!*str)
		return (1);
	n = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		n = n * 10 + (*str - '0');
		if (n < 0 || 255 < n)
			return (1);
		str++;
	}
	*out = (int)n;
	return (0);
}

static int	parse_color(int *color, char *str)
{
	char	**vec;
	int		r;
	int		g;
	int		b;

	vec = ft_split(str, ',');
	if (!vec || !vec[0] || !vec[1] || !vec[2] || vec[3])
	{
		free_split(vec);
		return (1);
	}
	if (parse_color_channel(vec[0], &r) || parse_color_channel(vec[1], &g)
		|| parse_color_channel(vec[2], &b))
	{
		free_split(vec);
		return (1);
	}
	free_split(vec);
	*color = (r << 16) | (g << 8) | b;
	return (0);
}
