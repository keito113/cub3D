/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:38:05 by takawagu          #+#    #+#             */
/*   Updated: 2026/02/17 16:38:21 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // cub3Dの全体定義（構造体・プロトタイプ・定数など）

static void	setup_ray(t_game *g, int x); // 画面x列に対応するレイ情報を初期化する
static void	setup_step(t_game *g);       // DDA用にstep方向と最初のside距離を初期化する

/* 1フレーム分の描画：画面の各x列ごとにレイを飛ばし、壁の縦ストライプを描く */
void	raycast_frame(t_game *game)
{
	int x;                      // 画面のx座標（列番号）
	t_wall_slice slice;         // 1列分の描画に使う情報（draw_columnへ渡す）
	x = 0;                      // 左端の列から開始
	while (x < game->gfx.win_w) // 画面幅分だけ繰り返す
	{
		setup_ray(game, x);        // レイ方向・マップ座標・delta距離などを準備
		setup_step(game);          // DDAのstep方向とside距離（最初の境界まで）を準備
		dda(game);                 // DDAでグリッドを進めて壁に当たるまで探索
		calculate_wall(game);      // 壁までの距離、描画高さ、テクスチャ座標等を計算
		slice.screen_x = x;        // このストライプが描画される画面のx列を設定
		draw_column(game, &slice); // 1列分の壁（と床天井）を描画
		x++;                       // 次の列へ
	}
}

/* 画面x列の「カメラ空間座標」を計算し、プレイヤーの向き＋平面からレイ方向を作る */
static void	setup_ray(t_game *g, int x)
{
	g->ray.camera_x = 2.0 * x / (double)g->gfx.win_w - 1.0;
	//-1〜+1の範囲に正規化（左=-1,右=+1）
	g->ray.dir_x = g->player.dir_x + g->player.plane_x * g->ray.camera_x;
	// レイのX方向（視線＋平面成分）
	g->ray.dir_y = g->player.dir_y + g->player.plane_y * g->ray.camera_x;
	// レイのY方向（視線＋平面成分）
	g->ray.map_x = (int)g->player.x;
	// プレイヤーがいるマップセルX（整数化）
	g->ray.map_y = (int)g->player.y;
	// プレイヤーがいるマップセルY（整数化）
	if (g->ray.dir_x == 0)
		// dir_xが0だと1/dir_xで割れない（真上/真下方向など）
		g->ray.delta_dist_x = 1e30;
	// X方向のdeltaを擬似的に無限大にする
	else
		g->ray.delta_dist_x = fabs(1.0 / g->ray.dir_x); // X方向に「セル境界を1回またぐ」ための距離
	if (g->ray.dir_y == 0)
		// dir_yが0だと1/dir_yで割れない（真左/真右方向など）
		g->ray.delta_dist_y = 1e30; // Y方向のdeltaを擬似的に無限大にする
	else
		g->ray.delta_dist_y = fabs(1.0 / g->ray.dir_y); // Y方向に「セル境界を1回またぐ」ための距離
}

/* レイが進む方向（step: +1/-1）と、最初の格子線までの距離（side_dist）を決める */
static void	setup_step(t_game *g)
{
	if (g->ray.dir_x < 0) // レイがXマイナス方向（左）に進む場合
	{
		g->ray.step_x = -1;
		// DDAではmap_xを減らしながら進む
		g->ray.side_dist_x = (g->player.x - g->ray.map_x) * g->ray.delta_dist_x;
		// 左側の縦境界までの距離
	}
	else // レイがXプラス方向（右）に進む場合
	{
		g->ray.step_x = 1;
		// DDAではmap_xを増やしながら進む
		g->ray.side_dist_x = (g->ray.map_x + 1.0 - g->player.x)
			* g->ray.delta_dist_x; // 右側の縦境界までの距離
	}
	if (g->ray.dir_y < 0) // レイがYマイナス方向に進む場合（座標系次第で「上」など）
	{
		g->ray.step_y = -1;
		// DDAではmap_yを減らしながら進む
		g->ray.side_dist_y = (g->player.y - g->ray.map_y) * g->ray.delta_dist_y;
		// 手前側の横境界までの距離
	}
	else // レイがYプラス方向に進む場合
	{
		g->ray.step_y = 1;
		// DDAではmap_yを増やしながら進む
		g->ray.side_dist_y = (g->ray.map_y + 1.0 - g->player.y)
			* g->ray.delta_dist_y; // 奥側の横境界までの距離
	}
}
