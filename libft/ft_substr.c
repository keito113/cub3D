/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:38:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/01 16:47:26 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_substr - 部分文字列を切り出して複製する。引数(const char *s, unsigned int start, size_t len)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> ft_calloc()。 */
char	*ft_substr(const char *s, unsigned int start, size_t len) // ft_substr関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*dst; // 変数 dst（ピクセル書き込み先アドレス） を宣言する
	size_t	s_len; // 変数 s_len（s_lenの作業用値） を宣言する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する

	if (!s) // 条件(!s)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	s_len = ft_strlen(s); // s_len に ft_strlen(s) の計算結果を代入する
	if (start >= s_len) // start >= s_len が成立する場合に分岐する
		return (ft_calloc(1, sizeof(char))); // 関数を終了し、ft_calloc(1, sizeof(char)) を呼び出し元へ返す
	if (s_len - start < len) // s_len - start < len が成立する場合に分岐する
		len = s_len - start; // len に s_len - start の計算結果を代入する
	dst = ft_calloc(len + 1, sizeof(char)); // dst に ft_calloc(len + 1, sizeof(char)) の計算結果を代入する
	if (!dst) // 条件(!dst)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	i = 0; // i に 0 の計算結果を代入する
	while (dst != NULL && s != NULL && i < len) // dst != NULL が成立する かつ s != NULL が成立する かつ i < len が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		dst[i] = s[start + i]; // dst[i] に s[start + i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (dst); // 関数を終了し、dst を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char *s1 = ft_substr("Helloooooo!!", 3, 8);
// 	printf("%s\n", s1);
// 	free(s1);

// 	return (0);
// }