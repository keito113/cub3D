/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:02:33 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/21 12:08:38 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: is_cub_file - 渡されたパスの末尾が .cub 拡張子かどうかを判定する。引数(const char *path)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> ft_strncmp()。 */
static int	is_cub_file(const char *path) // is_cub_file関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	len; // 変数 len（文字列長） を宣言する

	len = ft_strlen(path); // len に ft_strlen(path) の計算結果を代入する
	if (len < 5) // ファイル名長が最低5文字（a.cub）未満である場合に分岐する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	if (ft_strncmp(path + len - 4, ".cub", 4) != 0) // パス末尾4文字が ".cub" と一致しない場合に分岐する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: args_validate - 起動引数の個数、拡張子が .cub かどうか、対象ファイルを開けるかを検証する。引数(t_game *game, int argc, char **argv)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: fatal() -> is_cub_file() -> open() -> close()。 */
int	args_validate(t_game *game, int argc, char **argv) // args_validate関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	fd; // 変数 fd（ファイルディスクリプタ） を宣言する

	if (argc != 2) // 引数個数が2（実行ファイル名 + .cubパス）でない場合に分岐する
		return (fatal(game, ERR_USAGE, NULL)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	if (!is_cub_file(argv[1])) // is_cub_file()で渡されたパスの末尾が .cub 拡張子かどうかを判定した結果が偽（条件不成立）なら分岐する
		return (fatal(game, ERR_EXT, argv[1])); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	fd = open(argv[1], O_RDONLY); // fd に open(argv[1], O_RDONLY) の計算結果を代入する
	if (fd < 0) // open結果fdが負値でファイルを開けない場合に分岐する
		return (fatal(game, ERR_OPEN, argv[1])); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	close(fd); // fd をcloseしてファイルディスクリプタを解放する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
