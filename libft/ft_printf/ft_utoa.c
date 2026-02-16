/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:24:58 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/24 13:41:03 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: num_len_unsigned_int - num_len_unsigned_intを実行する。引数(unsigned int u_num)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static unsigned int	num_len_unsigned_int(unsigned int u_num) // num_len_unsigned_int関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	unsigned int	len; // 変数 len（文字列長） を宣言する

	len = 1; // len に 1 の計算結果を代入する
	while (u_num >= 10) // u_num >= 10 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		u_num /= 10; // u_num を /= で更新し、10 を反映する
		len++; // 文 `len++;` を実行する
	} // ここでブロックスコープを終了する
	return (len); // 関数を終了し、len を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: ft_utoa - ft_utoaを実行する。引数(unsigned int n)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: num_len_unsigned_int() -> malloc()。 */
char	*ft_utoa(unsigned int n) // ft_utoa関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char			*str; // 変数 str（strの作業用値） を宣言する
	unsigned int	len; // 変数 len（文字列長） を宣言する

	len = num_len_unsigned_int(n); // len に num_len_unsigned_int(n) の計算結果を代入する
	str = malloc(len + 1); // str に malloc(len + 1) の計算結果を代入する
	if (!str) // 条件(!str)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	str[len] = '\0'; // str[len] に '\0' の計算結果を代入する
	while (len--) // 条件(len--)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		str[len] = n % 10 + '0'; // str[len] に n % 10 + '0' の計算結果を代入する
		n /= 10; // n を /= で更新し、10 を反映する
	} // ここでブロックスコープを終了する
	return (str); // 関数を終了し、str を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned int un;
// 	un = 4294967295;
// 	printf("%s\n", ft_utoa(un));

// 	return (0);
// }