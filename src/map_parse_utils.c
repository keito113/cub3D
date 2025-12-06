/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:51:22 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/06 16:33:06 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_split(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
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
	char	**v;
	int		r;
	int		g;
	int		b;

	v = ft_split(s, ',');
	if (!v || !v[0] || !v[1] || !v[2] || !v[3])
	{
		free_split(v);
		return (1);
	}
	if (parse_chan(v[0], &r) || parse_chan(v[1], &g) || parse_chan(v[2], &b))
	{
		free_split(v);
		return (1);
	}
	free_split(v);
	*out = (r << 16) | (g << 8) | b;
	return (0);
}
