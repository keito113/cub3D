/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:31:16 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/21 11:12:36 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: print_int - intを出力する。引数(int n)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_itoa() -> print_str() -> free()。 */
int	print_int(int n) // print_int関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char			*str; // 変数 str（strの作業用値） を宣言する
	unsigned int	len; // 変数 len（文字列長） を宣言する

	str = ft_itoa(n); // str に ft_itoa(n) の計算結果を代入する
	if (!str) // 条件(!str)が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	len = print_str(str); // len に print_str(str) の計算結果を代入する
	free(str); // free() を呼び出して、対象を解放する
	return (len); // 関数を終了し、len を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	int	n;

// 	n = 21010;
// 	ft_print_int(n);
// 	return (0);
// }
