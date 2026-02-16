/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:42:02 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:58:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
#include <stdlib.h> // <stdlib.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: void - voidを実行する。引数(t_list **lst, void (*del)(void *))を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: del() -> free()。 */
void	ft_lstclear(t_list **lst, void (*del)(void *)) // void関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	t_list	*tmp; // 変数 tmp（tmpの作業用値） を宣言する

	if (!lst || !del) // 条件(!lst)が成立する または 条件(!del)が成立する場合に分岐する
		return ; // この時点で関数を終了して呼び出し元へ戻る
	while (*lst) // 条件(*lst)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		tmp = (*lst)->next; // tmp に (*lst)->next の計算結果を代入する
		del((*lst)->content); // del() を呼び出して、delを実行する
		free(*lst); // free() を呼び出して、対象を解放する
		*lst = tmp; // 前行から続く式に演算を連結して計算を完成させる
	} // ここでブロックスコープを終了する
	*lst = NULL; // 前行から続く式に演算を連結して計算を完成させる
} // ここでブロックスコープを終了する

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *a = ft_lstnew(strdup("One"));
// 	t_list *b = ft_lstnew(strdup("Two"));
// 	t_list *c = ft_lstnew(strdup("Three"));
// 	a->next = b;
// 	b->next = c;

// 	ft_lstclear(&a, del);
// 	return (0); // Check with valgrind
// }
