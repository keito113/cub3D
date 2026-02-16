/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:04:08 by takawagu          #+#    #+#             */
/*   Updated: 2025/11/04 12:34:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H // インクルードガードを開始し、ヘッダ重複展開を防ぐ
# define FT_PRINTF_H // FT_PRINTF_Hマクロを定義する

# include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stdarg.h> // <stdarg.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stdlib.h> // <stdlib.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <unistd.h> // <unistd.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

int		ft_printf(const char *format, ...); // ft_printf() の関数宣言。目的: 可変長引数を使って書式付き文字列を出力する
int		dispatch_format(char specifier, va_list *args); // dispatch_format() の関数宣言。目的: 書式指定を振り分ける
int		handle_format(const char *format, va_list *args, int *index); // handle_format() の関数宣言。目的: 書式指定子を解釈して対応する出力関数へ振り分ける
int		print_char(char c); // print_char() の関数宣言。目的: charを出力する
int		print_str(const char *s); // print_str() の関数宣言。目的: strを出力する
int		print_int(int n); // print_int() の関数宣言。目的: intを出力する
int		print_unsigned(unsigned int un); // print_unsigned() の関数宣言。目的: unsignedを出力する
int		print_hex(unsigned int xn, int uppercase); // print_hex() の関数宣言。目的: hexを出力する
int		print_pointer(void *p); // print_pointer() の関数宣言。目的: pointerを出力する
char	*ft_utoa(unsigned int un); // ft_utoa() の関数宣言。目的: ft_utoaを実行する

#endif // インクルードガード/条件コンパイルを終了する
