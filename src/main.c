/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:51:27 by keitabe           #+#    #+#             */
/*   Updated: 2026/02/10 15:28:54 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	if (args_validate(&game, argc, argv))
		return (1);
	if (game_prepare(&game, argv))
		return (1);
	game_run(&game);
	game_destroy(&game);
	return (0);
}
