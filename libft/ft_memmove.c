/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:26:31 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:23:07 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_memmove - 重なりを考慮してメモリ領域を移動コピーする。引数(void *dst, const void *src, size_t len)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	*ft_memmove(void *dst, const void *src, size_t len) // ft_memmove関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char		*d; // 変数 d（dの作業用値） を宣言する
	const char	*s; // 変数 s（sの作業用値） を宣言する
	size_t		i; // 変数 i（ループ用インデックス） を宣言する

	d = dst; // d に dst の計算結果を代入する
	s = src; // s に src の計算結果を代入する
	if (d == s || len == 0) // d == s が成立する または len == 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		return (d); // 関数を終了し、d を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	else if (d < s) // d < s が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		i = 0; // i に 0 の計算結果を代入する
		while (i < len) // i < len が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			d[i] = s[i]; // d[i] に s[i] の計算結果を代入する
			i++; // 文 `i++;` を実行する
		} // ここでブロックスコープを終了する
	} // ここでブロックスコープを終了する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
	{ // ここからブロックスコープを開始する
		while (len--) // 条件(len--)が成立する場合に分岐する
			d[len] = s[len]; // d[len] に s[len] の計算結果を代入する
	} // ここでブロックスコープを終了する
	return (dst); // 関数を終了し、dst を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[] = "hello world!";
// 	char	s2[] = "hello world!";

// 	ft_memmove(s1 + 6, s1, 5);
// 	memmove(s2 + 6, s2, 5);
// 	printf("ft_memmove overlap result : %s\n", s1);
// 	printf("   memmove overlap result : %s\n", s2);
// 	return (0);
// }
