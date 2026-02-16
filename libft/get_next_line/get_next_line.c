/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/02/10 15:14:58 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" // "get_next_line.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: strjoin_and_free - 文字列を連結して古いバッファを解放する。引数(char *stash, char *buf)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: gnl_ft_strdup() -> gnl_ft_strjoin() -> free()。 */
static char	*strjoin_and_free(char *stash, char *buf) // strjoin_and_free関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*joined; // 変数 joined（joinedの作業用値） を宣言する

	if (!stash) // 条件(!stash)が成立する場合に分岐する
		return (gnl_ft_strdup(buf)); // 関数を終了し、gnl_ft_strdup(buf) を呼び出し元へ返す
	joined = gnl_ft_strjoin(stash, buf); // joined に gnl_ft_strjoin(stash, buf) の計算結果を代入する
	free(stash); // free() を呼び出して、対象を解放する
	return (joined); // 関数を終了し、joined を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: extract_line - stash先頭から1行分を取り出す。引数(char *stash)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: gnl_ft_strchr() -> ft_strlen() -> malloc()。 */
char	*extract_line(char *stash) // extract_line関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*line; // 変数 line（1行分の文字列） を宣言する
	char	*newline_ptr; // 変数 newline_ptr（newline_ptrの作業用値） を宣言する
	size_t	line_len; // 変数 line_len（line_lenの作業用値） を宣言する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	newline_ptr = gnl_ft_strchr(stash, '\n'); // newline_ptr に gnl_ft_strchr(stash, '\n') の計算結果を代入する
	if (newline_ptr == NULL) // newline_ptr == NULL が成立する場合に分岐する
		line_len = ft_strlen(stash); // line_len に ft_strlen(stash) の計算結果を代入する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
		line_len = (size_t)(newline_ptr - stash + 1); // line_len に (size_t)(newline_ptr - stash + 1) の計算結果を代入する
	line = malloc(line_len + 1); // line に malloc(line_len + 1) の計算結果を代入する
	if (!line) // 条件(!line)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	while (i < line_len) // i < line_len が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		line[i] = stash[i]; // line[i] に stash[i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	line[i] = '\0'; // line[i] に '\0' の計算結果を代入する
	return (line); // 関数を終了し、line を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: update_stash - 読み出した行を除いた残りstashへ更新する。引数(char *stash)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: gnl_ft_strchr() -> free() -> ft_strlen() -> malloc()。 */
char	*update_stash(char *stash) // update_stash関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*newline_ptr; // 変数 newline_ptr（newline_ptrの作業用値） を宣言する
	char	*new_stash; // 変数 new_stash（new_stashの作業用値） を宣言する
	size_t	len; // 変数 len（文字列長） を宣言する

	if (!stash) // 条件(!stash)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	newline_ptr = gnl_ft_strchr(stash, '\n'); // newline_ptr に gnl_ft_strchr(stash, '\n') の計算結果を代入する
	if (!newline_ptr) // 条件(!newline_ptr)が成立する場合に分岐する
		return (free(stash), NULL); // 関数を終了し、free(stash), NULL を呼び出し元へ返す
	newline_ptr++; // 文 `newline_ptr++;` を実行する
	if (*newline_ptr == '\0') // *newline_ptr == '\0' が成立する場合に分岐する
		return (free(stash), NULL); // 関数を終了し、free(stash), NULL を呼び出し元へ返す
	len = ft_strlen(newline_ptr); // len に ft_strlen(newline_ptr) の計算結果を代入する
	new_stash = malloc(len + 1); // new_stash に malloc(len + 1) の計算結果を代入する
	if (!new_stash) // 条件(!new_stash)が成立する場合に分岐する
		return (free(stash), NULL); // 関数を終了し、free(stash), NULL を呼び出し元へ返す
	gnl_ft_memcpy(new_stash, newline_ptr, len); // gnl_ft_memcpy() を呼び出して、メモリ領域をコピーする
	new_stash[len] = '\0'; // new_stash[len] に '\0' の計算結果を代入する
	free(stash); // free() を呼び出して、対象を解放する
	return (new_stash); // 関数を終了し、new_stash を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: read_and_stash - 改行が出るまでfdから読み込みstashへ連結する。引数(int fd, char *stash)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: malloc() -> gnl_ft_strdup() -> free() -> gnl_ft_strchr()。 */
char	*read_and_stash(int fd, char *stash) // read_and_stash関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*buf; // 変数 buf（bufの作業用値） を宣言する
	ssize_t	bytes_read; // 変数 bytes_read（bytes_readの作業用値） を宣言する

	buf = malloc((size_t)BUFFER_SIZE + 1); // buf に malloc((size_t)BUFFER_SIZE + 1) の計算結果を代入する
	if (!buf) // 条件(!buf)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	if (!stash) // 条件(!stash)が成立する場合に分岐する
		stash = gnl_ft_strdup(""); // stash に gnl_ft_strdup("") の計算結果を代入する
	if (!stash) // 条件(!stash)が成立する場合に分岐する
		return (free(buf), NULL); // 関数を終了し、free(buf), NULL を呼び出し元へ返す
	while (stash && !gnl_ft_strchr(stash, '\n')) // 条件(stash)が成立する かつ gnl_ft_strchr()で文字列から指定文字の位置を検索した結果が偽（条件不成立）なら分岐する
	{ // ここからブロックスコープを開始する
		bytes_read = read(fd, buf, BUFFER_SIZE); // bytes_read に read(fd, buf, BUFFER_SIZE) の計算結果を代入する
		if (bytes_read < 0) // bytes_read < 0 が成立する場合に分岐する
			return (free(buf), free(stash), NULL); // 関数を終了し、free(buf), free(stash), NULL を呼び出し元へ返す
		if (bytes_read == 0) // bytes_read == 0 が成立する場合に分岐する
			break ; // 変数 break（breakの作業用値） を宣言する
		buf[bytes_read] = '\0'; // buf[bytes_read] に '\0' の計算結果を代入する
		stash = strjoin_and_free(stash, buf); // stash に strjoin_and_free(stash, buf) の計算結果を代入する
		if (!stash) // 条件(!stash)が成立する場合に分岐する
			return (free(buf), NULL); // 関数を終了し、free(buf), NULL を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	free(buf); // free() を呼び出して、対象を解放する
	return (stash); // 関数を終了し、stash を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: get_next_line - next・lineを取得する。引数(int fd)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: read_and_stash() -> free() -> extract_line() -> update_stash()。 */
char	*get_next_line(int fd) // get_next_line関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	static char	*stash; // 変数 stash（stashの作業用値） を宣言する
	char		*line; // 変数 line（1行分の文字列） を宣言する

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > __INT_MAX__) // open結果fdが負値でファイルを開けない または BUFFER_SIZE <= 0 が成立する または BUFFER_SIZE > __INT_MAX__ が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	stash = read_and_stash(fd, stash); // stash に read_and_stash(fd, stash) の計算結果を代入する
	if (!stash || stash[0] == '\0') // 条件(!stash)が成立する または stash[0] == '\0' が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		free(stash); // free() を呼び出して、対象を解放する
		stash = NULL; // stash に NULL の計算結果を代入する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	line = extract_line(stash); // line に extract_line(stash) の計算結果を代入する
	if (!line) // 条件(!line)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	stash = update_stash(stash); // stash に update_stash(stash) の計算結果を代入する
	return (line); // 関数を終了し、line を呼び出し元へ返す
} // ここでブロックスコープを終了する
