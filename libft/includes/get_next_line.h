/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:23:00 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/31 15:14:51 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H // インクルードガードを開始し、ヘッダ重複展開を防ぐ
# define GET_NEXT_LINE_H // GET_NEXT_LINE_Hマクロを定義する

# include <fcntl.h> // <fcntl.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stdio.h> // <stdio.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stdlib.h> // <stdlib.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <unistd.h> // <unistd.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

# ifndef BUFFER_SIZE // インクルードガードを開始し、ヘッダ重複展開を防ぐ
#  define BUFFER_SIZE 1024 // BUFFER_SIZEマクロを定義する
# endif // インクルードガード/条件コンパイルを終了する

char	*get_next_line(int fd); // get_next_line() の関数宣言。目的: next・lineを取得する
size_t	ft_strlen(const char *s); // ft_strlen() の関数宣言。目的: 文字列長を取得する
char	*gnl_ft_strchr(const char *s, int c); // gnl_ft_strchr() の関数宣言。目的: 文字列から指定文字の位置を検索する
char	*gnl_ft_strdup(const char *s); // gnl_ft_strdup() の関数宣言。目的: 文字列を複製する
char	*gnl_ft_strjoin(char const *s1, char const *s2); // gnl_ft_strjoin() の関数宣言。目的: 2つの文字列を連結する
void	*gnl_ft_memcpy(void *dst, const void *src, size_t n); // gnl_ft_memcpy() の関数宣言。目的: メモリ領域をコピーする

#endif // インクルードガード/条件コンパイルを終了する