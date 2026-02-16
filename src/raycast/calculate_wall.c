/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:40:05 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:58:11 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static double	calculate_perp_dist(t_game *game); // calculate_perp_dist() の関数宣言。目的: perp・distを計算する
static void		calculate_draw_range(t_game *game, double perp_dist); // calculate_draw_range() の関数宣言。目的: draw・rangeを計算する

/* 関数概要: calculate_wall - 壁を計算する。引数(t_game *game)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: calculate_perp_dist() -> calculate_draw_range()。 */
void	calculate_wall(t_game *game) // calculate_wall関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	double	perp_dist; // 変数 perp_dist（壁までの垂直距離） を宣言する

	perp_dist = calculate_perp_dist(game); // perp_dist に calculate_perp_dist(game) の計算結果を代入する
	game->ray.perp_wall_dist = perp_dist; // game->ray.perp_wall_dist に perp_dist の計算結果を代入する
	calculate_draw_range(game, perp_dist); // calculate_draw_range() を呼び出して、draw・rangeを計算する
} // ここでブロックスコープを終了する

/* 関数概要: calculate_perp_dist - perp・distを計算する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static double	calculate_perp_dist(t_game *game) // calculate_perp_dist関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (game->ray.side == HIT_X_SIDE) // game- > ray.side == HIT_X_SIDE が成立する場合に分岐する
		return ((game->ray.map_x - game->player.x + (1 - game->ray.step_x) // 関数を終了し、値 を呼び出し元へ返す
				/ 2.0) / game->ray.dir_x); // 文 `/ 2.0) / game->ray.dir_x);` を実行する
	return ((game->ray.map_y - game->player.y + (1 - game->ray.step_y) / 2.0) // 関数を終了し、値 を呼び出し元へ返す
		/ game->ray.dir_y); // 文 `/ game->ray.dir_y);` を実行する
} // ここでブロックスコープを終了する

/* 関数概要: calculate_draw_range - draw・rangeを計算する。引数(t_game *game, double perp_dist)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	calculate_draw_range(t_game *game, double perp_dist) // calculate_draw_range関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	wall_height; // 変数 wall_height（描画する壁の高さ） を宣言する
	int	draw_start; // 変数 draw_start（壁描画開始Y） を宣言する
	int	draw_end; // 変数 draw_end（壁描画終了Y） を宣言する

	wall_height = (int)(game->gfx.win_h / perp_dist); // wall_height に (int)(game->gfx.win_h / perp_dist) の計算結果を代入する
	draw_start = -wall_height / 2 + game->gfx.win_h / 2; // draw_start に -wall_height / 2 + game->gfx.win_h / 2 の計算結果を代入する
	if (draw_start < 0) // draw_start < 0 が成立する場合に分岐する
		draw_start = 0; // draw_start に 0 の計算結果を代入する
	draw_end = wall_height / 2 + game->gfx.win_h / 2; // draw_end に wall_height / 2 + game->gfx.win_h / 2 の計算結果を代入する
	if (draw_end >= game->gfx.win_h) // draw_end >= game->gfx.win_h が成立する場合に分岐する
		draw_end = game->gfx.win_h - 1; // draw_end に game->gfx.win_h - 1 の計算結果を代入する
	game->ray.wall_height = wall_height; // game->ray.wall_height に wall_height の計算結果を代入する
	game->ray.draw_start = draw_start; // game->ray.draw_start に draw_start の計算結果を代入する
	game->ray.draw_end = draw_end; // game->ray.draw_end に draw_end の計算結果を代入する
} // ここでブロックスコープを終了する
