/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:19:11 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:29:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: ft_lstnew - 新しいリストノードを生成する。引数(void *content)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: malloc()。 */
t_list	*ft_lstnew(void *content) // ft_lstnew関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	t_list	*node; // 変数 node（nodeの作業用値） を宣言する

	node = (t_list *)malloc(sizeof(t_list)); // node に (t_list *)malloc(sizeof(t_list)) の計算結果を代入する
	if (!node) // 条件(!node)が成立する場合に分岐する
		return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
	node->content = content; // node->content に content の計算結果を代入する
	node->next = NULL; // node->next に NULL の計算結果を代入する
	return (node); // 関数を終了し、node を呼び出し元へ返す
} // ここでブロックスコープを終了する

// int	main(void)
// {
// 	char *str = strdup("Hello");
// 	t_list *node = ft_lstnew(str);

// 	if (node && node->content)
// 		printf("Node content: %s\n", (char *)node->content);
// 	else
// 		printf("Node creation failed.\n");

// 	free(node->content);
// 	free(node);
// 	return (0);
// }