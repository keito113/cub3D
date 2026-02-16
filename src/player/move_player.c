/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:45:38 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:18:02 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static int	is_wall(t_game *game, double x, double y); // is_wall() の関数宣言。目的: 壁セルかどうかを判定する

/* 関数概要: move_player - プレイヤー状態を移動する。引数(t_game *game, double dx, double dy)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: is_wall()。 */
void	move_player(t_game *game, double dx, double dy) // move_player関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	double	nx; // 変数 nx（移動後候補のX座標） を宣言する
	double	ny; // 変数 ny（移動後候補のY座標） を宣言する

	nx = game->player.x + dx; // nx に game->player.x + dx の計算結果を代入する
	ny = game->player.y + dy; // ny に game->player.y + dy の計算結果を代入する
	if (!is_wall(game, nx, game->player.y)) // is_wall()で壁セルかどうかを判定した結果が偽（条件不成立）なら分岐する
		game->player.x = nx; // game->player.x に nx の計算結果を代入する
	if (!is_wall(game, game->player.x, ny)) // is_wall()で壁セルかどうかを判定した結果が偽（条件不成立）なら分岐する
		game->player.y = ny; // game->player.y に ny の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: is_wall - 壁セルかどうかを判定する。引数(t_game *game, double x, double y)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static int	is_wall(t_game *game, double x, double y) // is_wall関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		grid_x; // 変数 grid_x（グリッドX座標） を宣言する
	int		grid_y; // 変数 grid_y（グリッドY座標） を宣言する
	char	c; // 変数 c（1文字の判定用値） を宣言する

	grid_x = (int)x; // grid_x に (int)x の計算結果を代入する
	grid_y = (int)y; // grid_y に (int)y の計算結果を代入する
	if (grid_y < 0 || grid_y >= game->map.height || grid_x < 0 // grid_y < 0 が成立する または 座標がマップ範囲外である または grid_x < 0 が成立する場合に分岐する
		|| grid_x >= game->map.width) // 前行の条件式へ OR 条件を追加する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	c = game->map.grid[grid_y][grid_x]; // c に game->map.grid[grid_y][grid_x] の計算結果を代入する
	return (c == '1' || c == ' '); // 関数を終了し、c == '1' || c == ' ' を呼び出し元へ返す
} // ここでブロックスコープを終了する
