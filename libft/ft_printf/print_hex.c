/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:47:23 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/21 11:22:57 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: putnbr_base_hex - putnbr_base_hexを実行する。引数(unsigned int n, const char *base)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: write()。 */
static int	putnbr_base_hex(unsigned int n, const char *base) // putnbr_base_hex関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	len; // 変数 len（文字列長） を宣言する
	int	sub; // 変数 sub（subの作業用値） を宣言する

	len = 0; // len に 0 の計算結果を代入する
	if (n >= 16) // n >= 16 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		sub = putnbr_base_hex(n / 16, base); // sub に putnbr_base_hex(n / 16, base) の計算結果を代入する
		if (sub < 0) // sub < 0 が成立する場合に分岐する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		len += sub; // len を += で更新し、sub を反映する
	} // ここでブロックスコープを終了する
	if (write(1, &base[n % 16], 1) < 0) // write(1, &base[n % 16], 1) < 0 が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	return (len + 1); // 関数を終了し、len + 1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: print_hex - hexを出力する。引数(unsigned int hex_n, int uppercase)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: putnbr_base_hex()。 */
int	print_hex(unsigned int hex_n, int uppercase) // print_hex関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	const char	*base; // 変数 base（baseの作業用値） を宣言する

	if (uppercase) // 条件(uppercase)が成立する場合に分岐する
		base = "0123456789ABCDEF"; // base に "0123456789ABCDEF" の計算結果を代入する
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
		base = "0123456789abcdef"; // base に "0123456789abcdef" の計算結果を代入する
	return (putnbr_base_hex(hex_n, base)); // 関数を終了し、putnbr_base_hex(hex_n, base) を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned int	xn;

// 	xn = 4233237;
// 	print_hex(xn, 0);
// 	write(1, "\n", 1);
// 	print_hex(xn, 1);
// 	return (0);
// }
