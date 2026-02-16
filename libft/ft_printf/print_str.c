/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:16:04 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/21 11:11:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: print_str - strを出力する。引数(const char *s)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> write()。 */
int	print_str(const char *s) // print_str関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	len; // 変数 len（文字列長） を宣言する
	ssize_t	ret; // 変数 ret（retの作業用値） を宣言する

	if (!s) // 条件(!s)が成立する場合に分岐する
		s = "(null)"; // s に "(null)" の計算結果を代入する
	len = ft_strlen(s); // len に ft_strlen(s) の計算結果を代入する
	ret = write(1, s, len); // ret に write(1, s, len) の計算結果を代入する
	if (ret < 0) // ret < 0 が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	return ((int)ret); // 関数を終了し、(int)ret を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;

// 	s = "Hello World";
// 	ft_print_str(s);
// }
