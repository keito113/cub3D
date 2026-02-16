/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:41:40 by takawagu          #+#    #+#             */
/*   Updated: 2025/11/04 12:33:37 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: dispatch_format - 書式指定を振り分ける。引数(char specifier, va_list *args)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: print_char() -> va_arg() -> print_str() -> print_int()。 */
int	dispatch_format(char specifier, va_list *args) // dispatch_format関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (specifier == 'c') // specifier == 'c' が成立する場合に分岐する
		return (print_char(va_arg(*args, int))); // 関数を終了し、print_char(va_arg(*args, int)) を呼び出し元へ返す
	else if (specifier == 's') // specifier == 's' が成立する場合に分岐する
		return (print_str(va_arg(*args, char *))); // 関数を終了し、print_str(va_arg(*args, char *)) を呼び出し元へ返す
	else if (specifier == 'd' || specifier == 'i') // specifier == 'd' が成立する または specifier == 'i' が成立する場合に分岐する
		return (print_int(va_arg(*args, int))); // 関数を終了し、print_int(va_arg(*args, int)) を呼び出し元へ返す
	else if (specifier == 'u') // specifier == 'u' が成立する場合に分岐する
		return (print_unsigned(va_arg(*args, unsigned int))); // 関数を終了し、print_unsigned(va_arg(*args, unsigned int)) を呼び出し元へ返す
	else if (specifier == 'x') // specifier == 'x' が成立する場合に分岐する
		return (print_hex(va_arg(*args, unsigned int), 0)); // 関数を終了し、print_hex(va_arg(*args, unsigned int), 0) を呼び出し元へ返す
	else if (specifier == 'X') // specifier == 'X' が成立する場合に分岐する
		return (print_hex(va_arg(*args, unsigned int), 1)); // 関数を終了し、print_hex(va_arg(*args, unsigned int), 1) を呼び出し元へ返す
	else if (specifier == 'p') // specifier == 'p' が成立する場合に分岐する
		return (print_pointer(va_arg(*args, void *))); // 関数を終了し、print_pointer(va_arg(*args, void *)) を呼び出し元へ返す
	else if (specifier == '%') // specifier == '%' が成立する場合に分岐する
		return (write(1, "%", 1)); // 関数を終了し、write(1, "%", 1) を呼び出し元へ返す
	return (-1); // 関数を終了し、-1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: handle_format - 書式指定子を解釈して対応する出力関数へ振り分ける。引数(const char *format, va_list *args, int *index)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: dispatch_format() -> write()。 */
int	handle_format(const char *format, va_list *args, int *index) // handle_format関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		tmp; // 変数 tmp（tmpの作業用値） を宣言する
	ssize_t	write_ret_percent; // 変数 write_ret_percent（write_ret_percentの作業用値） を宣言する
	ssize_t	write_ret_specifier; // 変数 write_ret_specifier（write_ret_specifierの作業用値） を宣言する

	if (format[*index] == '%') // format[*index] == '%' が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (format[*index + 1] == '\0') // format[*index + 1] == '\0' が成立する場合に分岐する
			return (-1); // 関数を終了し、-1 を呼び出し元へ返す
		tmp = dispatch_format(format[*index + 1], args); // tmp に dispatch_format(format[*index + 1], args) の計算結果を代入する
		if (tmp < 0) // tmp < 0 が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			write_ret_percent = write(1, &format[*index], 1); // write_ret_percent に write(1, &format[*index], 1) の計算結果を代入する
			write_ret_specifier = write(1, &format[*index + 1], 1); // write_ret_specifier に write(1, &format[*index + 1], 1) の計算結果を代入する
			if (write_ret_percent < 0 || write_ret_specifier < 0) // write_ret_percent < 0 が成立する または write_ret_specifier < 0 が成立する場合に分岐する
				return (-1); // 関数を終了し、-1 を呼び出し元へ返す
			tmp = (int)(write_ret_percent + write_ret_specifier); // tmp に (int)(write_ret_percent + write_ret_specifier) の計算結果を代入する
		} // ここでブロックスコープを終了する
		*index += 2; // 前行から続く式に演算を連結して計算を完成させる
		return (tmp); // 関数を終了し、tmp を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	write_ret_percent = write(1, &format[*index], 1); // write_ret_percent に write(1, &format[*index], 1) の計算結果を代入する
	if (write_ret_percent < 0) // write_ret_percent < 0 が成立する場合に分岐する
		return (-1); // 関数を終了し、-1 を呼び出し元へ返す
	(*index)++; // 文 `(*index)++;` を実行する
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する
