/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:39:19 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:59:31 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_lstadd_front - ノードをリスト先頭へ追加する。引数(t_list **lst, t_list *new)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	ft_lstadd_front(t_list **lst, t_list *new) // ft_lstadd_front関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (lst && new) // 条件(lst)が成立する かつ 条件(new)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		new->next = *lst; // new->next に *lst の計算結果を代入する
		*lst = new; // 前行から続く式に演算を連結して計算を完成させる
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *new1 = ft_lstnew(strdup("World"));
// 	t_list *new2 = ft_lstnew(strdup("Hello"));

// 	ft_lstadd_front(&head, new1);
// 	ft_lstadd_front(&head, new2);

// 	t_list *curr = head;
// 	while (curr)
// 	{
// 		printf("%s\n", (char *)curr->content);
// 		curr = curr->next;
// 	}
// 	// free omitted for brevity
// 	return (0);
// }