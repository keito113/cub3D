/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:07:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 18:43:29 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	draw_wall_slice(t_game *game, t_wall_slice *slice); // draw_wall_slice() の関数宣言。目的: 壁・sliceを描画する
static int	get_tex_pixel(t_img *tex, int x, int y); // get_tex_pixel() の関数宣言。目的: テクスチャ・pixelを取得する

/* 関数概要: draw_wall - 壁を描画する。引数(t_game *game, t_wall_slice *slice)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: draw_wall_slice()。 */
void	draw_wall(t_game *game, t_wall_slice *slice) // draw_wall関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	while (slice->screen_y <= game->ray.draw_end) // slice- > screen_y <= game->ray.draw_end が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		draw_wall_slice(game, slice); // draw_wall_slice() を呼び出して、壁・sliceを描画する
		slice->screen_y++; // 文 `slice->screen_y++;` を実行する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: draw_wall_slice - 壁・sliceを描画する。引数(t_game *game, t_wall_slice *slice)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: get_tex_pixel() -> put_pixel()。 */
static void	draw_wall_slice(t_game *game, t_wall_slice *slice) // draw_wall_slice関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		tex_y; // 変数 tex_y（テクスチャY座標） を宣言する
	int		color; // 変数 color（描画色） を宣言する

	tex_y = (int)(slice->tex_y_pos); // tex_y に (int)(slice->tex_y_pos) の計算結果を代入する
	if (tex_y < 0) // tex_y < 0 が成立する場合に分岐する
		tex_y = 0; // tex_y に 0 の計算結果を代入する
	if (tex_y >= slice->tex->img_height) // tex_y >= slice->tex->img_height が成立する場合に分岐する
		tex_y = slice->tex->img_height - 1; // tex_y に slice->tex->img_height - 1 の計算結果を代入する
	slice->tex_y_pos += slice->tex_step; // slice->tex_y_pos を += で更新し、slice->tex_step を反映する
	color = get_tex_pixel(slice->tex, slice->tex_x, tex_y); // color に get_tex_pixel(slice->tex, slice->tex_x, tex_y) の計算結果を代入する
	put_pixel(&game->gfx.screen, slice->screen_x, slice->screen_y, color); // put_pixel() を呼び出して、画像バッファの指定座標へ1ピクセル書き込む
} // ここでブロックスコープを終了する

/* 関数概要: get_tex_pixel - テクスチャ・pixelを取得する。引数(t_img *tex, int x, int y)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static int	get_tex_pixel(t_img *tex, int x, int y) // get_tex_pixel関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*dst; // 変数 dst（ピクセル書き込み先アドレス） を宣言する

	if (x < 0 || y < 0 || x >= tex->img_width || y >= tex->img_height) // x < 0 が成立する または y < 0 が成立する または x >= tex->img_width が成立する または y >= tex->img_height が成立する場合に分岐する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8)); // dst に tex->addr + (y * tex->line_len + x * (tex->bpp / 8)) の計算結果を代入する
	return (*(unsigned int *)dst); // 関数を終了し、*(unsigned int *)dst を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: put_pixel - 画像バッファの指定座標へ1ピクセル書き込む。引数(t_img *img, int x, int y, int color)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	put_pixel(t_img *img, int x, int y, int color) // put_pixel関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*dst; // 変数 dst（ピクセル書き込み先アドレス） を宣言する

	if (x < 0 || y < 0 || x >= img->img_width || y >= img->img_height) // x < 0 が成立する または y < 0 が成立する または x >= img->img_width が成立する または y >= img->img_height が成立する場合に分岐する
		return ; // この時点で関数を終了して呼び出し元へ戻る
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8)); // dst に img->addr + (y * img->line_len + x * (img->bpp / 8)) の計算結果を代入する
	*(unsigned int *)dst = (unsigned int)color; // 式の計算結果を変数または構造体メンバへ代入して状態を更新する
} // ここでブロックスコープを終了する
