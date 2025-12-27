/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:54:35 by takawagu          #+#    #+#             */
/*   Updated: 2025/12/27 15:01:17 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_close(t_game *g)
{
	game_destroy(g);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_game *g)
{
	if (keycode == 65307) /* ESC */
		return (handle_close(g));
	return (0);
}