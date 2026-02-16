/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_player_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:27:00 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 18:49:22 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: set_player_start - プレイヤー状態・startを設定する。引数(t_game *game, int x, int y, char c)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: set_player_dir()。 */
static int	set_player_start(t_game *game, int x, int y, char c) // set_player_start関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	game->player.x = x + 0.5; // game->player.x に x + 0.5 の計算結果を代入する
	game->player.y = y + 0.5; // game->player.y に y + 0.5 の計算結果を代入する
	set_player_dir(&game->player, c); // set_player_dir() を呼び出して、プレイヤー状態・dirを設定する
	game->map.grid[y][x] = '0'; // game->map.grid[y][x] に '0' の計算結果を代入する
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: fill_player_config - プレイヤー状態・設定を埋めて設定する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> set_player_start() -> fatal()。 */
int	fill_player_config(t_game *game) // fill_player_config関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		x; // 変数 x（X座標） を宣言する
	int		y; // 変数 y（Y座標） を宣言する
	int		found; // 変数 found（探索ヒット数/フラグ） を宣言する
	char	c; // 変数 c（1文字の判定用値） を宣言する

	found = 0; // found に 0 の計算結果を代入する
	y = 0; // y に 0 の計算結果を代入する
	while (y < game->map.height) // 座標がマップ範囲外である場合に分岐する
	{ // ここからブロックスコープを開始する
		x = 0; // x に 0 の計算結果を代入する
		while (x < (int)ft_strlen(game->map.grid[y])) // x < (int)ft_strlen(game->map.grid[y]) が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			c = game->map.grid[y][x]; // c に game->map.grid[y][x] の計算結果を代入する
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W') // c == 'N' が成立する または c == 'S' が成立する または c == 'E' が成立する または c == 'W' が成立する場合に分岐する
				found += set_player_start(game, x, y, c); // found を += で更新し、set_player_start(game, x, y, c) を反映する
			x++; // 文 `x++;` を実行する
		} // ここでブロックスコープを終了する
		y++; // 文 `y++;` を実行する
	} // ここでブロックスコープを終了する
	if (found == 0) // found == 0 が成立する場合に分岐する
		return (fatal(game, ERR_MAP, "No player start")); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	if (found > 1) // found > 1 が成立する場合に分岐する
		return (fatal(game, ERR_MAP, "Multiple player starts")); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
