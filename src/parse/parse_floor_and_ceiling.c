/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_and_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:52:26 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:17:45 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static int	parse_color_channel(const char *str, int *out); // parse_color_channel() の関数宣言。目的: color・channelを解析する
static int	parse_color(int *out, char *s); // parse_color() の関数宣言。目的: colorを解析する

/* 関数概要: parse_floor_and_ceil - 床・and・天井を解析する。引数(t_game *game, int key_len, char key, char *rest)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: parse_color()。 */
int	parse_floor_and_ceil(t_game *game, int key_len, char key, char *rest) // parse_floor_and_ceil関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (key_len != 1) // key_len != 1 が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	if (key == 'F') // key == 'F' が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (game->config.parsed.floor) // game- > config.parsed.floor が成立する場合に分岐する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		if (parse_color(&game->config.floor_color, rest)) // parse_color()でcolorを解析し、その戻り値が非0（真）なら分岐する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		game->config.parsed.floor = 1; // game->config.parsed.floor に 1 の計算結果を代入する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	if (key == 'C') // key == 'C' が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (game->config.parsed.ceil) // game- > config.parsed.ceil が成立する場合に分岐する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		if (parse_color(&game->config.ceil_color, rest)) // parse_color()でcolorを解析し、その戻り値が非0（真）なら分岐する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		game->config.parsed.ceil = 1; // game->config.parsed.ceil に 1 の計算結果を代入する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: parse_color_channel - color・channelを解析する。引数(const char *str, int *out)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_isdigit()。 */
static int	parse_color_channel(const char *str, int *out) // parse_color_channel関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	long	n; // 変数 n（nの作業用値） を宣言する

	if (!*str) // 条件(!*str)が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	n = 0; // n に 0 の計算結果を代入する
	while (*str) // 条件(*str)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (!ft_isdigit(*str)) // ft_isdigit()で数字か判定した結果が偽（条件不成立）なら分岐する
			return (1); // 関数を終了し、1 を呼び出し元へ返す
		n = n * 10 + (*str - '0'); // n に n * 10 + (*str - '0') の計算結果を代入する
		if (n < 0 || 255 < n) // n < 0 が成立する または 255 < n が成立する場合に分岐する
			return (1); // 関数を終了し、1 を呼び出し元へ返す
		str++; // 文 `str++;` を実行する
	} // ここでブロックスコープを終了する
	*out = (int)n; // 前行から続く式に演算を連結して計算を完成させる
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: parse_color - colorを解析する。引数(int *color, char *str)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_split() -> free_split() -> parse_color_channel()。 */
static int	parse_color(int *color, char *str) // parse_color関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	**vec; // 変数 vec（vecの作業用値） を宣言する
	int		r; // 変数 r（赤成分） を宣言する
	int		g; // 変数 g（緑成分） を宣言する
	int		b; // 変数 b（青成分） を宣言する

	vec = ft_split(str, ','); // vec に ft_split(str, ',') の計算結果を代入する
	if (!vec || !vec[0] || !vec[1] || !vec[2] || vec[3]) // 条件(!vec)が成立する または 条件(!vec[0])が成立する または 条件(!vec[1])が成立する または 条件(!vec[2])が成立する または 条件(vec[3])が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		free_split(vec); // free_split() を呼び出して、splitを解放する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	if (parse_color_channel(vec[0], &r) || parse_color_channel(vec[1], &g) // parse_color_channel()でcolor・channelを解析した戻り値が真（非0）である または 条件(parse_color_channel(vec[1], &g)が成立する場合に分岐する
		|| parse_color_channel(vec[2], &b)) // 前行の条件式へ OR 条件を追加する
	{ // ここからブロックスコープを開始する
		free_split(vec); // free_split() を呼び出して、splitを解放する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	free_split(vec); // free_split() を呼び出して、splitを解放する
	*color = (r << 16) | (g << 8) | b; // 前行から続く式に演算を連結して計算を完成させる
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
