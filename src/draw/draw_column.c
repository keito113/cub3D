/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:32:59 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 19:01:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	draw_ceiling(t_game *game, int x, int end_y); // draw_ceiling() の関数宣言。目的: ceilingを描画する
static void	draw_floor(t_game *game, int x, int start_y); // draw_floor() の関数宣言。目的: 床を描画する

/* 関数概要: draw_column - columnを描画する。引数(t_game *game, t_wall_slice *slice)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: draw_ceiling() -> setup_wall_slice() -> draw_wall() -> draw_floor()。 */
void	draw_column(t_game *game, t_wall_slice *slice) // draw_column関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	draw_ceiling(game, slice->screen_x, game->ray.draw_start); // draw_ceiling() を呼び出して、ceilingを描画する
	setup_wall_slice(game, slice); // setup_wall_slice() を呼び出して、壁・sliceを事前準備を行う
	slice->screen_y = game->ray.draw_start; // slice->screen_y に game->ray.draw_start の計算結果を代入する
	draw_wall(game, slice); // draw_wall() を呼び出して、壁を描画する
	draw_floor(game, slice->screen_x, game->ray.draw_end + 1); // draw_floor() を呼び出して、床を描画する
} // ここでブロックスコープを終了する

/* 関数概要: draw_ceiling - ceilingを描画する。引数(t_game *game, int x, int end_y)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: put_pixel()。 */
static void	draw_ceiling(t_game *game, int x, int end_y) // draw_ceiling関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	y; // 変数 y（Y座標） を宣言する

	y = 0; // y に 0 の計算結果を代入する
	while (y < end_y) // y < end_y が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		put_pixel(&game->gfx.screen, x, y, game->config.ceil_color); // put_pixel() を呼び出して、画像バッファの指定座標へ1ピクセル書き込む
		y++; // 文 `y++;` を実行する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: draw_floor - 床を描画する。引数(t_game *game, int x, int start_y)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: put_pixel()。 */
static void	draw_floor(t_game *game, int x, int start_y) // draw_floor関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	y; // 変数 y（Y座標） を宣言する

	y = start_y; // y に start_y の計算結果を代入する
	while (y < game->gfx.win_h) // y < game->gfx.win_h が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		put_pixel(&game->gfx.screen, x, y, game->config.floor_color); // put_pixel() を呼び出して、画像バッファの指定座標へ1ピクセル書き込む
		y++; // 文 `y++;` を実行する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する
