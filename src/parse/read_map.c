/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:48:36 by keitabe           #+#    #+#             */
/*   Updated: 2026/02/10 16:11:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: push_line - マップ行をリスト末尾へ追加する。引数(t_list **lst, char *str)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_lstnew() -> free() -> fatal() -> ft_lstadd_back()。 */
static int	push_line(t_list **lst, char *str) // push_line関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	t_list	*node; // 変数 node（nodeの作業用値） を宣言する

	node = ft_lstnew(str); // node に ft_lstnew(str) の計算結果を代入する
	if (!node) // 条件(!node)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		free(str); // free() を呼び出して、対象を解放する
		return (fatal(NULL, ERR_ALLOC, NULL)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	} // ここでブロックスコープを終了する
	ft_lstadd_back(lst, node); // ft_lstadd_back() を呼び出して、ノードをリスト末尾へ追加する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: handle_line - 読み込んだ1行を設定行/マップ行として振り分けて処理する。引数(t_game *game, char *line, int *in_map, t_list **map)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> push_line() -> parse_config_line() -> free()。 */
static int	handle_line(t_game *game, char *line, int *in_map, t_list **map) // handle_line関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	len; // 変数 len（文字列長） を宣言する

	len = ft_strlen(line); // len に ft_strlen(line) の計算結果を代入する
	if (len > 0 && line[len - 1] == '\n') // len > 0 が成立する かつ line[len - 1] == '\n' が成立する場合に分岐する
		line[len - 1] = '\0'; // line[len - 1] に '\0' の計算結果を代入する
	if (*in_map) // 条件(*in_map)が成立する場合に分岐する
		return (push_line(map, line)); // 関数を終了し、push_line(map, line) を呼び出し元へ返す
	if (parse_config_line(game, line, in_map) == 0) // parse_config_line()が0（成功/継続条件）を返す場合に分岐する
	{ // ここからブロックスコープを開始する
		if (*in_map) // 条件(*in_map)が成立する場合に分岐する
			return (push_line(map, line)); // 関数を終了し、push_line(map, line) を呼び出し元へ返す
		free(line); // free() を呼び出して、対象を解放する
		return (0); // 関数を終了し、0 を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	free(line); // free() を呼び出して、対象を解放する
	return (fatal(game, ERR_PARSE, "Invalid line")); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
} // ここでブロックスコープを終了する

/* 関数概要: cleanup_err - errを後始末する。引数(int fd, t_list **map)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_lstclear() -> get_next_line() -> free() -> close()。 */
static int	cleanup_err(int fd, t_list **map) // cleanup_err関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*line; // 変数 line（1行分の文字列） を宣言する

	if (map) // 条件(map)が成立する場合に分岐する
		ft_lstclear(map, free); // ft_lstclear() を呼び出して、リスト全体を解放する
	if (fd >= 0) // fd >= 0 が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		line = get_next_line(fd); // line に get_next_line(fd) の計算結果を代入する
		while (line) // 条件(line)が成立する場合に分岐する
		{ // ここからブロックスコープを開始する
			free(line); // free() を呼び出して、対象を解放する
			line = get_next_line(fd); // line に get_next_line(fd) の計算結果を代入する
		} // ここでブロックスコープを終了する
		close(fd); // fd をcloseしてファイルディスクリプタを解放する
	} // ここでブロックスコープを終了する
	return (1); // 関数を終了し、1 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: free_list_nodes - list・nodesを解放する。引数(t_list **lst)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: free()。 */
static void	free_list_nodes(t_list **lst) // free_list_nodes関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	t_list	*tmp; // 変数 tmp（tmpの作業用値） を宣言する

	while (lst && *lst) // 条件(lst)が成立する かつ 条件(*lst)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		tmp = (*lst)->next; // tmp に (*lst)->next の計算結果を代入する
		free(*lst); // free() を呼び出して、対象を解放する
		*lst = tmp; // 前行から続く式に演算を連結して計算を完成させる
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: read_map - マップファイルを読み込んで設定/マップ情報を構築する。引数(t_game *game, const char *path)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: open() -> fatal() -> get_next_line() -> handle_line()。 */
int	read_map(t_game *game, const char *path) // read_map関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		fd; // 変数 fd（ファイルディスクリプタ） を宣言する
	char	*line; // 変数 line（1行分の文字列） を宣言する
	int		in_map; // 変数 in_map（in_mapの作業用値） を宣言する
	t_list	*map; // 変数 map（mapの作業用値） を宣言する

	fd = open(path, O_RDONLY); // fd に open(path, O_RDONLY) の計算結果を代入する
	if (fd < 0) // open結果fdが負値でファイルを開けない場合に分岐する
		return (fatal(game, ERR_OPEN, path)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	in_map = 0; // in_map に 0 の計算結果を代入する
	map = NULL; // map に NULL の計算結果を代入する
	line = get_next_line(fd); // line に get_next_line(fd) の計算結果を代入する
	while (line) // 条件(line)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if (handle_line(game, line, &in_map, &map)) // handle_line()で読み込んだ1行を設定行/マップ行として振り分けて処理し、その戻り値が非0（真）なら分岐する
			return (cleanup_err(fd, &map)); // 関数を終了し、cleanup_err(fd, &map) を呼び出し元へ返す
		line = get_next_line(fd); // line に get_next_line(fd) の計算結果を代入する
	} // ここでブロックスコープを終了する
	close(fd); // fd をcloseしてファイルディスクリプタを解放する
	if (finalize_map(game, map) != 0) // finalize_map()が非0（失敗）を返す場合に分岐する
	{ // ここからブロックスコープを開始する
		ft_lstclear(&map, free); // ft_lstclear() を呼び出して、リスト全体を解放する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	} // ここでブロックスコープを終了する
	free_list_nodes(&map); // free_list_nodes() を呼び出して、list・nodesを解放する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
