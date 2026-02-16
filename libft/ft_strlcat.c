/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:35:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:21:01 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strlcat - サイズ上限付きで文字列を連結する。引数(char *dst, const char *src, size_t size)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen()。 */
size_t	ft_strlcat(char *dst, const char *src, size_t size) // ft_strlcat関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	dstlen; // 変数 dstlen（dstlenの作業用値） を宣言する
	size_t	srclen; // 変数 srclen（srclenの作業用値） を宣言する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する

	dstlen = 0; // dstlen に 0 の計算結果を代入する
	srclen = ft_strlen(src); // srclen に ft_strlen(src) の計算結果を代入する
	i = 0; // i に 0 の計算結果を代入する
	while (dstlen < size && dst[dstlen]) // dstlen < size が成立する かつ 条件(dst[dstlen])が成立する場合に分岐する
		dstlen++; // 文 `dstlen++;` を実行する
	if (dstlen == size) // dstlen == size が成立する場合に分岐する
		return (size + srclen); // 関数を終了し、size + srclen を呼び出し元へ返す
	while (src[i] && (dstlen + i + 1) < size) // 条件(src[i])が成立する かつ (dstlen + i + 1) < size が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		dst[dstlen + i] = src[i]; // dst[dstlen + i] に src[i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	if ((dstlen + i) < size) // (dstlen + i) < size が成立する場合に分岐する
		dst[dstlen + i] = '\0'; // dst[dstlen + i] に '\0' の計算結果を代入する
	return (dstlen + srclen); // 関数を終了し、dstlen + srclen を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char s[] = "worlddd";
// 	char d[] = "Hello";
// 	ft_strlcat(d, s, 4);
// 	printf("%s\n", d);
// 	printf("%zu\n", ft_strlcat(d, s, 4));
// 	return (0);
// }