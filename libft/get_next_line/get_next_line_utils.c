/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:37:47 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/31 15:13:16 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" // "get_next_line.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
#include <stdlib.h> // <stdlib.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: gnl_ft_strchr - 文字列から指定文字の位置を検索する。引数(const char *s, int c)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
char	*gnl_ft_strchr(const char *s, int c) // gnl_ft_strchr関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (s[i]) // 条件(s[i])が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (s[i] == (char)c) // s[i] == (char)c が成立する場合に分岐する
			return ((char *)(s + i)); // 関数を終了し、(char *)(s + i) を呼び出し元へ返す
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	if ((char)c == '\0') // (char)c == '\0' が成立する場合に分岐する
		return ((char *)(s + i)); // 関数を終了し、(char *)(s + i) を呼び出し元へ返す
	return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: gnl_ft_strdup - 文字列を複製する。引数(const char *s)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> malloc()。 */
char	*gnl_ft_strdup(const char *s) // gnl_ft_strdup関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	len; // 変数 len（文字列長） を宣言する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する
	char	*copy; // 変数 copy（copyの作業用値） を宣言する

	len = ft_strlen(s); // len に ft_strlen(s) の計算結果を代入する
	copy = malloc(len + 1); // copy に malloc(len + 1) の計算結果を代入する
	if (copy == NULL) // copy == NULL が成立する場合に分岐する
		return ((NULL)); // 関数を終了し、(NULL) を呼び出し元へ返す
	i = 0; // i に 0 の計算結果を代入する
	while (i < len) // i < len が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		copy[i] = s[i]; // copy[i] に s[i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	copy[i] = '\0'; // copy[i] に '\0' の計算結果を代入する
	return (copy); // 関数を終了し、copy を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: gnl_ft_strjoin - 2つの文字列を連結する。引数(char const *s1, char const *s2)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: malloc() -> ft_strlen()。 */
char	*gnl_ft_strjoin(char const *s1, char const *s2) // gnl_ft_strjoin関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*res; // 変数 res（resの作業用値） を宣言する
	char	*tmp; // 変数 tmp（tmpの作業用値） を宣言する

	if (!s1 || !s2) // 条件(!s1)が成立する または 条件(!s2)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	res = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1); // res に malloc((ft_strlen(s1) + ft_strlen(s2)) + 1) の計算結果を代入する
	if (!res) // 条件(!res)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	tmp = res; // tmp に res の計算結果を代入する
	while (*s1) // 条件(*s1)が成立する場合に分岐する
		*tmp++ = *s1++; // 前行から続く式に演算を連結して計算を完成させる
	while (*s2) // 条件(*s2)が成立する場合に分岐する
		*tmp++ = *s2++; // 前行から続く式に演算を連結して計算を完成させる
	*tmp = '\0'; // 前行から続く式に演算を連結して計算を完成させる
	return (res); // 関数を終了し、res を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: gnl_ft_memcpy - メモリ領域をコピーする。引数(void *dst, const void *src, size_t n)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	*gnl_ft_memcpy(void *dst, const void *src, size_t n) // gnl_ft_memcpy関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	unsigned char		*d; // 変数 d（dの作業用値） を宣言する
	const unsigned char	*s; // 変数 s（sの作業用値） を宣言する
	size_t				i; // 変数 i（ループ用インデックス） を宣言する

	if ((dst == NULL && src == NULL) || n == 0) // (dst == NULL が成立する かつ src == NULL) が成立する または n == 0 が成立する場合に分岐する
		return (dst); // 関数を終了し、dst を呼び出し元へ返す
	d = (unsigned char *)dst; // d に (unsigned char *)dst の計算結果を代入する
	s = (const unsigned char *)src; // s に (const unsigned char *)src の計算結果を代入する
	i = 0; // i に 0 の計算結果を代入する
	while (i < n) // i < n が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		d[i] = s[i]; // d[i] に s[i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (dst); // 関数を終了し、dst を呼び出し元へ返す
} // ここでブロックスコープを終了する
