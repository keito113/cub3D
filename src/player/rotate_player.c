/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:47:21 by takawagu          #+#    #+#             */
/*   Updated: 2026/01/26 19:48:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" // "cub3d.h"を読み込み、必要な型・定数・関数宣言を参照可能にする

/* 関数概要: rotate_player - プレイヤー状態を回転する。引数(t_game *game, double rot)を受け取り、必要な状態更新を反映して呼び出し元へ戻る。 主な内部呼び出し: cos() -> sin()。 */
void	rotate_player(t_game *game, double rot) // rotate_player関数のシグネチャを定義し、ここから本体処理を記述する
{ // ここからブロックスコープを開始する
	double	old_dir_x; // 変数 old_dir_x（回転前のdir_x） を宣言する
	double	old_plane_x; // 変数 old_plane_x（回転前のplane_x） を宣言する
	double	c; // 変数 c（1文字の判定用値） を宣言する
	double	s; // 変数 s（sの作業用値） を宣言する

	c = cos(rot); // c に cos(rot) の計算結果を代入する
	s = sin(rot); // s に sin(rot) の計算結果を代入する
	old_dir_x = game->player.dir_x; // old_dir_x に game->player.dir_x の計算結果を代入する
	game->player.dir_x = game->player.dir_x * c - game->player.dir_y * s; // game->player.dir_x に game->player.dir_x * c - game->player.dir_y * s の計算結果を代入する
	game->player.dir_y = old_dir_x * s + game->player.dir_y * c; // game->player.dir_y に old_dir_x * s + game->player.dir_y * c の計算結果を代入する
	old_plane_x = game->player.plane_x; // old_plane_x に game->player.plane_x の計算結果を代入する
	game->player.plane_x = game->player.plane_x * c - game->player.plane_y * s; // game->player.plane_x に game->player.plane_x * c - game->player.plane_y * s の計算結果を代入する
	game->player.plane_y = old_plane_x * s + game->player.plane_y * c; // game->player.plane_y に old_plane_x * s + game->player.plane_y * c の計算結果を代入する
} // ここでブロックスコープを終了する
