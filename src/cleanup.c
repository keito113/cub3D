/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:03:53 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/26 17:41:06 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	free_map(t_game *game); // free_map() の関数宣言。目的: マップ情報を解放する
static void	free_config(t_game *game); // free_config() の関数宣言。目的: 設定を解放する

/* 関数概要: game_destroy - 確保済み画像・ウィンドウ・マップ・設定メモリを解放する。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: mlx_destroy_image() -> mlx_destroy_window() -> free_map() -> free_config()。 */
void	game_destroy(t_game *game) // game_destroy関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	i; // 変数 i（ループ用インデックス） を宣言する

	if (!game) // 条件(!game)が成立する場合に分岐する
		return ; // この時点で関数を終了して呼び出し元へ戻る
	i = 0; // i に 0 の計算結果を代入する
	while (i < TEX_MAX) // i < TEX_MAX が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (game->gfx.tex[i].ptr) // game- > gfx.tex[i].ptr が成立する場合に分岐する
			mlx_destroy_image(game->gfx.mlx, game->gfx.tex[i].ptr); // mlx_destroy_image() を呼び出して、mlxを破棄する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	if (game->gfx.screen.ptr) // game- > gfx.screen.ptr が成立する場合に分岐する
		mlx_destroy_image(game->gfx.mlx, game->gfx.screen.ptr); // mlx_destroy_image() を呼び出して、mlxを破棄する
	if (game->gfx.win) // game- > gfx.win が成立する場合に分岐する
		mlx_destroy_window(game->gfx.mlx, game->gfx.win); // mlx_destroy_window() を呼び出して、mlxを破棄する
	free_map(game); // free_map() を呼び出して、マップ情報を解放する
	free_config(game); // free_config() を呼び出して、設定を解放する
	if (game->gfx.mlx) // game- > gfx.mlx が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		mlx_destroy_display(game->gfx.mlx); // mlx_destroy_display() を呼び出して、mlxを破棄する
		free(game->gfx.mlx); // free() を呼び出して、対象を解放する
		game->gfx.mlx = NULL; // game->gfx.mlx に NULL の計算結果を代入する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: free_map - マップ情報を解放する。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: free()。 */
static void	free_map(t_game *game) // free_map関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	y; // 変数 y（Y座標） を宣言する

	if (!game->map.grid) // !game- > map.grid が成立する場合に分岐する
		return ; // この時点で関数を終了して呼び出し元へ戻る
	y = 0; // y に 0 の計算結果を代入する
	while (game->map.grid[y]) // game- > map.grid[y] が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		free(game->map.grid[y]); // free() を呼び出して、対象を解放する
		y++; // 文 `y++;` を実行する
	} // ここでブロックスコープを終了する
	free(game->map.grid); // free() を呼び出して、対象を解放する
	game->map.grid = NULL; // game->map.grid に NULL の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: free_config - 設定を解放する。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: free()。 */
static void	free_config(t_game *game) // free_config関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (i < TEX_MAX) // i < TEX_MAX が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		free(game->config.tex_path[i]); // free() を呼び出して、対象を解放する
		game->config.tex_path[i] = NULL; // game->config.tex_path[i] に NULL の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する
