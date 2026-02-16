/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:08:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:21:52 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_memset - メモリ領域を指定値で埋める。引数(void *b, int c, size_t len)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	*ft_memset(void *b, int c, size_t len) // ft_memset関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	size_t	i; // 変数 i（ループ用インデックス） を宣言する
	char	*str; // 変数 str（strの作業用値） を宣言する

	str = b; // str に b の計算結果を代入する
	i = 0; // i に 0 の計算結果を代入する
	while (i < len) // i < len が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		str[i] = c; // str[i] に c の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	return (b); // 関数を終了し、b を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "sjaojda";
// 	void	*address;
// 	int		c;
// 	size_t	len;

// 	c = '1';
// 	len = 7;
// 	address = &str;
// 	printf("変更前;%s\n", str);
// 	ft_memset(address, c, len);
// 	printf("変更後;%s\n", str);
// 	return (0);
// }
