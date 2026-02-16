/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:29:00 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:34:33 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_memcmp - メモリ領域を比較する。引数(const void *s1, const void *s2, size_t n)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
int	ft_memcmp(const void *s1, const void *s2, size_t n) // ft_memcmp関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t				i; // 変数 i（ループ用インデックス） を宣言する
	const unsigned char	*p1; // 変数 p1（p1の作業用値） を宣言する
	const unsigned char	*p2; // 変数 p2（p2の作業用値） を宣言する

	p1 = s1; // p1 に s1 の計算結果を代入する
	p2 = s2; // p2 に s2 の計算結果を代入する
	i = 0; // i に 0 の計算結果を代入する
	while (i < n) // i < n が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (p1[i] != p2[i]) // p1[i] != p2[i] が成立する場合に分岐する
			return (p1[i] - p2[i]); // 関数を終了し、p1[i] - p2[i] を呼び出し元へ返す
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s1;
// 	const char	*s2;

// 	s1 = "ABbDD";
// 	s2 = "ABBDEF";
// 	printf("結果:%d\n", ft_memcmp(s1, s2, ft_strlen(s1) + 1));
// 	return (0);
// }