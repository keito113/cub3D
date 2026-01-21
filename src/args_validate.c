/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:02:33 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/21 12:08:38 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_cub_file(const char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	args_validate(t_game *game, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (fatal(game, ERR_USAGE, NULL));
	if (!is_cub_file(argv[1]))
		return (fatal(game, ERR_EXT, argv[1]));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (fatal(game, ERR_OPEN, argv[1]));
	close(fd);
	return (0);
}
