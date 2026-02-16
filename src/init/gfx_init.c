/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:58:27 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 19:02:56 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	init_gfx_screen(t_img *screen); // init_gfx_screen() の関数宣言。目的: 描画コンテキスト・screenを初期化する
static void	init_gfx_tex(t_img *tex); // init_gfx_tex() の関数宣言。目的: 描画コンテキスト・テクスチャを初期化する

/* 関数概要: init_gfx - 描画コンテキストを初期化する。引数(t_gfx *gfx)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: init_gfx_screen() -> init_gfx_tex()。 */
void	init_gfx(t_gfx *gfx) // init_gfx関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	gfx->mlx = NULL; // gfx->mlx に NULL の計算結果を代入する
	gfx->win = NULL; // gfx->win に NULL の計算結果を代入する
	gfx->win_w = 640; // gfx->win_w に 640 の計算結果を代入する
	gfx->win_h = 480; // gfx->win_h に 480 の計算結果を代入する
	init_gfx_screen(&gfx->screen); // init_gfx_screen() を呼び出して、描画コンテキスト・screenを初期化する
	init_gfx_tex(gfx->tex); // init_gfx_tex() を呼び出して、描画コンテキスト・テクスチャを初期化する
} // ここでブロックスコープを終了する

/* 関数概要: init_gfx_screen - 描画コンテキスト・screenを初期化する。引数(t_img *screen)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	init_gfx_screen(t_img *screen) // init_gfx_screen関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	screen->ptr = NULL; // screen->ptr に NULL の計算結果を代入する
	screen->addr = NULL; // screen->addr に NULL の計算結果を代入する
	screen->bpp = 0; // screen->bpp に 0 の計算結果を代入する
	screen->line_len = 0; // screen->line_len に 0 の計算結果を代入する
	screen->endian = 0; // screen->endian に 0 の計算結果を代入する
	screen->img_width = 0; // screen->img_width に 0 の計算結果を代入する
	screen->img_height = 0; // screen->img_height に 0 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: init_gfx_tex - 描画コンテキスト・テクスチャを初期化する。引数(t_img *tex)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	init_gfx_tex(t_img *tex) // init_gfx_tex関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	tex[TEX_NO].ptr = NULL; // tex[TEX_NO].ptr に NULL の計算結果を代入する
	tex[TEX_SO].ptr = NULL; // tex[TEX_SO].ptr に NULL の計算結果を代入する
	tex[TEX_WE].ptr = NULL; // tex[TEX_WE].ptr に NULL の計算結果を代入する
	tex[TEX_EA].ptr = NULL; // tex[TEX_EA].ptr に NULL の計算結果を代入する
} // ここでブロックスコープを終了する
