/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:50:55 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:58:47 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_lstsize - リスト要素数を数える。引数(t_list *lst)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
int	ft_lstsize(t_list *lst) // ft_lstsize関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	count; // 変数 count（countの作業用値） を宣言する

	count = 0; // count に 0 の計算結果を代入する
	while (lst != NULL) // lst != NULL が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		count++; // 文 `count++;` を実行する
		lst = lst->next; // lst に lst->next の計算結果を代入する
	} // ここでブロックスコープを終了する
	return (count); // 関数を終了し、count を呼び出し元へ返す
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew("A");
// 	t_list *n2 = ft_lstnew("B");
// 	t_list *n3 = ft_lstnew("C");

// 	ft_lstadd_front(&n2, n1);
// 	ft_lstadd_back(&n1, n3);

// 	printf("ノード数: %d\n", ft_lstsize(n1));

// 	ft_lstclear(&n1, free);
// 	return (0);
// }