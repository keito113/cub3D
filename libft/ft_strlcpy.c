/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:46:18 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:20:09 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strlcpy - サイズ上限付きで文字列をコピーする。引数(char *dst, const char *src, size_t size)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size) // ft_strlcpy関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	src_len; // 変数 src_len（src_lenの作業用値） を宣言する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	src_len = 0; // src_len に 0 の計算結果を代入する
	while (src[src_len]) // 条件(src[src_len])が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		src_len++; // 文 `src_len++;` を実行する
	} // ここでブロックスコープを終了する
	if (size != 0) // size != 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		while (i < size - 1 && src[i]) // i < size - 1 が成立する かつ 条件(src[i])が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			dst[i] = src[i]; // dst[i] に src[i] の計算結果を代入する
			i++; // 文 `i++;` を実行する
		} // ここでブロックスコープを終了する
		dst[i] = '\0'; // dst[i] に '\0' の計算結果を代入する
	} // ここでブロックスコープを終了する
	return (src_len); // 関数を終了し、src_len を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char s[] = "Hello,world";
// 	char d[12];

// 	ft_strlcpy(d, s, 12);
// 	printf("%s\n", d);
// 	return (0);
// }