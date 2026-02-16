/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:36:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/12 08:56:58 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_bzero - メモリ領域を0で埋める。引数(void *s, size_t n)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: ft_memset()。 */
void	ft_bzero(void *s, size_t n) // ft_bzero関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	ft_memset(s, 0, n); // ft_memset() を呼び出して、メモリ領域を指定値で埋める
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "sjaojda";
// 	void *address;
// 	size_t len;

// 	len = 7;
// 	address = &str;
// 	printf("変更前;%s\n", str);
// 	ft_bzero(address, len);
// 	printf("変更後;%s\n", str);
// 	return (0);
// }