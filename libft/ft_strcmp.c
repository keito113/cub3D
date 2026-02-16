/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:27:09 by takawagu          #+#    #+#             */
/*   Updated: 2025/09/02 14:27:53 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strcmp - 文字列を比較する。引数(const char *s1, const char *s2)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
int	ft_strcmp(const char *s1, const char *s2) // ft_strcmp関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	const unsigned char	*p1 = (const unsigned char *)s1; // const unsigned char	*p1 に (const unsigned char *)s1 の計算結果を代入する
	const unsigned char	*p2 = (const unsigned char *)s2; // const unsigned char	*p2 に (const unsigned char *)s2 の計算結果を代入する

	while (*p1 && *p2) // 条件(*p1)が成立する かつ 条件(*p2)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (*p1 != *p2) // *p1 != *p2 が成立する場合に分岐する
			return ((int)(*p1) - (int)(*p2)); // 関数を終了し、(int)(*p1) - (int)(*p2) を呼び出し元へ返す
		p1++; // 文 `p1++;` を実行する
		p2++; // 文 `p2++;` を実行する
	} // ここでブロックスコープを終了する
	return ((int)(*p1) - (int)(*p2)); // 関数を終了し、(int)(*p1) - (int)(*p2) を呼び出し元へ返す
} // ここでブロックスコープを終了する
