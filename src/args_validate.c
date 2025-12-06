/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:02:33 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/03 14:45:19 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_cub_ext(const char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	args_validate(t_game *g, int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (fatal(g, ERR_USAGE, NULL));
	if (!has_cub_ext(av[1]))
		return (fatal(g, ERR_EXT, av[1]));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (fatal(g, ERR_OPEN, av[1]));
	close(fd);
	return (0);
}
