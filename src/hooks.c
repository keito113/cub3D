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

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: handle_key_press - キー押下イベントを受けて入力フラグを立てる。引数(int keycode, t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: handle_close()。 */
int	handle_key_press(int keycode, t_game *game) // handle_key_press関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (keycode == KEY_ESC) // keycode == KEY_ESC が成立する場合に分岐する
		return (handle_close(game)); // 関数を終了し、handle_close(game) を呼び出し元へ返す
	if (keycode == KEY_W) // keycode == KEY_W が成立する場合に分岐する
		game->input.key_w = 1; // game->input.key_w に 1 の計算結果を代入する
	else if (keycode == KEY_S) // keycode == KEY_S が成立する場合に分岐する
		game->input.key_s = 1; // game->input.key_s に 1 の計算結果を代入する
	else if (keycode == KEY_A) // keycode == KEY_A が成立する場合に分岐する
		game->input.key_a = 1; // game->input.key_a に 1 の計算結果を代入する
	else if (keycode == KEY_D) // keycode == KEY_D が成立する場合に分岐する
		game->input.key_d = 1; // game->input.key_d に 1 の計算結果を代入する
	else if (keycode == KEY_LEFT) // keycode == KEY_LEFT が成立する場合に分岐する
		game->input.key_left = 1; // game->input.key_left に 1 の計算結果を代入する
	else if (keycode == KEY_RIGHT) // keycode == KEY_RIGHT が成立する場合に分岐する
		game->input.key_right = 1; // game->input.key_right に 1 の計算結果を代入する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: handle_key_release - キー離上イベントを受けて入力フラグを下ろす。引数(int keycode, t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
int	handle_key_release(int keycode, t_game *game) // handle_key_release関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (keycode == KEY_W) // keycode == KEY_W が成立する場合に分岐する
		game->input.key_w = 0; // game->input.key_w に 0 の計算結果を代入する
	else if (keycode == KEY_S) // keycode == KEY_S が成立する場合に分岐する
		game->input.key_s = 0; // game->input.key_s に 0 の計算結果を代入する
	else if (keycode == KEY_A) // keycode == KEY_A が成立する場合に分岐する
		game->input.key_a = 0; // game->input.key_a に 0 の計算結果を代入する
	else if (keycode == KEY_D) // keycode == KEY_D が成立する場合に分岐する
		game->input.key_d = 0; // game->input.key_d に 0 の計算結果を代入する
	else if (keycode == KEY_LEFT) // keycode == KEY_LEFT が成立する場合に分岐する
		game->input.key_left = 0; // game->input.key_left に 0 の計算結果を代入する
	else if (keycode == KEY_RIGHT) // keycode == KEY_RIGHT が成立する場合に分岐する
		game->input.key_right = 0; // game->input.key_right に 0 の計算結果を代入する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: handle_close - ウィンドウクローズ時に終了処理を実行する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: game_destroy() -> exit()。 */
int	handle_close(t_game *game) // handle_close関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	game_destroy(game); // game_destroy() を呼び出して、確保済み画像・ウィンドウ・マップ・設定メモリを解放する
	exit(0); // exit() を呼び出して、exitを実行する
} // ここでブロックスコープを終了する
