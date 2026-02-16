/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:17:12 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/16 18:25:10 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: msg_of - エラーコードに対応する固定メッセージ文字列を返す。引数(t_errc c)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static const char	*msg_of(t_errc c) // msg_of関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (c == ERR_USAGE) // c == ERR_USAGE が成立する場合に分岐する
		return ("Usage: ./cub3D file.cub"); // 関数を終了し、"Usage: ./cub3D file.cub" を呼び出し元へ返す
	if (c == ERR_EXT) // c == ERR_EXT が成立する場合に分岐する
		return ("Invalid extension"); // 関数を終了し、"Invalid extension" を呼び出し元へ返す
	if (c == ERR_OPEN) // c == ERR_OPEN が成立する場合に分岐する
		return ("Cannot open file"); // 関数を終了し、"Cannot open file" を呼び出し元へ返す
	if (c == ERR_PARSE) // c == ERR_PARSE が成立する場合に分岐する
		return ("Parse error"); // 関数を終了し、"Parse error" を呼び出し元へ返す
	if (c == ERR_MAP) // c == ERR_MAP が成立する場合に分岐する
		return ("Map error"); // 関数を終了し、"Map error" を呼び出し元へ返す
	if (c == ERR_MLX) // c == ERR_MLX が成立する場合に分岐する
		return ("MLX init failed"); // 関数を終了し、"MLX init failed" を呼び出し元へ返す
	if (c == ERR_IMG) // c == ERR_IMG が成立する場合に分岐する
		return ("Texture load failed"); // 関数を終了し、"Texture load failed" を呼び出し元へ返す
	if (c == ERR_ALLOC) // c == ERR_ALLOC が成立する場合に分岐する
		return ("Memory allocation failed"); // 関数を終了し、"Memory allocation failed" を呼び出し元へ返す
	return ("Fatal error"); // 関数を終了し、"Fatal error" を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: fatal - エラー内容を出力して失敗コードを返す。引数(t_game *game, t_errc code, const char *detail)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: msg_of() -> write() -> ft_strlen() -> game_destroy()。 */
int	fatal(t_game *game, t_errc code, const char *detail) // fatal関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	const char	*msg; // 変数 msg（エラーメッセージ文字列） を宣言する

	msg = msg_of(code); // msg に msg_of(code) の計算結果を代入する
	write(2, "Error\n", 6); // write() を呼び出して、writeを実行する
	write(2, msg, ft_strlen(msg)); // write() を呼び出して、writeを実行する
	if (detail) // 条件(detail)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		write(2, ": ", 2); // write() を呼び出して、writeを実行する
		write(2, detail, ft_strlen(detail)); // write() を呼び出して、writeを実行する
	} // ここでブロックスコープを終了する
	write(2, "\n", 1); // write() を呼び出して、writeを実行する
	game_destroy(game); // game_destroy() を呼び出して、確保済み画像・ウィンドウ・マップ・設定メモリを解放する
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する
