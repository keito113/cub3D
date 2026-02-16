/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:46:17 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/17 18:18:36 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: config_init - 設定構造体の初期値をセットする。引数(t_config *config)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	config_init(t_config *config) // config_init関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	int	i; // 変数 i（ループ用インデックス） を宣言する

	i = 0; // i に 0 の計算結果を代入する
	while (i < TEX_MAX) // i < TEX_MAX が成立する場合に分岐する
	{ // ここからブロックスコープを開始する
		config->tex_path[i] = NULL; // config->tex_path[i] に NULL の計算結果を代入する
		config->parsed.tex[i] = 0; // config->parsed.tex[i] に 0 の計算結果を代入する
		i++; // 文 `i++;` を実行する
	} // ここでブロックスコープを終了する
	config->floor_color = -1; // config->floor_color に -1 の計算結果を代入する
	config->ceil_color = -1; // config->ceil_color に -1 の計算結果を代入する
	config->parsed.floor = 0; // config->parsed.floor に 0 の計算結果を代入する
	config->parsed.ceil = 0; // config->parsed.ceil に 0 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: map_init - マップ構造体の初期値をセットする。引数(t_map *map)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	map_init(t_map *map) // map_init関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	map->grid = NULL; // map->grid に NULL の計算結果を代入する
	map->width = 0; // map->width に 0 の計算結果を代入する
	map->height = 0; // map->height に 0 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: player_init - プレイヤー構造体の初期値をセットする。引数(t_player *player)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	player_init(t_player *player) // player_init関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	player->x = 0.0; // player->x に 0.0 の計算結果を代入する
	player->y = 0.0; // player->y に 0.0 の計算結果を代入する
	player->dir_x = 0.0; // player->dir_x に 0.0 の計算結果を代入する
	player->dir_y = 0.0; // player->dir_y に 0.0 の計算結果を代入する
	player->plane_x = 0.0; // player->plane_x に 0.0 の計算結果を代入する
	player->plane_y = 0.0; // player->plane_y に 0.0 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: input_init - 入力状態構造体の初期値をセットする。引数(t_input *input)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	input_init(t_input *input) // input_init関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	input->key_w = 0; // input->key_w に 0 の計算結果を代入する
	input->key_s = 0; // input->key_s に 0 の計算結果を代入する
	input->key_a = 0; // input->key_a に 0 の計算結果を代入する
	input->key_d = 0; // input->key_d に 0 の計算結果を代入する
	input->key_left = 0; // input->key_left に 0 の計算結果を代入する
	input->key_right = 0; // input->key_right に 0 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: game_init - ゲーム状態を初期化する。引数(t_game *game, const char *path)を受け取り、成功/失敗または計算結果を戻り値で返す。 主な内部呼び出し: config_init() -> map_init() -> player_init() -> input_init()。 */
int	game_init(t_game *game, const char *path) // game_init関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (!game || !path) // 条件(!game)が成立する または 条件(!path)が成立する場合に分岐する
		return (1); // 関数を終了し、1 を呼び出し元へ返す
	config_init(&game->config); // config_init() を呼び出して、設定構造体の初期値をセットする
	map_init(&game->map); // map_init() を呼び出して、マップ構造体の初期値をセットする
	player_init(&game->player); // player_init() を呼び出して、プレイヤー構造体の初期値をセットする
	input_init(&game->input); // input_init() を呼び出して、入力状態構造体の初期値をセットする
	init_gfx(&game->gfx); // init_gfx() を呼び出して、描画コンテキストを初期化する
	game->is_running = 1; // game->is_running に 1 の計算結果を代入する
	(void)path; // 文 `(void)path;` を実行する
	return (0); // 関数を終了し、0 を呼び出し元へ返す
} // ここでブロックスコープを終了する
