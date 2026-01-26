/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:51:22 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/26 16:56:14 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_split(char **vec)
{
	int	i;

	if (!vec)
		return ;
	i = 0;
	while (vec[i])
	{
		free(vec[i]);
		i++;
	}
	free(vec);
}

static int	parse_chan(const char *s, int *out)
{
	long	n;

	if (!*s)
		return (1);
	n = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		n = n * 10 + (*s - '0');
		if (n > 255)
			return (1);
		s++;
	}
	*out = (int)n;
	return (0);
}

int	parse_color(int *out, char *s)
{
	char	**vec;
	int		r;
	int		g;
	int		b;

	vec = ft_split(s, ',');
	if (!vec || !vec[0] || !vec[1] || !vec[2] || vec[3])
	{
		free_split(vec);
		return (1);
	}
	if (parse_chan(vec[0], &r) || parse_chan(vec[1], &g) || parse_chan(vec[2], &b))
	{
		free_split(vec);
		return (1);
	}
	free_split(vec);
	*out = (r << 16) | (g << 8) | b;
	return (0);
}

char	*skip_space(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}
