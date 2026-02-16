/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:12:59 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:21:15 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_memcpy - メモリ領域をコピーする。引数(void *dst, const void *src, size_t n)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	*ft_memcpy(void *dst, const void *src, size_t n) // ft_memcpy関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	unsigned char		*d; // 変数 d（dの作業用値） を宣言する
	const unsigned char	*s; // 変数 s（sの作業用値） を宣言する
	size_t				i; // 変数 i（ループ用インデックス） を宣言する

	if (!dst && !src && n == 0) // 条件(!dst)が成立する かつ 条件(!src)が成立する かつ n == 0 が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	d = (unsigned char *)dst; // d に (unsigned char *)dst の計算結果を代入する
	s = (unsigned char *)src; // s に (unsigned char *)src の計算結果を代入する
	i = 0; // i に 0 の計算結果を代入する
	while (i < n) // i < n が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		d[i] = s[i]; // d[i] に s[i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (dst); // 関数を終了し、dst を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "Hello world!";
// 	char d[6];

// 	ft_memcpy(s + 6, s, 10);

// 	printf("%s\n", s);
// 	return (0);
// }