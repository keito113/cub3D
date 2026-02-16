/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:15:44 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/30 18:08:52 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static int	get_map_max_width(t_list *lst); // get_map_max_width() の関数宣言。目的: マップ情報・max・widthを取得する
static int	pad_map_lines(t_list *lst, int width); // pad_map_lines() の関数宣言。目的: マップ行を最大幅まで空白で右埋めする
static void	fill_grid_from_list(char **grid, t_list *lst); // fill_grid_from_list() の関数宣言。目的: grid・from・listを埋めて設定する
static int	fail_map_enclosed(t_game *game, char **grid); // fail_map_enclosed() の関数宣言。目的: マップ囲い検証失敗時に確保済みメモリを解放してエラーを返す

/* 関数概要: finalize_map - マップ情報を確定する。引数(t_game *game, t_list *lst)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: fatal() -> ft_lstsize() -> get_map_max_width() -> pad_map_lines()。 */
int	finalize_map(t_game *game, t_list *lst) // finalize_map関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int		height; // 変数 height（高さ） を宣言する
	int		width; // 変数 width（幅） を宣言する
	char	**grid; // 変数 grid（gridの作業用値） を宣言する

	if (!game->config.parsed.floor) // !game- > config.parsed.floor が成立する場合に分岐する
		return (fatal(game, ERR_PARSE, "Missing floor color")); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	if (!game->config.parsed.ceil) // !game- > config.parsed.ceil が成立する場合に分岐する
		return (fatal(game, ERR_PARSE, "Missing ceiling color")); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	height = ft_lstsize(lst); // height に ft_lstsize(lst) の計算結果を代入する
	if (height == 0) // height == 0 が成立する場合に分岐する
		return (fatal(game, ERR_MAP, "Map missing")); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	width = get_map_max_width(lst); // width に get_map_max_width(lst) の計算結果を代入する
	if (pad_map_lines(lst, width) != 0) // pad_map_lines()が非0（失敗）を返す場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	grid = ft_calloc(height + 1, sizeof(char *)); // grid に ft_calloc(height + 1, sizeof(char *)) の計算結果を代入する
	if (!grid) // 条件(!grid)が成立する場合に分岐する
		return (fatal(game, ERR_ALLOC, NULL)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
	fill_grid_from_list(grid, lst); // fill_grid_from_list() を呼び出して、grid・from・listを埋めて設定する
	game->map.grid = grid; // game->map.grid に grid の計算結果を代入する
	game->map.height = height; // game->map.height に height の計算結果を代入する
	game->map.width = width; // game->map.width に width の計算結果を代入する
	if (check_map_enclosed(game) != 0) // check_map_enclosed()が非0（失敗）を返す場合に分岐する
		return (fail_map_enclosed(game, grid)); // 関数を終了し、fail_map_enclosed(game, grid) を呼び出し元へ返す
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: get_map_max_width - マップ情報・max・widthを取得する。引数(t_list *lst)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen()。 */
static int	get_map_max_width(t_list *lst) // get_map_max_width関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	width; // 変数 width（幅） を宣言する

	width = 0; // width に 0 の計算結果を代入する
	while (lst) // 条件(lst)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		if ((int)ft_strlen(lst->content) > width) // (int)ft_strlen(lst- > content) > width が成立する場合に分岐する
			width = ft_strlen(lst->content); // width に ft_strlen(lst->content) の計算結果を代入する
		lst = lst->next; // lst に lst->next の計算結果を代入する
	} // ここでブロックスコープを終了する
	return (width); // 関数を終了し、width を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: pad_map_lines - マップ行を最大幅まで空白で右埋めする。引数(t_list *lst, int width)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: ft_strlen() -> ft_calloc() -> fatal() -> ft_memset()。 */
static int	pad_map_lines(t_list *lst, int width) // pad_map_lines関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	char	*line; // 変数 line（1行分の文字列） を宣言する
	char	*padded; // 変数 padded（paddedの作業用値） を宣言する
	int		len; // 変数 len（文字列長） を宣言する

	while (lst) // 条件(lst)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		line = lst->content; // line に lst->content の計算結果を代入する
		len = (int)ft_strlen(line); // len に (int)ft_strlen(line) の計算結果を代入する
		padded = ft_calloc(width + 1, sizeof(char)); // padded に ft_calloc(width + 1, sizeof(char)) の計算結果を代入する
		if (!padded) // 条件(!padded)が成立する場合に分岐する
			return (fatal(NULL, ERR_ALLOC, NULL)); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
		ft_memset(padded, ' ', width); // ft_memset() を呼び出して、メモリ領域を指定値で埋める
		if (len > 0) // len > 0 が成立する場合に分岐する
			ft_memcpy(padded, line, len); // ft_memcpy() を呼び出して、メモリ領域をコピーする
		free(line); // free() を呼び出して、対象を解放する
		lst->content = padded; // lst->content に padded の計算結果を代入する
		lst = lst->next; // lst に lst->next の計算結果を代入する
	} // ここでブロックスコープを終了する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する

/* 関数概要: fill_grid_from_list - grid・from・listを埋めて設定する。引数(char **grid, t_list *lst)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	fill_grid_from_list(char **grid, t_list *lst) // fill_grid_from_list関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (lst) // 条件(lst)が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		grid[i++] = lst->content; // grid[i++] に lst->content の計算結果を代入する
		lst = lst->next; // lst に lst->next の計算結果を代入する
	} // ここでブロックスコープを終了する
} // ここでブロックスコープを終了する

/* 関数概要: fail_map_enclosed - マップ囲い検証失敗時に確保済みメモリを解放してエラーを返す。引数(t_game *game, char **grid)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: free() -> fatal()。 */
static int	fail_map_enclosed(t_game *game, char **grid) // fail_map_enclosed関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	game->map.grid = NULL; // game->map.grid に NULL の計算結果を代入する
	game->map.height = 0; // game->map.height に 0 の計算結果を代入する
	game->map.width = 0; // game->map.width に 0 の計算結果を代入する
	free(grid); // free() を呼び出して、対象を解放する
	return (fatal(game, ERR_MAP, "Map not enclosed")); // fatal()でエラー詳細を出力し、その戻り値をそのまま返して終了する
} // ここでブロックスコープを終了する
