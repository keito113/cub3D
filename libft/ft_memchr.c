/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:16:41 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 23:25:57 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_memchr - メモリ領域から指定値を検索する。引数(const void *s, int c, size_t n)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	*ft_memchr(const void *s, int c, size_t n) // ft_memchr関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t				i; // 変数 i（ループ用インデックス） を宣言する
	const unsigned char	*str; // 変数 str（strの作業用値） を宣言する

	str = (const unsigned char *)s; // str に (const unsigned char *)s の計算結果を代入する
	i = 0; // i に 0 の計算結果を代入する
	while (i < n) // i < n が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (str[i] == (unsigned char)c) // str[i] == (unsigned char)c が成立する場合に分岐する
			return ((void *)(str + i)); // 関数を終了し、(void *)(str + i) を呼び出し元へ返す
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char	str[] = "Hello World";
// 	int			c;
// 	void		*p;

// 	c = 'p';
// 	p = ft_memchr(str, c, ft_strlen(str) + 1);
// 	if (p != NULL)
// 		printf("見つかった文字:%c\n", *(char *)p);
// 	else
// 		printf("見つかりませんでした\n");
// 	return (0);
// }
