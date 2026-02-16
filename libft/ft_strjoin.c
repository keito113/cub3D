/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:47:38 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:41:36 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strjoin - 2つの文字列を連結して新規文字列を作る。引数(char const *s1, char const *s2)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: malloc() -> ft_strlen()。 */
char	*ft_strjoin(char const *s1, char const *s2) // ft_strjoin関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*res; // 変数 res（resの作業用値） を宣言する
	char	*tmp; // 変数 tmp（tmpの作業用値） を宣言する

	if (!s1 || !s2) // 条件(!s1)が成立する または 条件(!s2)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	res = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1); // res に malloc((ft_strlen(s1) + ft_strlen(s2)) + 1) の計算結果を代入する
	if (!res) // 条件(!res)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	tmp = res; // tmp に res の計算結果を代入する
	while (*s1) // 条件(*s1)が成立する場合に分岐する
		*tmp++ = *s1++; // 前行から続く式に演算を連結して計算を完成させる
	while (*s2) // 条件(*s2)が成立する場合に分岐する
		*tmp++ = *s2++; // 前行から続く式に演算を連結して計算を完成させる
	*tmp = '\0'; // 前行から続く式に演算を連結して計算を完成させる
	return (res); // 関数を終了し、res を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	char s1[] = "Hello ";
// 	char s2[] = "World";

// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }