/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:38:28 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:48:26 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: game_prepare - ゲーム開始前に初期化・マップ読み込み・描画リソース準備を順番に完了させる。引数(t_game *game, char **argv)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: game_init() -> read_map() -> fill_gfx() -> load_textures()。 */
int	game_prepare(t_game *game, char **argv) // game_prepare関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (game_init(game, argv[1]) != 0) // game_init()が非0（失敗）を返す場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (read_map(game, argv[1]) != 0) // read_map()が非0（失敗）を返す場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (fill_gfx(game) != 0) // fill_gfx()が非0（失敗）を返す場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (load_textures(game) != 0) // load_textures()が非0（失敗）を返す場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (fill_player_config(game) != 0) // fill_player_config()が非0（失敗）を返す場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: game_update - 1フレーム分の移動更新とレイキャスト描画を行って画面へ転送する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: handle_movement() -> raycast_frame() -> mlx_put_image_to_window()。 */
int	game_update(t_game *game) // game_update関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	handle_movement(game); // handle_movement() を呼び出して、入力フラグに応じて移動/回転を反映する
	raycast_frame(game); // raycast_frame() を呼び出して、画面横方向を走査して各列のレイ計算と壁描画を行う
	mlx_put_image_to_window(game->gfx.mlx, game->gfx.win, // 関数呼び出し引数をこの行で追加し、次行へ続ける
		game->gfx.screen.ptr, 0, 0); // 変数 ptr（ptrの作業用値） を宣言する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: game_run - フック登録後にMLXメインループを開始する。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: raycast_frame() -> mlx_put_image_to_window() -> mlx_hook() -> mlx_loop_hook()。 */
void	game_run(t_game *game) // game_run関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	raycast_frame(game); // raycast_frame() を呼び出して、画面横方向を走査して各列のレイ計算と壁描画を行う
	mlx_put_image_to_window(game->gfx.mlx, game->gfx.win, // 関数呼び出し引数をこの行で追加し、次行へ続ける
		game->gfx.screen.ptr, 0, 0); // 変数 ptr（ptrの作業用値） を宣言する
	mlx_hook(game->gfx.win, 2, 1L << 0, handle_key_press, game); // イベント番号に対応するコールバックを登録する
	mlx_hook(game->gfx.win, 3, 1L << 1, handle_key_release, game); // イベント番号に対応するコールバックを登録する
	mlx_hook(game->gfx.win, 17, 0, handle_close, game); // イベント番号に対応するコールバックを登録する
	mlx_loop_hook(game->gfx.mlx, game_update, game); // メインループ1周ごとの更新コールバックを登録する
	mlx_loop(game->gfx.mlx); // MLXイベントループを開始し、入力/描画処理を継続する
} // ここでブロックスコープを終了する
