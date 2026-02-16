/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:09:01 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:11:26 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static int	parse_tex(t_config *config, int i, char *rest); // parse_tex() の関数宣言。目的: テクスチャを解析する
static int	tex_wrap(t_config *config, int idx, char *rest); // tex_wrap() の関数宣言。目的: テクスチャパスの重複設定を検出しつつparse_texへ処理を委譲する

/* 関数概要: handle_texture - テクスチャ識別子(NO/SO/WE/EA)に応じて対応パスを設定する。引数(char *key, int key_len, t_game *game, char *rest)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strncmp() -> tex_wrap()。 */
int	handle_texture(char *key, int key_len, t_game *game, char *rest) // handle_texture関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (key_len != 2) // key_len != 2 が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (ft_strncmp(key, "NO", 2) == 0) // ft_strncmp()が0（成功/継続条件）を返す場合に分岐する
		return (tex_wrap(&game->config, TEX_NO, rest)); // 関数を終了し、tex_wrap(&game->config, TEX_NO, rest) を呼び出し元へ返す
	if (ft_strncmp(key, "SO", 2) == 0) // ft_strncmp()が0（成功/継続条件）を返す場合に分岐する
		return (tex_wrap(&game->config, TEX_SO, rest)); // 関数を終了し、tex_wrap(&game->config, TEX_SO, rest) を呼び出し元へ返す
	if (ft_strncmp(key, "WE", 2) == 0) // ft_strncmp()が0（成功/継続条件）を返す場合に分岐する
		return (tex_wrap(&game->config, TEX_WE, rest)); // 関数を終了し、tex_wrap(&game->config, TEX_WE, rest) を呼び出し元へ返す
	if (ft_strncmp(key, "EA", 2) == 0) // ft_strncmp()が0（成功/継続条件）を返す場合に分岐する
		return (tex_wrap(&game->config, TEX_EA, rest)); // 関数を終了し、tex_wrap(&game->config, TEX_EA, rest) を呼び出し元へ返す
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: parse_tex - テクスチャを解析する。引数(t_config *config, int i, char *rest)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: skip_space() -> ft_strdup()。 */
static int	parse_tex(t_config *config, int i, char *rest) // parse_tex関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*path; // 変数 path（ファイルパス） を宣言する

	if (config->parsed.tex[i]) // config- > parsed.tex[i] が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	rest = skip_space(rest); // rest に skip_space(rest) の計算結果を代入する
	if (*rest == '\0') // *rest == '\0' が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	path = ft_strdup(rest); // path に ft_strdup(rest) の計算結果を代入する
	if (!path) // 条件(!path)が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	config->tex_path[i] = path; // config->tex_path[i] に path の計算結果を代入する
	config->parsed.tex[i] = 1; // config->parsed.tex[i] に 1 の計算結果を代入する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: tex_wrap - テクスチャパスの重複設定を検出しつつparse_texへ処理を委譲する。引数(t_config *config, int idx, char *rest)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: parse_tex()。 */
static int	tex_wrap(t_config *config, int idx, char *rest) // tex_wrap関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	err; // 変数 err（errの作業用値） を宣言する

	err = parse_tex(config, idx, rest); // err に parse_tex(config, idx, rest) の計算結果を代入する
	if (err != 0) // err != 0 が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
