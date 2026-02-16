/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:49:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/11/04 12:33:35 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_printf - 可変長引数を使って書式付き文字列を出力する。引数(const char *format, ...)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: va_start() -> handle_format() -> va_end()。 */
int	ft_printf(const char *format, ...) // ft_printf関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	va_list	args; // 変数 args（argsの作業用値） を宣言する
	int		i; // 変数 i（ループ用インデックス） を宣言する
	int		printed_len; // 変数 printed_len（printed_lenの作業用値） を宣言する
	int		tmp; // 変数 tmp（tmpの作業用値） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	printed_len = 0; // printed_len に 0 の計算結果を代入する
	if (!format) // 条件(!format)が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	va_start(args, format); // va_start() を呼び出して、va_startを実行する
	while (format[i]) // 条件(format[i])が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		tmp = handle_format(format, &args, &i); // tmp に handle_format(format, &args, &i) の計算結果を代入する
		if (tmp < 0) // tmp < 0 が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			va_end(args); // va_end() を呼び出して、va_endを実行する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		} // ここでブロックスコープを終了する
		printed_len += tmp; // printed_len を += で更新し、tmp を反映する
	} // ここでブロックスコープを終了する
	va_end(args); // va_end() を呼び出して、va_endを実行する
	return (printed_len); // 関数を終了し、printed_len を呼び出し元へ返す
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	int	ret_ft;
// 	int	ret_std;

// 	// テスト1:
// 	// 	文字列
// 	ret_ft = ft_printf("ft_printf: [%s]\n", "Hello World");
// 	ret_std = printf("printf:    [%s]\n", "Hello World");
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	// テスト2: 整数
// 	ret_ft = ft_printf("ft_printf: [%d]\n", 12345);
// 	ret_std = printf("printf:    [%d]\n", 12345);
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	// テスト3: NULL文字列
// 	ret_ft = ft_printf("ft_printf: [%s]\n", (char *)NULL);
// 	ret_std = printf("printf:    [%s]\n", (char *)NULL);
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	// テスト4: ポインタ
// 	ret_ft = ft_printf("ft_printf: [%p]\n", (void *)0x1234);
// 	ret_std = printf("printf:    [%p]\n", (void *)0x1234);
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	return (0);
// }

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	ssize_t	ret;

// 	close(1); // 標準出力を閉じる
// 	ret = write(1, "Hello\n", 6);
// 	// 標準エラー出力に結果を表示
// 	dprintf(2, "write returned: %zd\n", ret);
// 	perror("write");
// 	return (0);
// }

// #include "ft_printf.h"
// #include <stdio.h>

// int	main(void)
// {
// 	int	result;

// 	result = ft_printf("テスト:さｂじゃ%"); // ← 不完全な % を渡す
// 	printf("\n戻り値: %d\n", result);
// 	return (0);
// }

// int	main(void)
// {
// 	char			*p;
// 	int				d;
// 	unsigned int	u_num;
// 	char			a;
// 	char			*s;
// 	int				ret1;
// 	int				ret2;

// 	d = 0;
// 	u_num = UINT_MAX;
// 	p = &a;
// 	s = "%k";
// 	ret1 = printf("%X,%x,%s", u_num, u_num, s);
// 	printf("\n");
// 	ret2 = ft_printf("%X,%x,%s", u_num, u_num, s);
// 	printf("\n");
// 	printf("%d", ret1);
// 	printf("\n");
// 	printf("%d", ret2);
// 	printf("\n");
// 	return (0);
// }
