/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:16:06 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:22:16 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_calloc - ゼロ初期化済みメモリを確保する。引数(size_t count, size_t size)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: malloc() -> ft_memset()。 */
void	*ft_calloc(size_t count, size_t size) // ft_calloc関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	void	*ptr; // 変数 ptr（ptrの作業用値） を宣言する
	size_t	total_size; // 変数 total_size（total_sizeの作業用値） を宣言する

	if (count == 0 || size == 0) // count == 0 が成立する または size == 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		ptr = malloc(1); // ptr に malloc(1) の計算結果を代入する
		if (!ptr) // 条件(!ptr)が成立する場合に分岐する
			return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
		return (ptr); // 関数を終了し、ptr を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	if (count > __SIZE_MAX__ / size) // count > __SIZE_MAX__ / size が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	total_size = count * size; // total_size に count * size の計算結果を代入する
	ptr = malloc(total_size); // ptr に malloc(total_size) の計算結果を代入する
	if (!ptr) // 条件(!ptr)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	ft_memset(ptr, 0, total_size); // ft_memset() を呼び出して、メモリ領域を指定値で埋める
	return (ptr); // 関数を終了し、ptr を呼び出し元へ返す
} // ここでブロックスコープを終了する

// #include <stdio.h>

// int	main(void)
// {
// 	size_t count;
// 	size_t size;
// 	const char *str;
// 	str = "Hello";
// 	void *memory;
// 	count = ft_strlen(str) + 1;
// 	size = sizeof(char);

// 	memory = (malloc(count * size));
// 	if (memory == NULL)
// 	{
// 		printf("メモリ確保に失敗しました\n");
// 		return (1);
// 	}
// 	else
// 	{
// 		printf("メモリ確保成功しました\n");
// 	}

// 	free(memory);
// 	return (0);
// }