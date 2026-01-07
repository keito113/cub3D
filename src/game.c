/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:38:28 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/07 16:02:16 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_prepare(t_game *game,char **argv)
{
	if (game_init(game, argv[1]) != 0)
		return (1);
	if (parse_file(game, argv[1]) != 0)
		return (1);
	if (gfx_init(game) != 0)
		return (1);
	if (load_textures(game) != 0)
		return (1);
	if (fill_player_config(game) != 0)
		return (1);
	return (0);
}
void	game_run(t_game *game)
{
	raycast_frame(game);
	mlx_put_image_to_window(game->gfx.mlx, game->gfx.win,
		game->gfx.screen.ptr, 0, 0);
	mlx_hook(game->gfx.win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->gfx.win, 3, 1L << 1, handle_key_release, game);
	mlx_hook(game->gfx.win, 17, 0, handle_close, game);
	mlx_loop_hook(game->gfx.mlx, game_update, game);
	mlx_loop(game->gfx.mlx);
}
