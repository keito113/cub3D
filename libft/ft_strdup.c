/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:07:22 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:13:07 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strdup - 文字列を新規メモリへ複製する。引数(const char *s)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> ft_calloc()。 */
char	*ft_strdup(const char *s) // ft_strdup関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	len; // 変数 len（文字列長） を宣言する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する
	char	*copy; // 変数 copy（copyの作業用値） を宣言する

	len = ft_strlen(s); // len に ft_strlen(s) の計算結果を代入する
	copy = ft_calloc(len + 1, sizeof(char)); // copy に ft_calloc(len + 1, sizeof(char)) の計算結果を代入する
	if (copy == NULL) // copy == NULL が成立する場合に分岐する
		return ((NULL)); // 関数を終了し、(NULL) を呼び出し元へ返す
	i = 0; // i に 0 の計算結果を代入する
	while (i < len) // i < len が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		copy[i] = s[i]; // copy[i] に s[i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (copy); // 関数を終了し、copy を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	const char *s1;
// 	s1 = "Hello,World";
// 	printf("%s\n", ft_strdup(s1));
// 	return (0);
// }