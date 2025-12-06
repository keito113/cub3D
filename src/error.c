/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:17:12 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/03 14:23:19 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static const char	*msg_of(t_errc c)
{
	if (c == ERR_USAGE)
		return ("Usage: ./cub3D file.cub");
	if (c == ERR_EXT)
		return ("Invalid extension");
	if (c == ERR_OPEN)
		return ("Cannot open file");
	if (c == ERR_PARSE)
		return ("Parse error");
	if (c == ERR_MAP)
		return ("Map error");
	if (c == ERR_MLX)
		return ("MLX init failed");
	if (c == ERR_IMG)
		return ("Texture load failed");
	if (c == ERR_ALLOC)
		return ("Memory allocation failed");
	return ("Fatal error");
}

int	fatal(t_game *g, t_errc code, const char *detail)
{
	const char	*msg;

	msg = msg_of(code);
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	if (detail)
	{
		write(2, ": ", 2);
		write(2, detail, ft_strlen(detail));
	}
	write(2, "\n", 1);
	game_destroy(g);
	return (1);
}
