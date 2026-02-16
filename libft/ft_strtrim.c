/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:56:01 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:13:18 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_strtrim - 指定文字集合を両端から取り除く。引数(char const *s1, char const *set)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strchr() -> ft_strlen() -> malloc() -> ft_strlcpy()。 */
char	*ft_strtrim(char const *s1, char const *set) // ft_strtrim関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	start; // 変数 start（startの作業用値） を宣言する
	size_t	end; // 変数 end（endの作業用値） を宣言する
	char	*res; // 変数 res（resの作業用値） を宣言する

	if (!s1 || !set) // 条件(!s1)が成立する または 条件(!set)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	start = 0; // start に 0 の計算結果を代入する
	while (s1[start] && ft_strchr(set, s1[start])) // 条件(s1[start])が成立する かつ ft_strchr()で文字列から指定文字の位置を探すを実行し、その戻り値が非0（真）なら分岐する
		start++; // 文 `start++;` を実行する
	end = ft_strlen(s1); // end に ft_strlen(s1) の計算結果を代入する
	while (end > start && ft_strchr(set, s1[end - 1])) // end > start が成立する かつ ft_strchr()で文字列から指定文字の位置を探すを実行し、その戻り値が非0（真）なら分岐する
		end--; // 文 `end--;` を実行する
	res = malloc(end - start + 1); // res に malloc(end - start + 1) の計算結果を代入する
	if (!res) // 条件(!res)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	ft_strlcpy(res, s1 + start, end - start + 1); // ft_strlcpy() を呼び出して、サイズ上限付きで文字列をコピーする
	return (res); // 関数を終了し、res を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	char const	s1[] = "___====-----heyheyhey!_----__";
// 	char const	s2[] = "-=_";

// 	printf("%s\n", ft_strtrim(s1, s2));
// 	return (0);
// }
