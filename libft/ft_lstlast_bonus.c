/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:00:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:56:45 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_lstlast - リスト末尾ノードを取得する。引数(t_list *lst)を受け取り、成功/失敗または計算結果を戻り値で返す。 */
t_list	*ft_lstlast(t_list *lst) // ft_lstlast関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (!lst) // 条件(!lst)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	while (lst->next != NULL) // lst- > next != NULL が成立する場合に分岐する
		lst = lst->next; // lst に lst->next の計算結果を代入する
	return (lst); // 関数を終了し、lst を呼び出し元へ返す
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	t_list *a = ft_lstnew(strdup("First"));
// 	t_list *b = ft_lstnew(strdup("Second"));
// 	a->next = b;

// 	t_list *last = ft_lstlast(a);
// 	printf("Last content: %s\n", (char *)last->content);

// 	return (0);
// }