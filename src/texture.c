/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:29:42 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:54:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static int	load_one_tex(t_game *game, int i); // load_one_tex() の関数宣言。目的: one・テクスチャを読み込む

/* 関数概要: load_textures - texturesを読み込む。引数(t_game *game)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: load_one_tex()。 */
int	load_textures(t_game *game) // load_textures関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (i < TEX_MAX) // i < TEX_MAX が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (load_one_tex(game, i) != 0) // load_one_tex()が非0（失敗）を返す場合に分岐する
			return (1); // 関数を終了し、1 を呼び出し元へ返す
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: load_one_tex - one・テクスチャを読み込む。引数(t_game *game, int i)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: mlx_xpm_file_to_image() -> fatal() -> mlx_get_data_addr()。 */
static int	load_one_tex(t_game *game, int i) // load_one_tex関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	t_img	*tex; // 変数 tex（texの作業用値） を宣言する
	char	*path; // 変数 path（ファイルパス） を宣言する

	tex = &game->gfx.tex[i]; // tex に &game->gfx.tex[i] の計算結果を代入する
	path = game->config.tex_path[i]; // path に game->config.tex_path[i] の計算結果を代入する
	tex->ptr = mlx_xpm_file_to_image(game->gfx.mlx, path, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			&tex->img_width, &tex->img_height); // 変数 img_width（img_widthの作業用値） を宣言する
	if (!tex->ptr) // !tex- > ptr が成立する場合に分岐する
		return (fatal(game, ERR_IMG, path)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->line_len, // 関数呼び出し引数をこの行で追加し、次行へ続ける
			&tex->endian); // 文 `&tex->endian);` を実行する
	if (!tex->addr) // !tex- > addr が成立する場合に分岐する
		return (fatal(game, ERR_IMG, path)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
