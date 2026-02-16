/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:28:44 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/19 16:10:35 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
#include <stdint.h> // <stdint.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: putnbr_base_ulong - putnbr_base_ulongを実行する。引数(unsigned long n, const char *base)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: write()。 */
static int	putnbr_base_ulong(unsigned long n, const char *base) // putnbr_base_ulong関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	len; // 変数 len（文字列長） を宣言する
	int	sub; // 変数 sub（subの作業用値） を宣言する

	len = 0; // len に 0 の計算結果を代入する
	if (n >= 16) // n >= 16 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		sub = putnbr_base_ulong(n / 16, base); // sub に putnbr_base_ulong(n / 16, base) の計算結果を代入する
		if (sub < 0) // sub < 0 が成立する場合に分岐する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		len += sub; // len を += で更新し、sub を反映する
	} // ここでブロックスコープを終了する
	if (write(1, &base[n % 16], 1) < 0) // write(1, &base[n % 16], 1) < 0 が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	return (len + 1); // 関数を終了し、len + 1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: print_pointer - pointerを出力する。引数(void *ptr)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: write() -> putnbr_base_ulong()。 */
int	print_pointer(void *ptr) // print_pointer関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	uintptr_t	addr; // 変数 addr（addrの作業用値） を宣言する
	int			len; // 変数 len（文字列長） を宣言する

	if (ptr == NULL) // ptr == NULL が成立する場合に分岐する
		return (write(1, "(nil)", 5)); // 関数を終了し、write(1, "(nil)", 5) を呼び出し元へ返す
	addr = (uintptr_t)ptr; // addr に (uintptr_t)ptr の計算結果を代入する
	if (write(1, "0x", 2) < 0) // write(1, "0x", 2) < 0 が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	len = putnbr_base_ulong(addr, "0123456789abcdef"); // len に putnbr_base_ulong(addr, "0123456789abcdef") の計算結果を代入する
	if (len < 0) // len < 0 が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	return (len + 2); // 関数を終了し、len + 2 を呼び出し元へ返す
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	char	*s;

// 	s = "Hello";
// 	print_pointer(s);
// 	return (0);
// }
