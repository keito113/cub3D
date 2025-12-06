/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:16:11 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/06 16:50:30 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <unistd.h>

enum			e_tex
{
	TEX_NO = 0,
	TEX_SO,
	TEX_WE,
	TEX_EA,
	TEX_MAX
};

/* MLX画像1枚分の情報 */
typedef struct s_img
{
	/* MLXの画像ハンドル */
	void		*ptr;
	/* ピクセルデータ先頭アドレス */
	char		*addr;
	/* 1ピクセルあたりのビット数 */
	int			bpp;
	/* 1行のバイト数 */
	int			line_len;
	/* エンディアン指定 */
	int			endian;
	/* 画像の幅 */
	int			w;
	/* 画像の高さ */
	int			h;
}				t_img;

/* .cub設定（パスと色） */
typedef struct s_config
{
	/* テクスチャパス配列: NO, SO, WE, EA */
	char		*tex_path[TEX_MAX];
	/* 床色 (0xRRGGBB) */
	int			floor_color;
	/* 天井色 (0xRRGGBB) */
	int			ceil_color;
	/* 取得済みフラグ用ビットマスク */
	int			parsed_mask;
}				t_config;

/* マップ情報 */
typedef struct s_map
{
	/* マップの2次元配列 */
	char		**grid;
	/* マップの幅 */
	int			width;
	/* マップの高さ */
	int			height;
}				t_map;

/* プレイヤー状態 */
typedef struct s_player
{
	/* 位置X */
	double		x;
	/* 位置Y */
	double		y;
	/* 向きベクトルX */
	double		dir_x;
	/* 向きベクトルY */
	double		dir_y;
	/* カメラ平面ベクトルX */
	double		plane_x;
	/* カメラ平面ベクトルY */
	double		plane_y;
}				t_player;

/* キー入力状態 */
typedef struct s_input
{
	/* Wキー押下フラグ */
	int			key_w;
	/* Sキー押下フラグ */
	int			key_s;
	/* Aキー押下フラグ */
	int			key_a;
	/* Dキー押下フラグ */
	int			key_d;
	/* 左回転キー押下フラグ */
	int			key_left;
	/* 右回転キー押下フラグ */
	int			key_right;
}				t_input;

/* 描画関連 */
typedef struct s_gfx
{
	/* MLXインスタンス */
	void		*mlx;
	/* ウィンドウハンドル */
	void		*win;
	/* 画面バッファ */
	t_img		screen;
	/* 壁テクスチャ NO/SO/WE/EA */
	t_img		tex[TEX_MAX];
	/* ウィンドウ幅 */
	int			win_w;
	/* ウィンドウ高さ */
	int			win_h;
}				t_gfx;

/* ゲーム全体の状態 */
typedef struct s_game
{
	/* 設定データ */
	t_config	config;
	/* マップデータ */
	t_map		map;
	/* プレイヤー状態 */
	t_player	player;
	/* 入力状態 */
	t_input		input;
	/* グラフィック状態 */
	t_gfx		gfx;
	/* ループ継続フラグ */
	int			is_running;
}				t_game;

// error.c
int				fatal(t_game *g, t_errc code, const char *detail);

// args_validate.c
int				args_validate(t_game *g, int ac, char **av);

// cleanup.c
void			game_destroy(t_game *g);

// game_init.c
int				game_init(t_game *g, const char *path);

// map_parse_utils.c
int				parse_color(int *out, char *s);

#endif
