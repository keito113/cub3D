/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:16:16 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/05 00:18:37 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strncmp - 文字列を先頭n文字で比較する。引数(const char *s1, const char *s2, size_t n)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
int	ft_strncmp(const char *s1, const char *s2, size_t n) // ft_strncmp関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (i < n) // i < n が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if ((unsigned char)s1[i] != (unsigned char)s2[i] // (unsigned char)s1[i] != (unsigned char が成立する場合に分岐する
			|| (unsigned char)s1[i] == '\0' || (unsigned char)s2[i] == '\0') // 前行の条件式へ OR 条件を追加する
			return ((unsigned char)s1[i] - (unsigned char)s2[i]); // 関数を終了し、(unsigned char)s1[i] - (unsigned char)s2[i] を呼び出し元へ返す
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s1;
// 	const char	*s2;

// 	s1 = "ACBDD";
// 	s2 = "ABBDEF";
// 	printf("結果:%d\n", ft_strncmp(s1, s2, 3));
// 	return (0);
// }
