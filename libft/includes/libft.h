/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:19:14 by takawagu          #+#    #+#             */
/*   Updated: 2025/09/02 14:25:32 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H // インクルードガードを開始し、ヘッダ重複展開を防ぐ
# define LIBFT_H // LIBFT_Hマクロを定義する

# include "ft_printf.h" // "ft_printf.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
# include "get_next_line.h" // "get_next_line.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <limits.h> // <limits.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stdio.h> // <stdio.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stdlib.h> // <stdlib.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <unistd.h> // <unistd.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

int					ft_isalpha(int c); // ft_isalpha() の関数宣言。目的: 英字か判定する
int					ft_isdigit(int c); // ft_isdigit() の関数宣言。目的: 数字か判定する
int					ft_isalnum(int c); // ft_isalnum() の関数宣言。目的: 英数字か判定する
int					ft_isascii(int c); // ft_isascii() の関数宣言。目的: ASCII文字か判定する
int					ft_isprint(int c); // ft_isprint() の関数宣言。目的: 表示可能文字か判定する
size_t				ft_strlen(const char *s); // ft_strlen() の関数宣言。目的: 文字列長を取得する
void				*ft_memset(void *b, int c, size_t len); // ft_memset() の関数宣言。目的: メモリ領域を指定値で埋める
void				ft_bzero(void *s, size_t n); // ft_bzero() の関数宣言。目的: メモリ領域を0で埋める
void				*ft_memcpy(void *dst, const void *src, size_t n); // ft_memcpy() の関数宣言。目的: メモリ領域をコピーする
void				*ft_memmove(void *dst, const void *src, size_t len); // ft_memmove() の関数宣言。目的: 重なりを考慮してメモリ領域を移動コピーする
size_t				ft_strlcpy(char *dst, const char *src, size_t size); // ft_strlcpy() の関数宣言。目的: サイズ上限付きで文字列をコピーする
size_t				ft_strlcat(char *dst, const char *src, size_t size); // ft_strlcat() の関数宣言。目的: サイズ上限付きで文字列を連結する

int					ft_toupper(int c); // ft_toupper() の関数宣言。目的: 小文字を大文字へ変換する
int					ft_tolower(int c); // ft_tolower() の関数宣言。目的: 大文字を小文字へ変換する
char				*ft_strchr(const char *s, int c); // ft_strchr() の関数宣言。目的: 文字列から指定文字の位置を探す
char				*ft_strrchr(const char *s, int c); // ft_strrchr() の関数宣言。目的: 文字列の末尾側から指定文字の位置を探す
int					ft_strncmp(const char *s1, const char *s2, size_t n); // ft_strncmp() の関数宣言。目的: 文字列を先頭n文字で比較する
void				*ft_memchr(const void *s, int c, size_t n); // ft_memchr() の関数宣言。目的: メモリ領域から指定値を検索する
int					ft_memcmp(const void *s1, const void *s2, size_t n); // ft_memcmp() の関数宣言。目的: メモリ領域を比較する
char				*ft_strnstr(const char *big, const char *little, // 関数呼び出し引数をこの行で追加し、次行へ続ける
						size_t len); // 文 `size_t len);` を実行する
int					ft_atoi(const char *nptr); // ft_atoi() の関数宣言。目的: 文字列を整数へ変換する

void				*ft_calloc(size_t count, size_t size); // ft_calloc() の関数宣言。目的: ゼロ初期化済みメモリを確保する
char				*ft_strdup(const char *s1); // ft_strdup() の関数宣言。目的: 文字列を新規メモリへ複製する

char				*ft_substr(char const *s, unsigned int start, size_t len); // ft_substr() の関数宣言。目的: 部分文字列を切り出して複製する
char				*ft_strjoin(char const *s1, char const *s2); // ft_strjoin() の関数宣言。目的: 2つの文字列を連結して新規文字列を作る
char				*ft_strtrim(char const *s1, char const *set); // ft_strtrim() の関数宣言。目的: 指定文字集合を両端から取り除く
char				**ft_split(char const *s, char c); // ft_split() の関数宣言。目的: 区切り文字で文字列を分割する
char				*ft_itoa(int n); // ft_itoa() の関数宣言。目的: 整数を文字列へ変換する
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // ft_strmapi() を呼び出して、各文字へコールバックを適用した新規文字列を作る
void				ft_striteri(char *s, void (*f)(unsigned int, char *)); // ft_striteri() を呼び出して、各文字へインデックス付きコールバックを適用する
void				ft_putchar_fd(char c, int fd); // ft_putchar_fd() の関数宣言。目的: 1文字をファイルディスクリプタへ出力する
void				ft_putstr_fd(char *s, int fd); // ft_putstr_fd() の関数宣言。目的: 文字列をファイルディスクリプタへ出力する
void				ft_putendl_fd(char *s, int fd); // ft_putendl_fd() の関数宣言。目的: 文字列末尾に改行を付けて出力する
void				ft_putnbr_fd(int n, int fd); // ft_putnbr_fd() の関数宣言。目的: 整数をファイルディスクリプタへ出力する
int					ft_max(int a, int b); // ft_max() の関数宣言。目的: 2値の大きい方を返す
int					ft_strcmp(const char *s1, const char *s2); // ft_strcmp() の関数宣言。目的: 文字列を比較する

typedef struct s_list // 式 `typedef struct s_list` を評価して処理を進める
{ // ここからブロックスコープを開始する
	void			*content; // 変数 content（contentの作業用値） を宣言する
	struct s_list	*next; // 変数 next（nextの作業用値） を宣言する
}					t_list; // 変数 t_list（t_listの作業用値） を宣言する

t_list				*ft_lstnew(void *content); // ft_lstnew() の関数宣言。目的: 新しいリストノードを生成する
void				ft_lstadd_front(t_list **lst, t_list *new); // ft_lstadd_front() の関数宣言。目的: ノードをリスト先頭へ追加する
void				ft_lstadd_back(t_list **lst, t_list *new); // ft_lstadd_back() の関数宣言。目的: ノードをリスト末尾へ追加する
void				ft_lstclear(t_list **lst, void (*del)(void *)); // ft_lstclear() を呼び出して、リスト全体を解放する
int					ft_lstsize(t_list *lst); // ft_lstsize() の関数宣言。目的: リスト要素数を数える
t_list				*ft_lstlast(t_list *lst); // ft_lstlast() の関数宣言。目的: リスト末尾ノードを取得する
void				ft_lstdelone(t_list *lst, void (*del)(void *)); // ft_lstdelone() を呼び出して、1ノードを削除する
void				ft_lstiter(t_list *lst, void (*f)(void *)); // ft_lstiter() を呼び出して、各ノードへ関数を適用する
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), // 関数呼び出し引数をこの行で追加し、次行へ続ける
						void (*del)(void *)); // void() の関数宣言。目的: voidを実行する

#endif // インクルードガード/条件コンパイルを終了する
