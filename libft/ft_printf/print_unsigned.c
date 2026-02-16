/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:19:00 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/24 13:50:00 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: print_unsigned - unsignedを出力する。引数(unsigned int un)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_utoa() -> print_str() -> free()。 */
int	print_unsigned(unsigned int un) // print_unsigned関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char			*str; // 変数 str（strの作業用値） を宣言する
	unsigned int	len; // 変数 len（文字列長） を宣言する

	str = ft_utoa(un); // str に ft_utoa(un) の計算結果を代入する
	if (!str) // 条件(!str)が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	len = print_str(str); // len に print_str(str) の計算結果を代入する
	free(str); // free() を呼び出して、対象を解放する
	return (len); // 関数を終了し、len を呼び出し元へ返す
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	unsigned int	un;

// 	un = 4294967295;
// 	print_unsigned(un);
// 	return (0);
// }
