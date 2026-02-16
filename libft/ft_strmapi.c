/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:40:05 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:30:15 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: char - charを実行する。引数(char const *s, char (*f)(unsigned int, char))を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: malloc() -> ft_strlen() -> f()。 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)) // char関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char			*res; // 変数 res（resの作業用値） を宣言する
	unsigned int	i; // 変数 i（ループ用インデックス） を宣言する

	if (!s || !f) // 条件(!s)が成立する または 条件(!f)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	res = malloc(ft_strlen(s) + 1); // res に malloc(ft_strlen(s) + 1) の計算結果を代入する
	if (!res) // 条件(!res)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	i = 0; // i に 0 の計算結果を代入する
	while (s[i]) // 条件(s[i])が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		res[i] = f(i, s[i]); // res[i] に f(i, s[i]) の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	res[i] = '\0'; // res[i] に '\0' の計算結果を代入する
	return (res); // 関数を終了し、res を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// char	to_upper_even(unsigned int i, char c)
// {
// 	if (i % 2 == 0 && c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main(void)
// {
// 	char const	*s;
// 	char		*result;

// 	s = "Hello World";
// 	result = ft_strmapi(s, to_upper_even);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
