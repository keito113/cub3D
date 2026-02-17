/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_and_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:52:26 by takawagu          #+#    #+#             */
/*   Updated: 2026/02/16 16:54:35 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // cub3d.h を読み込み（t_gameやconfig構造体、libft関数宣言などを使えるようにする）

static int	parse_color_channel(const char *str, int *out);
// "0"〜"255"の数値文字列を解析して out に入れる関数（内部用）
static int	parse_color(int *out, char *s);
// "R,G,B" 形式を解析して 0xRRGGBB を out に入れる関数（内部用）

/*
 * parse_floor_and_ceil
 *  - .cub の "F ..."（床）または "C ..."（天井）を解析して config に保存する
 * 戻り値:
 *  - 0  : 成功（この行を処理した）
 *  - -1 : エラー（重複 or 色の形式が不正）
 *  - 1  : この関数の担当外（key_len不一致、F/C以外など）
 */
int	parse_floor_and_ceil(t_game *game, int key_len, char key, char *rest)
// rest は "220,100,0" のような色部分
{
	if (key_len != 1) // キーが1文字（F/C）でないなら担当外
		return (1);   // 上位の解析へ回す（この関数では処理しない）

	if (key == 'F') // 床色（Floor）の指定行なら
	{
		if (game->config.parsed.floor) // 既に床色が設定済みなら（重複）
			return (-1);
		// エラー（同じ要素の複数指定を禁止したい）
		if (parse_color(&game->config.floor_color, rest)) // "R,G,B" を解析（失敗なら非0）
			return (-1);                                  // エラー（形式不正、範囲外など）
		game->config.parsed.floor = 1;                    // 「床色を読み取った」フラグを立てる
		return (0);                                       // 成功
	}

	if (key == 'C') // 天井色（Ceiling）の指定行なら
	{
		if (game->config.parsed.ceil)                    // 既に天井色が設定済みなら（重複）
			return (-1);                                 // エラー
		if (parse_color(&game->config.ceil_color, rest)) // "R,G,B" を解析（失敗なら非0）
			return (-1);                                 // エラー
		game->config.parsed.ceil = 1;                    // 「天井色を読み取った」フラグを立てる
		return (0);                                      // 成功
	}

	return (1); // F/C以外は担当外
}

/*
 * parse_color_channel
 *  - str が "0"〜"255" の10進数字だけで構成されていることを確認し、数値化して out に入れる
 *  - 数字以外が混ざる / 空文字 / 範囲外ならエラー
 */
static int	parse_color_channel(const char *str, int *out) // out に 0〜255 を格納したい
{
	long n; // 途中計算用（intより安全に大きめで受ける）

	if (!*str)      // 先頭が '\0' なら空文字 → NG
		return (1); // 失敗

	n = 0;       // 数値を0から組み立てる
	while (*str) // 文字列の終端まで1文字ずつ見る
	{
		if (!ft_isdigit(*str))     // 数字('0'〜'9')以外が来たら
			return (1);            // 失敗（例: 空白、符号、文字などはNG）
		n = n * 10 + (*str - '0'); // 10進数として桁を追加（例: "25" → 2→25）
		if (n < 0 || 255 < n)      // RGBは0〜255に限定
			return (1);            // 範囲外なら失敗（例: 256）
		str++;                     // 次の文字へ進む
	}
	*out = (int)n; // long から int に詰める（範囲チェック済みなので安全）
	return (0);    // 成功
}

/*
 * parse_color
 *  - "R,G,B" を解析して 0xRRGGBB 形式のintに変換する
 *  - 要素数が3つちょうどであること、各要素が 0〜255 の数字だけであることを保証する
 */
static int	parse_color(int *color, char *str) // color に 0xRRGGBB を格納する
{
	char **vec; // "R","G","B" に分解した配列
	int r;      // 赤成分（0〜255）
	int g;      // 緑成分（0〜255）
	int b;      // 青成分（0〜255）

	vec = ft_split(str, ',');
	// ',' で分割（例: "220,100,0" → ["220","100","0",NULL]）
	if (!vec || !vec[0] || !vec[1] || !vec[2] || vec[3])
	// 失敗 or 要素が3つでない（多すぎ/少なすぎ）
	{
		free_split(vec); // vec が NULL でも安全に解放できる実装を想定
		return (1);      // 失敗
	}

	if (parse_color_channel(vec[0], &r)     // Rを0〜255として解析（失敗なら非0）
		|| parse_color_channel(vec[1], &g)  // Gを解析
		|| parse_color_channel(vec[2], &b)) // Bを解析
	{
		free_split(vec); // splitした配列を解放
		return (1);      // 失敗
	}

	free_split(vec); // ここまで来たら vec は不要なので解放

	*color = (r << 16) | (g << 8) | b; // 0xRRGGBB に詰める（Rを上位、G中位、B下位）
	return (0);                        // 成功
}
