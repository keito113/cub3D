/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:50:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:29:10 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: void - voidを実行する。引数(t_list *lst, void *(*f)(void *), void (*del)(void *))を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: f() -> ft_lstnew() -> ft_lstclear() -> ft_lstadd_back()。 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) // void関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	t_list	*new_list; // 変数 new_list（new_listの作業用値） を宣言する
	t_list	*new_node; // 変数 new_node（new_nodeの作業用値） を宣言する
	void	*new_content; // 変数 new_content（new_contentの作業用値） を宣言する

	new_list = NULL; // new_list に NULL の計算結果を代入する
	while (lst) // 条件(lst)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		new_content = f(lst->content); // new_content に f(lst->content) の計算結果を代入する
		new_node = ft_lstnew(new_content); // new_node に ft_lstnew(new_content) の計算結果を代入する
		if (!new_node) // 条件(!new_node)が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			ft_lstclear(&new_list, del); // ft_lstclear() を呼び出して、リスト全体を解放する
			return (NULL); // 関数を終了し、NULL を呼び出し元へ返す
		} // ここでブロックスコープを終了する
		ft_lstadd_back(&new_list, new_node); // ft_lstadd_back() を呼び出して、ノードをリスト末尾へ追加する
		lst = lst->next; // lst に lst->next の計算結果を代入する
	} // ここでブロックスコープを終了する
	return (new_list); // 関数を終了し、new_list を呼び出し元へ返す
} // ここでブロックスコープを終了する

// void	*dup_uppercase(void *s)
// {
// 	char	*str;
// 	char	*res;

// 	str = (char *)s;
// 	res = strdup(str);
// 	for (int i = 0; res[i]; i++)
// 		res[i] = toupper(res[i]);
// 	return (res);
// }

// void	free_str(void *s)
// {
// 	free(s);
// }

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	t_list	*upper;

// 	l1 = ft_lstnew(strdup("hello"));
// 	l2 = ft_lstnew(strdup("libft"));
// 	ft_lstadd_back(&l1, l2);
// 	upper = ft_lstmap(l1, dup_uppercase, free_str);
// 	printf("%s\n", (char *)upper->content);       // HELLO
// 	printf("%s\n", (char *)upper->next->content); // LIBFT
// 	ft_lstclear(&l1, free_str);
// 	ft_lstclear(&upper, free_str);
// 	return (0);
// }
