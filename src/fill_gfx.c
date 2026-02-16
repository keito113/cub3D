/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:48:22 by takawagu          #+#    #+#             */
/*   Updated: 2026/02/10 15:52:24 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static int	init_window(t_game *game); // init_window() の関数宣言。目的: windowを初期化する

/* 関数概要: fill_gfx - 描画コンテキストを埋めて設定する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: mlx_init() -> fatal() -> init_window() -> mlx_new_image()。 */
int	fill_gfx(t_game *game) // fill_gfx関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	game->gfx.mlx = mlx_init(); // game->gfx.mlx に mlx_init() の計算結果を代入する
	if (!game->gfx.mlx) // !game- > gfx.mlx が成立する場合に分岐する
		return (fatal(game, ERR_MLX, NULL)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	if (init_window(game) != 0) // init_window()が非0（失敗）を返す場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	game->gfx.screen.ptr = mlx_new_image(game->gfx.mlx, game->gfx.win_w, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			game->gfx.win_h); // 文 `game->gfx.win_h);` を実行する
	if (!game->gfx.screen.ptr) // !game- > gfx.screen.ptr が成立する場合に分岐する
		return (fatal(game, ERR_IMG, NULL)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	game->gfx.screen.addr = mlx_get_data_addr(game->gfx.screen.ptr, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			&game->gfx.screen.bpp, &game->gfx.screen.line_len, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			&game->gfx.screen.endian); // 文 `&game->gfx.screen.endian);` を実行する
	game->gfx.screen.img_width = game->gfx.win_w; // game->gfx.screen.img_width に game->gfx.win_w の計算結果を代入する
	game->gfx.screen.img_height = game->gfx.win_h; // game->gfx.screen.img_height に game->gfx.win_h の計算結果を代入する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: init_window - windowを初期化する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: mlx_new_window() -> fatal()。 */
static int	init_window(t_game *game) // init_window関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	game->gfx.win_w = game->map.width * 50; // game->gfx.win_w に game->map.width * 50 の計算結果を代入する
	game->gfx.win_h = game->map.height * 50; // game->gfx.win_h に game->map.height * 50 の計算結果を代入する
	game->gfx.win = mlx_new_window(game->gfx.mlx, game->gfx.win_w, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			game->gfx.win_h, "cub3D"); // 変数 win_h（win_hの作業用値） を宣言する
	if (!game->gfx.win) // !game- > gfx.win が成立する場合に分岐する
		return (fatal(game, ERR_MLX, NULL)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
