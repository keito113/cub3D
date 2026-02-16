/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:37:45 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 19:31:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: handle_movement - 入力フラグに応じて移動/回転を反映する。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: move_player() -> rotate_player()。 */
void	handle_movement(t_game *game) // handle_movement関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (game->input.key_w) // game- > input.key_w が成立する場合に分岐する
		move_player(game, game->player.dir_x * MOVE_SPEED, game->player.dir_y // 式 `move_player(game, game->player.dir_x * MOVE_SPEED, game->player.dir_y` を評価して処理を進める
			* MOVE_SPEED); // 前行から続く式に演算を連結して計算を完成させる
	if (game->input.key_s) // game- > input.key_s が成立する場合に分岐する
		move_player(game, -game->player.dir_x * MOVE_SPEED, -game->player.dir_y // 式 `move_player(game, -game->player.dir_x * MOVE_SPEED, -game->player.dir_y` を評価して処理を進める
			* MOVE_SPEED); // 前行から続く式に演算を連結して計算を完成させる
	if (game->input.key_d) // game- > input.key_d が成立する場合に分岐する
		move_player(game, game->player.plane_x * MOVE_SPEED, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			game->player.plane_y * MOVE_SPEED); // 文 `game->player.plane_y * MOVE_SPEED);` を実行する
	if (game->input.key_a) // game- > input.key_a が成立する場合に分岐する
		move_player(game, -game->player.plane_x * MOVE_SPEED, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			-game->player.plane_y * MOVE_SPEED); // 文 `-game->player.plane_y * MOVE_SPEED);` を実行する
	if (game->input.key_left) // game- > input.key_left が成立する場合に分岐する
		rotate_player(game, -ROT_SPEED); // rotate_player() を呼び出して、プレイヤー状態を回転する
	if (game->input.key_right) // game- > input.key_right が成立する場合に分岐する
		rotate_player(game, ROT_SPEED); // rotate_player() を呼び出して、プレイヤー状態を回転する
} // ここでブロックスコープを終了する
