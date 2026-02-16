/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:59:44 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 17:44:18 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: count_words - 区切り文字で分割した単語数を数える。引数(const char *s, char c)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
static int	count_words(const char *s, char c) // count_words関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	count; // 変数 count（countの作業用値） を宣言する
	int	in_word; // 変数 in_word（in_wordの作業用値） を宣言する

	count = 0; // count に 0 の計算結果を代入する
	in_word = 0; // in_word に 0 の計算結果を代入する
	while (*s) // 条件(*s)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (*s != c && !in_word) // *s != c が成立する かつ 条件(!in_word)が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			in_word = 1; // in_word に 1 の計算結果を代入する
			count++; // 文 `count++;` を実行する
		} // ここでブロックスコープを終了する
		else if (*s == c) // *s == c が成立する場合に分岐する
			in_word = 0; // in_word に 0 の計算結果を代入する
		s++; // 文 `s++;` を実行する
	} // ここでブロックスコープを終了する
	return (count); // 関数を終了し、count を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: mini_word - 指定長の単語を新規メモリへ切り出す。引数(const char *str, int len)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: malloc()。 */
static char	*mini_word(const char *str, int len) // mini_word関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*word; // 変数 word（wordの作業用値） を宣言する
	int		i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	word = malloc(sizeof(char) * (len + 1)); // word に malloc(sizeof(char) * (len + 1)) の計算結果を代入する
	if (!word) // 条件(!word)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	while (i < len) // i < len が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		word[i] = str[i]; // word[i] に str[i] の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	word[i] = '\0'; // word[i] に '\0' の計算結果を代入する
	return (word); // 関数を終了し、word を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: ft_free_all - ftを解放する。引数(char **res)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: free()。 */
static void	ft_free_all(char **res) // ft_free_all関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (res[i]) // 条件(res[i])が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		free(res[i]); // free() を呼び出して、対象を解放する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	free(res); // free() を呼び出して、対象を解放する
} // ここでブロックスコープを終了する

/* 関数概要: word_export - 分割した単語を配列へ格納する。引数(const char *str, char c, char **res)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: mini_word() -> ft_free_all()。 */
static int	word_export(const char *str, char c, char **res) // word_export関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	i; // 変数 i（ループ用インデックス） を宣言する
	int	len; // 変数 len（文字列長） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (*str) // 条件(*str)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (*str != c) // *str != c が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			len = 0; // len に 0 の計算結果を代入する
			while (str[len] && str[len] != c) // 条件(str[len])が成立する かつ str[len] != c が成立する場合に分岐する
				len++; // 文 `len++;` を実行する
			res[i] = mini_word(str, len); // res[i] に mini_word(str, len) の計算結果を代入する
			if (!res[i]) // 条件(!res[i])が成立する場合に分岐する
			{ // ここからブロックスコープを開始する
				ft_free_all(res); // ft_free_all() を呼び出して、ftを解放する
				return (0); // 関数を終了し、0 を呼び出し元へ返す
			} // ここでブロックスコープを終了する
			str += len; // str を += で更新し、len を反映する
			i++; // 文 `i++;` を実行する
		} // ここでブロックスコープを終了する
		else // 直前のif/else if条件に当てはまらない場合の処理へ進む
			str++; // 文 `str++;` を実行する
	} // ここでブロックスコープを終了する
	res[i] = NULL; // res[i] に NULL の計算結果を代入する
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: ft_split - 区切り文字で文字列を分割する。引数(char const *s, char c)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: malloc() -> count_words() -> word_export()。 */
char	**ft_split(char const *s, char c) // ft_split関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	**res; // 変数 res（resの作業用値） を宣言する

	if (!s) // 条件(!s)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	res = malloc(sizeof(char *) * (count_words(s, c) + 1)); // res に malloc(sizeof(char *) * (count_words(s, c) + 1)) の計算結果を代入する
	if (!res) // 条件(!res)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	if (!word_export(s, c, res)) // word_export()で分割した単語を配列へ格納した結果が偽（条件不成立）なら分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	return (res); // 関数を終了し、res を呼び出し元へ返す
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char	**res;
// 	int		i;

// 	s = "__Macbook__ipad___iphone";
// 	c = "_";
// 	res = ft_split(s, c);
// 	i = 0;
// 	while (res && res[i])
// 	{
// 		printf("%s\n", res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }
