/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 07:21:29 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/05 00:12:21 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strrchr - 文字列の末尾側から指定文字の位置を探す。引数(const char *s, int c)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
char	*ft_strrchr(const char *s, int c) // ft_strrchr関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		i; // 変数 i（ループ用インデックス） を宣言する
	char	*last; // 変数 last（lastの作業用値） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	last = NULL; // last に NULL の計算結果を代入する
	while (s[i]) // 条件(s[i])が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (s[i] == (char)c) // s[i] == (char)c が成立する場合に分岐する
			last = ((char *)(s + i)); // last に ((char *)(s + i)) の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	if ((char)c == '\0') // (char)c == '\0' が成立する場合に分岐する
		return ((char *)(s + i)); // 関数を終了し、(char *)(s + i) を呼び出し元へ返す
	return (last); // 関数を終了し、last を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s;
// 	int			c;

// 	s = "HelloWorld Windows";
// 	c = 'a';
// 	printf("抽出：%s", ft_strrchr(s, c));
// 	return (0);
// }
