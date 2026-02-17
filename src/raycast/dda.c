/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/02/17 10:09:47 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // cub3Dの全体定義（構造体・プロトタイプ等）

static void	dda_step(t_game *game);                        
		// DDAの「1ステップ」分だけマップ座標を進める
static int	is_hit_cell(t_game *game, int map_x, int map_y); // 壁セルかどうか判定する

/* DDA本体：レイが壁セルに当たるまで、マス目を1つずつ進め続ける */
void	dda(t_game *game)
{
	game->ray.hit = 0;         // まだ壁に当たっていない状態に初期化
	while (game->ray.hit == 0) // 壁に当たるまで繰り返す
	{
		dda_step(game);
		// 次に近い境界へ進めて、map_x / map_y を更新
		if (is_hit_cell(game, game->ray.map_x, game->ray.map_y)) // 今いるセルが壁か確認
			game->ray.hit = 1;
		// 壁ならヒット確定してループ終了へ
	}
}

/* DDAの1ステップ：次に近い「縦境界 or 横境界」を選び、マップセルを1つ進める */
static void	dda_step(t_game *game)
{
	if (game->ray.side_dist_x < game->ray.side_dist_y) // 次に近いのが縦線（x境界）の場合
	{
		game->ray.side_dist_x += game->ray.delta_dist_x; // 次の縦線までの距離ぶん増やす
		game->ray.map_x += game->ray.step_x;             // x方向に1マス進める（+1 or -1）
		game->ray.side = 0;                              // 0: 縦壁（x側の境界）に当たった側
	}
	else // 次に近いのが横線（y境界）の場合（同距離もここに入る）
	{
		game->ray.side_dist_y += game->ray.delta_dist_y; // 次の横線までの距離ぶん増やす
		game->ray.map_y += game->ray.step_y;             // y方向に1マス進める（+1 or -1）
		game->ray.side = 1;                              // 1: 横壁（y側の境界）に当たった側
	}
}

/* 指定セルが「当たり判定あり（壁扱い）」かどうかを返す（範囲外も壁扱い） */
static int	is_hit_cell(t_game *game, int map_x, int map_y)
{
	char cell;                                             
		// マップ文字（'1' など）を取り出すための変数
	if (map_y < 0 || map_y >= game->map.height || map_x < 0 // マップの外に出たら
		|| map_x >= game->map.width)
		// 範囲外はクラッシュ防止のため壁扱いにする
		return (1);
	// 「当たり」として返す（= これ以上進まない）
	cell = game->map.grid[map_y][map_x]; // マップから現在セルの文字を取得
	return (cell == '1' || cell == ' ');
	// '1'（壁）または' '（空白/無効領域）を壁扱い
}
