/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:24:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:28:59 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
#include <stdlib.h> // <stdlib.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: void - voidを実行する。引数(t_list *lst, void (*del)(void *))を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: del() -> free()。 */
void	ft_lstdelone(t_list *lst, void (*del)(void *)) // void関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (!lst || !del) // 条件(!lst)が成立する または 条件(!del)が成立する場合に分岐する
		return ; // この時点で関数を終了して呼び出し元へ戻る
	del(lst->content); // del() を呼び出して、delを実行する
	free(lst); // free() を呼び出して、対象を解放する
} // ここでブロックスコープを終了する

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	char	*str;
// 	t_list	*node;

// 	str = malloc(6);
// 	if (!str)
// 		return (1);
// 	str[0] = 'H';
// 	str[1] = 'e';
// 	str[2] = 'l';
// 	str[3] = 'l';
// 	str[4] = 'o';
// 	str[5] = '\0';
// 	node = ft_lstnew(str);
// 	printf("Before delete: %s\n", (char *)node->content);
// 	ft_lstdelone(node, del);
// 	printf("Node deleted successfully.\n");
// 	return (0);
// }
