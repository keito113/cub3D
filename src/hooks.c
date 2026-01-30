/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:54:35 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 19:13:09 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (handle_close(game));
	if (keycode == KEY_W)
		game->input.key_w = 1;
	else if (keycode == KEY_S)
		game->input.key_s = 1;
	else if (keycode == KEY_A)
		game->input.key_a = 1;
	else if (keycode == KEY_D)
		game->input.key_d = 1;
	else if (keycode == KEY_LEFT)
		game->input.key_left = 1;
	else if (keycode == KEY_RIGHT)
		game->input.key_right = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->input.key_w = 0;
	else if (keycode == KEY_S)
		game->input.key_s = 0;
	else if (keycode == KEY_A)
		game->input.key_a = 0;
	else if (keycode == KEY_D)
		game->input.key_d = 0;
	else if (keycode == KEY_LEFT)
		game->input.key_left = 0;
	else if (keycode == KEY_RIGHT)
		game->input.key_right = 0;
	return (0);
}

int	handle_close(t_game *game)
{
	game_destroy(game);
	exit(0);
}
