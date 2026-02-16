/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:35:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	dda_step(t_game *game); // dda_step() の関数宣言。目的: 次に近い境界(X/Y)を選んで side_dist と map座標を1ステップ進める
static int	is_hit_cell(t_game *game, int map_x, int map_y); // is_hit_cell() の関数宣言。目的: 指定マップ座標が壁セルまたは無効領域かどうかを判定する

/* 関数概要: dda - レイが壁に当たるまで DDA でマップセルを1マスずつ進める。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: dda_step() -> is_hit_cell()。 */
void	dda(t_game *game) // dda関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	game->ray.hit = 0; // 壁ヒットフラグを0に設定する
	while (game->ray.hit == 0) // game- > ray.hit == 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		dda_step(game); // dda_step() を呼び出して、次に近い境界(X/Y)を選んで side_dist と map座標を1ステップ進める
		if (is_hit_cell(game, game->ray.map_x, game->ray.map_y)) // is_hit_cell()で指定マップ座標が壁セルまたは無効領域かどうかを判定し、その戻り値が非0（真）なら分岐する
			game->ray.hit = 1; // 壁ヒットフラグを1に設定する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: dda_step - 次に近い境界(X/Y)を選んで side_dist と map座標を1ステップ進める。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	dda_step(t_game *game) // dda_step関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (game->ray.side_dist_x < game->ray.side_dist_y) // game- > ray.side_dist_x < game->ray.side_dist_y が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		game->ray.side_dist_x += game->ray.delta_dist_x; // 次のX境界までの距離(side_dist_x)をdelta_dist_xぶん進める
		game->ray.map_x += game->ray.step_x; // DDA進行方向(step_x)ぶんマップXセルを1つ進める
		game->ray.side = 0; // ヒット壁面をX側(0)またはY側(1)として記録する
	} // ここでブロックスコープを終了する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
	{ // ここからブロックスコープを開始する
		game->ray.side_dist_y += game->ray.delta_dist_y; // 次のY境界までの距離(side_dist_y)をdelta_dist_yぶん進める
		game->ray.map_y += game->ray.step_y; // DDA進行方向(step_y)ぶんマップYセルを1つ進める
		game->ray.side = 1; // ヒット壁面をX側(0)またはY側(1)として記録する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: is_hit_cell - 指定マップ座標が壁セルまたは無効領域かどうかを判定する。引数(t_game *game, int map_x, int map_y)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static int	is_hit_cell(t_game *game, int map_x, int map_y) // is_hit_cell関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	cell; // 変数 cell（マップセル文字） を宣言する

	if (map_y < 0 || map_y >= game->map.height || map_x < 0 // 座標がマップ範囲外である または 座標がマップ範囲外である または 座標がマップ範囲外である場合に分岐する
		|| map_x >= game->map.width) // 前行の条件式へ OR 条件を追加する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	cell = game->map.grid[map_y][map_x]; // cell に game->map.grid[map_y][map_x] の計算結果を代入する
	return (cell == '1' || cell == ' '); // 関数を終了し、cell == '1' || cell == ' ' を呼び出し元へ返す
} // ここでブロックスコープを終了する
