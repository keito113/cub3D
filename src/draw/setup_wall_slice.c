/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_wall_slice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:15:03 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:58:46 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	setup_tex(t_game *game, t_wall_slice *slice); // setup_tex() の関数宣言。目的: テクスチャを事前準備を行う
static void	setup_tex_x(t_game *game, t_wall_slice *slice); // setup_tex_x() の関数宣言。目的: テクスチャ・xを事前準備を行う
static void	setup_tex_step(t_game *game, t_wall_slice *slice); // setup_tex_step() の関数宣言。目的: テクスチャ・stepを事前準備を行う
static int	select_tex(t_game *game); // select_tex() の関数宣言。目的: 壁の向きとヒット面に応じて使用するテクスチャIDを選択する

/* 関数概要: setup_wall_slice - 壁・sliceを事前準備を行う。引数(t_game *game, t_wall_slice *slice)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: setup_tex() -> setup_tex_x() -> setup_tex_step()。 */
void	setup_wall_slice(t_game *game, t_wall_slice *slice) // setup_wall_slice関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	setup_tex(game, slice); // setup_tex() を呼び出して、テクスチャを事前準備を行う
	setup_tex_x(game, slice); // setup_tex_x() を呼び出して、テクスチャ・xを事前準備を行う
	setup_tex_step(game, slice); // setup_tex_step() を呼び出して、テクスチャ・stepを事前準備を行う
} // ここでブロックスコープを終了する

/* 関数概要: setup_tex - テクスチャを事前準備を行う。引数(t_game *game, t_wall_slice *slice)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: select_tex()。 */
static void	setup_tex(t_game *game, t_wall_slice *slice) // setup_tex関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	tex_id; // 変数 tex_id（使用テクスチャID） を宣言する

	tex_id = select_tex(game); // tex_id に select_tex(game) の計算結果を代入する
	slice->tex = &game->gfx.tex[tex_id]; // slice->tex に &game->gfx.tex[tex_id] の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: setup_tex_x - テクスチャ・xを事前準備を行う。引数(t_game *game, t_wall_slice *slice)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: floor()。 */
static void	setup_tex_x(t_game *game, t_wall_slice *slice) // setup_tex_x関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (game->ray.side == 0) // game- > ray.side == 0 が成立する場合に分岐する
		slice->wall_hit = game->player.y + game->ray.perp_wall_dist // 式 `slice->wall_hit = game->player.y + game->ray.perp_wall_dist` を評価して処理を進める
			* game->ray.dir_y; // 前行から続く式に演算を連結して計算を完成させる
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
		slice->wall_hit = game->player.x + game->ray.perp_wall_dist // 式 `slice->wall_hit = game->player.x + game->ray.perp_wall_dist` を評価して処理を進める
			* game->ray.dir_x; // 前行から続く式に演算を連結して計算を完成させる
	slice->wall_hit = 1.0 - (slice->wall_hit - floor(slice->wall_hit)); // slice->wall_hit に 1.0 - (slice->wall_hit - floor(slice->wall_hit)) の計算結果を代入する
	slice->tex_x = (int)(slice->wall_hit * (double)slice->tex->img_width); // slice->tex_x に (int)(slice->wall_hit * (double)slice->tex->img_width) の計算結果を代入する
	if (game->ray.side == 0 && game->ray.dir_x > 0) // game- > ray.side == 0 が成立する かつ game- > ray.dir_x > 0 が成立する場合に分岐する
		slice->tex_x = slice->tex->img_width - slice->tex_x - 1; // slice->tex_x に slice->tex->img_width - slice->tex_x - 1 の計算結果を代入する
	if (game->ray.side == 1 && game->ray.dir_y < 0) // game- > ray.side == 1 が成立する かつ game- > ray.dir_y < 0 が成立する場合に分岐する
		slice->tex_x = slice->tex->img_width - slice->tex_x - 1; // slice->tex_x に slice->tex->img_width - slice->tex_x - 1 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: setup_tex_step - テクスチャ・stepを事前準備を行う。引数(t_game *game, t_wall_slice *slice)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	setup_tex_step(t_game *game, t_wall_slice *slice) // setup_tex_step関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	slice->tex_step = 1.0 * slice->tex->img_height / game->ray.wall_height; // slice->tex_step に 1.0 * slice->tex->img_height / game->ray.wall_height の計算結果を代入する
	slice->tex_y_pos = (game->ray.draw_start - game->gfx.win_h / 2 // 式 `slice->tex_y_pos = (game->ray.draw_start - game->gfx.win_h / 2` を評価して処理を進める
			+ game->ray.wall_height / 2) * slice->tex_step; // 変数 tex_step（tex_stepの作業用値） を宣言する
} // ここでブロックスコープを終了する

/* 関数概要: select_tex - 壁の向きとヒット面に応じて使用するテクスチャIDを選択する。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static int	select_tex(t_game *game) // select_tex関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (game->ray.side == 0) // game- > ray.side == 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (game->ray.dir_x > 0) // game- > ray.dir_x > 0 が成立する場合に分岐する
			return (TEX_WE); // 関数を終了し、TEX_WE を呼び出し元へ返す
		return (TEX_EA); // 関数を終了し、TEX_EA を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
	{ // ここからブロックスコープを開始する
		if (game->ray.dir_y > 0) // game- > ray.dir_y > 0 が成立する場合に分岐する
			return (TEX_NO); // 関数を終了し、TEX_NO を呼び出し元へ返す
		return (TEX_SO); // 関数を終了し、TEX_SO を呼び出し元へ返す
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する
