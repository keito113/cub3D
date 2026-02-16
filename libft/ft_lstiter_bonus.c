/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:44:51 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:27:59 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: void - voidを実行する。引数(t_list *lst, void (*f)(void *))を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: f()。 */
void	ft_lstiter(t_list *lst, void (*f)(void *)) // void関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (!lst || !f) // 条件(!lst)が成立する または 条件(!f)が成立する場合に分岐する
		return ; // この時点で関数を終了して呼び出し元へ戻る
	while (lst) // 条件(lst)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		f(lst->content); // f() を呼び出して、fを実行する
		lst = lst->next; // lst に lst->next の計算結果を代入する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

// #include <ctype.h>
// #include <string.h>

// void	to_upper_first_letter(void *content)
// {
// 	char	*str;

// 	str = (char *)content;
// 	if (str && str[0])
// 		str[0] = toupper(str[0]);
// }

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew(strdup("hello"));
// 	t_list *n2 = ft_lstnew(strdup("world"));
// 	t_list *n3 = ft_lstnew(strdup("list"));

// 	n1->next = n2;
// 	n2->next = n3;

// 	ft_lstiter(n1, to_upper_first_letter);

// 	printf("%s\n", (char *)n1->content);
// 	printf("%s\n", (char *)n2->content);
// 	printf("%s\n", (char *)n3->content);

// 	ft_lstclear(&n1, free);
// 	return (0);
// }