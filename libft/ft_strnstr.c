/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:11:46 by takawagu          #+#    #+#             */
/*   Updated: 2025/04/28 17:15:18 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strnstr - 文字列中から部分文字列を検索する。引数(const char *big, const char *little, size_t len)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
char	*ft_strnstr(const char *big, const char *little, size_t len) // ft_strnstr関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する
	size_t	j; // 変数 j（ループ用インデックス） を宣言する

	if (little[0] == '\0') // little[0] == '\0' が成立する場合に分岐する
		return ((char *)big); // 関数を終了し、(char *)big を呼び出し元へ返す
	i = 0; // i に 0 の計算結果を代入する
	while (i < len && big[i] != '\0') // i < len が成立する かつ big[i] != '\0' が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		j = 0; // j に 0 の計算結果を代入する
		while (i + j < len && little[j] != '\0' && big[i + j] == little[j]) // i + j < len が成立する かつ little[j] != '\0' が成立する かつ big[i + j] == little[j] が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			j++; // 文 `j++;` を実行する
		} // ここでブロックスコープを終了する
		if (little[j] == '\0') // little[j] == '\0' が成立する場合に分岐する
			return ((char *)(big + i)); // 関数を終了し、(char *)(big + i) を呼び出し元へ返す
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*big = "Harry Potter";
// 	const char	*little = "Pot";
// 	char		*ptr;

// 	ptr = ft_strnstr(big, little, 10);
// 	if (ptr != NULL)
// 	{
// 		printf("ポインタ値: %p\n", (void *)ptr);
// 		printf("最初の文字: %c\n", *ptr);
// 		printf("以降の文字列: %s\n", ptr);
// 	}
// 	else
// 	{
// 		printf("見つかりませんでした\n");
// 	}
// 	return (0);
// }
