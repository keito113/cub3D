/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:02:48 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:59:07 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_lstadd_back - ノードをリスト末尾へ追加する。引数(t_list **lst, t_list *new)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
void	ft_lstadd_back(t_list **lst, t_list *new) // ft_lstadd_back関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	t_list	*last; // 変数 last（lastの作業用値） を宣言する

	if (!lst || !new) // 条件(!lst)が成立する または 条件(!new)が成立する場合に分岐する
		return ; // この時点で関数を終了して呼び出し元へ戻る
	if (*lst == NULL) // *lst == NULL が成立する場合に分岐する
		*lst = new; // 前行から続く式に演算を連結して計算を完成させる
	else // 直前のif/else if条件に当てはまらない場合の処理へ進む
	{ // ここからブロックスコープを開始する
		last = *lst; // last に *lst の計算結果を代入する
		while (last->next) // last- > next が成立する場合に分岐する
			last = last->next; // last に last->next の計算結果を代入する
		last->next = new; // last->next に new の計算結果を代入する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *a = ft_lstnew(strdup("Front"));
// 	t_list *b = ft_lstnew(strdup("Back"));

// 	ft_lstadd_back(&head, a);
// 	ft_lstadd_back(&head, b);

// 	t_list *tmp = head;
// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }