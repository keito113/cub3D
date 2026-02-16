/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:02:51 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/16 18:44:44 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

static void	set_player_dir_north(t_player *player); // set_player_dir_north() の関数宣言。目的: プレイヤー状態・dir・northを設定する
static void	set_player_dir_south(t_player *player); // set_player_dir_south() の関数宣言。目的: プレイヤー状態・dir・southを設定する
static void	set_player_dir_east(t_player *player); // set_player_dir_east() の関数宣言。目的: プレイヤー状態・dir・eastを設定する
static void	set_player_dir_west(t_player *player); // set_player_dir_west() の関数宣言。目的: プレイヤー状態・dir・westを設定する

/* 関数概要: set_player_dir - プレイヤー状態・dirを設定する。引数(t_player *player, char c)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: set_player_dir_north() -> set_player_dir_south() -> set_player_dir_east() -> set_player_dir_west()。 */
void	set_player_dir(t_player *player, char c) // set_player_dir関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	if (c == 'N') // c == 'N' が成立する場合に分岐する
		set_player_dir_north(player); // set_player_dir_north() を呼び出して、プレイヤー状態・dir・northを設定する
	else if (c == 'S') // c == 'S' が成立する場合に分岐する
		set_player_dir_south(player); // set_player_dir_south() を呼び出して、プレイヤー状態・dir・southを設定する
	else if (c == 'E') // c == 'E' が成立する場合に分岐する
		set_player_dir_east(player); // set_player_dir_east() を呼び出して、プレイヤー状態・dir・eastを設定する
	else if (c == 'W') // c == 'W' が成立する場合に分岐する
		set_player_dir_west(player); // set_player_dir_west() を呼び出して、プレイヤー状態・dir・westを設定する
} // ここでブロックスコープを終了する

/* 関数概要: set_player_dir_north - プレイヤー状態・dir・northを設定する。引数(t_player *player)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	set_player_dir_north(t_player *player) // set_player_dir_north関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	player->dir_x = 0.0; // player->dir_x に 0.0 の計算結果を代入する
	player->dir_y = -1.0; // player->dir_y に -1.0 の計算結果を代入する
	player->plane_x = 0.66; // player->plane_x に 0.66 の計算結果を代入する
	player->plane_y = 0.0; // player->plane_y に 0.0 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: set_player_dir_south - プレイヤー状態・dir・southを設定する。引数(t_player *player)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	set_player_dir_south(t_player *player) // set_player_dir_south関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	player->dir_x = 0.0; // player->dir_x に 0.0 の計算結果を代入する
	player->dir_y = 1.0; // player->dir_y に 1.0 の計算結果を代入する
	player->plane_x = -0.66; // player->plane_x に -0.66 の計算結果を代入する
	player->plane_y = 0.0; // player->plane_y に 0.0 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: set_player_dir_east - プレイヤー状態・dir・eastを設定する。引数(t_player *player)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	set_player_dir_east(t_player *player) // set_player_dir_east関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	player->dir_x = 1.0; // player->dir_x に 1.0 の計算結果を代入する
	player->dir_y = 0.0; // player->dir_y に 0.0 の計算結果を代入する
	player->plane_x = 0.0; // player->plane_x に 0.0 の計算結果を代入する
	player->plane_y = 0.66; // player->plane_y に 0.66 の計算結果を代入する
} // ここでブロックスコープを終了する

/* 関数概要: set_player_dir_west - プレイヤー状態・dir・westを設定する。引数(t_player *player)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 */
static void	set_player_dir_west(t_player *player) // set_player_dir_west関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	player->dir_x = -1.0; // player->dir_x に -1.0 の計算結果を代入する
	player->dir_y = 0.0; // player->dir_y に 0.0 の計算結果を代入する
	player->plane_x = 0.0; // player->plane_x に 0.0 の計算結果を代入する
	player->plane_y = -0.66; // player->plane_y に -0.66 の計算結果を代入する
} // ここでブロックスコープを終了する
