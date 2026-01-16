/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:51:27 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/16 19:07:19 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (args_validate(&game, argc, argv))
		return (1);
	if (game_prepare(&game, argv))
	{
		game_destroy(&game);
		return (1);
	}
	game_run(&game);
	game_destroy(&game);
	return (0);
}
