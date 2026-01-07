/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:54:35 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/07 15:50:42 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_close(t_game *game)
{
	game_destroy(game);
	exit(0);
	return (0);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		return (handle_close(game));
	if (keycode == XK_w)
		game->input.key_w = 1;
	else if (keycode == XK_s)
		game->input.key_s = 1;
	else if (keycode == XK_a)
		game->input.key_a = 1;
	else if (keycode == XK_d)
		game->input.key_d = 1;
	else if (keycode == XK_Left)
		game->input.key_left = 1;
	else if (keycode == XK_Right)
		game->input.key_right = 1;
    printf("keycode: %d\n", keycode);
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->input.key_w = 0;
	else if (keycode == XK_s)
		game->input.key_s = 0;
	else if (keycode == XK_a)
		game->input.key_a = 0;
	else if (keycode == XK_d)
		game->input.key_d = 0;
	else if (keycode == XK_Left)
		game->input.key_left = 0;
	else if (keycode == XK_Right)
		game->input.key_right = 0;
	return (0);
}
