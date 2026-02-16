/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:55:59 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/26 19:11:58 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: parse_config_line - 設定・lineを解析する。引数(t_game *game, char *line, int *in_map)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: skip_space() -> handle_texture() -> parse_floor_and_ceil()。 */
int	parse_config_line(t_game *game, char *line, int *in_map) // parse_config_line関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*key; // 変数 key（keyの作業用値） を宣言する
	char	*rest; // 変数 rest（restの作業用値） を宣言する
	int		key_len; // 変数 key_len（key_lenの作業用値） を宣言する
	int		res; // 変数 res（resの作業用値） を宣言する

	line = skip_space(line); // line に skip_space(line) の計算結果を代入する
	if (*line == '\0') // *line == '\0' が成立する場合に分岐する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	key = line; // key に line の計算結果を代入する
	while (*line && *line != ' ' && *line != '\t') // 条件(*line)が成立する かつ *line != ' ' が成立する かつ *line != '\t' が成立する場合に分岐する
		line++; // 文 `line++;` を実行する
	key_len = line - key; // key_len に line - key の計算結果を代入する
	rest = skip_space(line); // rest に skip_space(line) の計算結果を代入する
	res = handle_texture(key, key_len, game, rest); // res に handle_texture(key, key_len, game, rest) の計算結果を代入する
	if (res < 0) // res < 0 が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (res == 0) // res == 0 が成立する場合に分岐する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	res = parse_floor_and_ceil(game, key_len, *key, rest); // res に parse_floor_and_ceil(game, key_len, *key, rest) の計算結果を代入する
	if (res < 0) // res < 0 が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (res == 0) // res == 0 が成立する場合に分岐する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	*in_map = 1; // 前行から続く式に演算を連結して計算を完成させる
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
