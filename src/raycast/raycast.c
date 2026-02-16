/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:38:05 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 19:21:27 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	setup_ray(t_game *g, int x); // setup_ray() の関数宣言。目的: スクリーン列ごとのレイ方向と距離増分を計算する
static void	setup_step(t_game *g); // setup_step() の関数宣言。目的: レイ方向の符号からステップ方向と初期side_distを設定する

/* 関数概要: raycast_frame - 画面横方向を走査して各列のレイ計算と壁描画を行う。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: setup_ray() -> setup_step() -> dda() -> calculate_wall()。 */
void	raycast_frame(t_game *game) // raycast_frame関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int				x; // 変数 x（X座標） を宣言する
	t_wall_slice	slice; // 変数 slice（sliceの作業用値） を宣言する

	x = 0; // x に 0 の計算結果を代入する
	while (x < game->gfx.win_w) // x < game->gfx.win_w が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		setup_ray(game, x); // setup_ray() を呼び出して、スクリーン列ごとのレイ方向と距離増分を計算する
		setup_step(game); // setup_step() を呼び出して、レイ方向の符号からステップ方向と初期side_distを設定する
		dda(game); // dda() を呼び出して、レイが壁に当たるまで DDA でマップセルを1マスずつ進める
		calculate_wall(game); // calculate_wall() を呼び出して、壁を計算する
		slice.screen_x = x; // slice.screen_x に x の計算結果を代入する
		draw_column(game, &slice); // draw_column() を呼び出して、columnを描画する
		x++; // 文 `x++;` を実行する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: setup_ray - スクリーン列ごとのレイ方向と距離増分を計算する。引数(t_game *g, int x)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: fabs()。 */
static void	setup_ray(t_game *g, int x) // setup_ray関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	g->ray.camera_x = 2.0 * x / (double)g->gfx.win_w - 1.0; // g->ray.camera_x に 2.0 * x / (double)g->gfx.win_w - 1.0 の計算結果を代入する
	g->ray.dir_x = g->player.dir_x + g->player.plane_x * g->ray.camera_x; // g->ray.dir_x に g->player.dir_x + g->player.plane_x * g->ray.camera_x の計算結果を代入する
	g->ray.dir_y = g->player.dir_y + g->player.plane_y * g->ray.camera_x; // g->ray.dir_y に g->player.dir_y + g->player.plane_y * g->ray.camera_x の計算結果を代入する
	g->ray.map_x = (int)g->player.x; // g->ray.map_x に (int)g->player.x の計算結果を代入する
	g->ray.map_y = (int)g->player.y; // g->ray.map_y に (int)g->player.y の計算結果を代入する
	if (g->ray.dir_x == 0) // g- > ray.dir_x == 0 が成立する場合に分岐する
		g->ray.delta_dist_x = 1e30; // g->ray.delta_dist_x に 1e30 の計算結果を代入する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
		g->ray.delta_dist_x = fabs(1.0 / g->ray.dir_x); // g->ray.delta_dist_x に fabs(1.0 / g->ray.dir_x) の計算結果を代入する
	if (g->ray.dir_y == 0) // g- > ray.dir_y == 0 が成立する場合に分岐する
		g->ray.delta_dist_y = 1e30; // g->ray.delta_dist_y に 1e30 の計算結果を代入する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
		g->ray.delta_dist_y = fabs(1.0 / g->ray.dir_y); // g->ray.delta_dist_y に fabs(1.0 / g->ray.dir_y) の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: setup_step - レイ方向の符号からステップ方向と初期side_distを設定する。引数(t_game *g)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	setup_step(t_game *g) // setup_step関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (g->ray.dir_x < 0) // g- > ray.dir_x < 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		g->ray.step_x = -1; // g->ray.step_x に -1 の計算結果を代入する
		g->ray.side_dist_x = (g->player.x - g->ray.map_x) * g->ray.delta_dist_x; // g->ray.side_dist_x に (g->player.x - g->ray.map_x) * g->ray.delta_dist_x の計算結果を代入する
	} // ここでブロックスコープを終了する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
	{ // ここからブロックスコープを開始する
		g->ray.step_x = 1; // g->ray.step_x に 1 の計算結果を代入する
		g->ray.side_dist_x = (g->ray.map_x + 1.0 - g->player.x) // 式 `g->ray.side_dist_x = (g->ray.map_x + 1.0 - g->player.x)` を評価して処理を進める
			* g->ray.delta_dist_x; // 前行から続く式に演算を連結して計算を完成させる
	} // ここでブロックスコープを終了する
	if (g->ray.dir_y < 0) // g- > ray.dir_y < 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		g->ray.step_y = -1; // g->ray.step_y に -1 の計算結果を代入する
		g->ray.side_dist_y = (g->player.y - g->ray.map_y) * g->ray.delta_dist_y; // g->ray.side_dist_y に (g->player.y - g->ray.map_y) * g->ray.delta_dist_y の計算結果を代入する
	} // ここでブロックスコープを終了する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
	{ // ここからブロックスコープを開始する
		g->ray.step_y = 1; // g->ray.step_y に 1 の計算結果を代入する
		g->ray.side_dist_y = (g->ray.map_y + 1.0 - g->player.y) // 式 `g->ray.side_dist_y = (g->ray.map_y + 1.0 - g->player.y)` を評価して処理を進める
			* g->ray.delta_dist_y; // 前行から続く式に演算を連結して計算を完成させる
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する
