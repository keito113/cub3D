/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:51:27 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/27 15:01:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (args_validate(&game, argc, argv))
		return (1);
	if (game_init(&game, argv[1]) != 0)
		return (1);
	if (parse_file(&game, argv[1]) != 0)
		return (1);
	if (gfx_init(&game) != 0)
		return (1);
	draw_map(&game);
	mlx_put_image_to_window(game.gfx.mlx, game.gfx.win,
		game.gfx.screen.ptr, 0, 0);
	/* hook 登録 */
	mlx_hook(game.gfx.win, 2, 1L << 0, handle_key, &game);   /* KeyPress */
	mlx_hook(game.gfx.win, 17, 0, handle_close, &game);      /* DestroyNotify */

	mlx_loop(game.gfx.mlx);
	game_destroy(&game);
	return (0);
}

