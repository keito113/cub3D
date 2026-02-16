/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_enclosed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:43:10 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 18:20:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static char	cell_at(char **grid, int y, int x); // cell_at() の関数宣言。目的: 指定座標のセル文字を安全に取り出す
static int	is_walkable(char c); // is_walkable() の関数宣言。目的: 通行可能セルかどうかを判定する
static int	is_open_to_space(char **grid, int y, int x); // is_open_to_space() の関数宣言。目的: 周囲が空白/外周へ開いていないか判定する

/* 関数概要: check_map_enclosed - マップ情報・enclosedを検証する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> is_walkable() -> is_open_to_space()。 */
int	check_map_enclosed(t_game *game) // check_map_enclosed関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		x; // 変数 x（X座標） を宣言する
	int		y; // 変数 y（Y座標） を宣言する
	int		len; // 変数 len（文字列長） を宣言する
	char	c; // 変数 c（1文字の判定用値） を宣言する

	y = 0; // y に 0 の計算結果を代入する
	while (y < game->map.height) // 座標がマップ範囲外である場合に分岐する
	{ // ここからブロックスコープを開始する
		x = 0; // x に 0 の計算結果を代入する
		len = (int)ft_strlen(game->map.grid[y]); // len に (int)ft_strlen(game->map.grid[y]) の計算結果を代入する
		while (x < len) // x < len が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			c = game->map.grid[y][x]; // c に game->map.grid[y][x] の計算結果を代入する
			if (is_walkable(c)) // is_walkable()で通行可能セルかどうかを判定し、その戻り値が非0（真）なら分岐する
			{ // ここからブロックスコープを開始する
				if (is_open_to_space(game->map.grid, y, x)) // is_open_to_space()で周囲が空白/外周へ開いていないか判定し、その戻り値が非0（真）なら分岐する
					return (1); // 関数を終了し、1 を呼び出し元へ返す
			} // ここでブロックスコープを終了する
			x++; // 文 `x++;` を実行する
		} // ここでブロックスコープを終了する
		y++; // 文 `y++;` を実行する
	} // ここでブロックスコープを終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: cell_at - 指定座標のセル文字を安全に取り出す。引数(char **grid, int y, int x)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen()。 */
static char	cell_at(char **grid, int y, int x) // cell_at関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	len; // 変数 len（文字列長） を宣言する

	if (y < 0 || x < 0 || !grid[y]) // y < 0 が成立する または x < 0 が成立する または 条件(!grid[y])が成立する場合に分岐する
		return (' '); // 関数を終了し、' ' を呼び出し元へ返す
	len = (int)ft_strlen(grid[y]); // len に (int)ft_strlen(grid[y]) の計算結果を代入する
	if (x >= len) // x >= len が成立する場合に分岐する
		return (' '); // 関数を終了し、' ' を呼び出し元へ返す
	return (grid[y][x]); // 関数を終了し、grid[y][x] を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: is_walkable - 通行可能セルかどうかを判定する。引数(char c)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static int	is_walkable(char c) // is_walkable関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'); // 関数を終了し、c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: is_open_to_space - 周囲が空白/外周へ開いていないか判定する。引数(char **grid, int y, int x)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: cell_at()。 */
static int	is_open_to_space(char **grid, int y, int x) // is_open_to_space関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (cell_at(grid, y - 1, x) == ' ') // cell_at(grid, y - 1, x) == ' ' が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (cell_at(grid, y + 1, x) == ' ') // cell_at(grid, y + 1, x) == ' ' が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (cell_at(grid, y, x - 1) == ' ') // cell_at(grid, y, x - 1) == ' ' が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (cell_at(grid, y, x + 1) == ' ') // cell_at(grid, y, x + 1) == ' ' が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
