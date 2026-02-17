/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:40:05 by takawagu          #+#    #+#             */
/*   Updated: 2026/02/17 10:10:30 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // cub3D全体の定義（t_game, ray構造体, 定数など）

static double	calculate_perp_dist(t_game *game);                 
		// 壁までの「垂直距離」を計算する
static void	calculate_draw_range(t_game *game, double perp_dist); // 描画範囲を計算する

/* DDAで壁ヒットが確定した後、壁までの距離と画面上の描画範囲（開始/終了）を決める */
void	calculate_wall(t_game *game)
{
	double perp_dist; // カメラ平面に対して垂直な壁距離（魚眼補正済み）
	perp_dist = calculate_perp_dist(game); // どの面に当たったか(side)に応じて距離を算出
	game->ray.perp_wall_dist = perp_dist;  // 後工程（テクスチャ計算/描画）で使うので保存
	calculate_draw_range(game, perp_dist); // 距離から壁の高さと描画開始/終了Yを計算
}

/* 壁までの距離を「視線に沿った距離」ではなく「スクリーンに垂直な距離」で求める（魚眼防止） */
static double	calculate_perp_dist(t_game *game)
{
	if (game->ray.side == HIT_X_SIDE)                                                                
		// 縦壁（x側の境界）に当たった場合
		return ((game->ray.map_x - game->player.x + (1 - game->ray.step_x)
				/ 2.0) / game->ray.dir_x); // x方向の壁交点までをdir_xで割って距離(t)にする
	return ((game->ray.map_y - game->player.y + (1 - game->ray.step_y) / 2.0)
		/ game->ray.dir_y);     // 横壁（y側）に当たった場合も同様にyで計算
}

/* 距離(perp_dist)から、壁の縦線の高さと、画面内での描画開始/終了位置を計算して保存する */
static void	calculate_draw_range(t_game *game, double perp_dist)
{
	int wall_height; // 画面上に描く壁の高さ（ピクセル）
	int draw_start;  // 描画開始Y（上端）
	int draw_end;    // 描画終了Y（下端）

	wall_height = (int)(game->gfx.win_h / perp_dist);    // 距離が近いほど高く、遠いほど低くなる
	draw_start = -wall_height / 2 + game->gfx.win_h / 2; // 画面中央を基準に上端を決める
	if (draw_start < 0)                                  // 画面の上にはみ出す場合
		draw_start = 0;                                  // 上端に丸める（クランプ）
	draw_end = wall_height / 2 + game->gfx.win_h / 2;    // 画面中央を基準に下端を決める
	if (draw_end >= game->gfx.win_h)                     // 画面の下にはみ出す場合
		draw_end = game->gfx.win_h - 1;                  // 下端に丸める（クランプ）
	game->ray.wall_height = wall_height;                 // 後で壁描画に使うので保存
	game->ray.draw_start = draw_start;                   // 描画開始ラインを保存
	game->ray.draw_end = draw_end;                       // 描画終了ラインを保存
}
