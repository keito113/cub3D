/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:16:11 by keitabe           #+#    #+#             */
/*   Updated: 2025/12/27 15:01:24 by takawagu         ###   ########.fr       */
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
#include <stdlib.h>
#include <X11/keysym.h>

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
	void		*ptr;			/* MLXの画像ハンドル */
	char		*addr;			/* ピクセルデータ先頭アドレス */
	int			bpp;			/* 1ピクセルあたりのビット数 */
	int			line_len;		/* 1行のバイト数 */
	int			endian;			/* エンディアン指定 */
	int			w;				/* 画像の幅 */
	int			h;				/* 画像の高さ */
}				t_img;

/* .cub設定（パスと色） */
typedef struct s_config
{
	char		*tex_path[TEX_MAX];	/* テクスチャパス配列: NO, SO, WE, EA */
	int			floor_color;		/* 床色 (0xRRGGBB) */
	int			ceil_color;			/* 天井色 (0xRRGGBB) */
	int			parsed_mask;		/* 取得済みフラグ用ビットマスク */
}				t_config;

/* マップ情報 */
typedef struct s_map
{
	char		**grid;			/* マップの2次元配列 */
	int			width;			/* マップの幅 */
	int			height;			/* マップの高さ */
}				t_map;

/* プレイヤー状態 */
typedef struct s_player
{
	double		x;				/* 位置X */
	double		y;				/* 位置Y */
	double		dir_x;			/* 向きベクトルX */
	double		dir_y;			/* 向きベクトルY */
	double		plane_x;		/* カメラ平面ベクトルX */
	double		plane_y;		/* カメラ平面ベクトルY */
}				t_player;

/* キー入力状態 */
typedef struct s_input
{
	int			key_w;			/* Wキー押下フラグ */
	int			key_s;			/* Sキー押下フラグ */
	int			key_a;			/* Aキー押下フラグ */
	int			key_d;			/* Dキー押下フラグ */
	int			key_left;		/* 左回転キー押下フラグ */
	int			key_right;		/* 右回転キー押下フラグ */
}				t_input;

/* 描画関連 */
typedef struct s_gfx
{
	void		*mlx;			/* MLXインスタンス */
	void		*win;			/* ウィンドウハンドル */
	t_img		screen;			/* 画面バッファ */
	t_img		tex[TEX_MAX];	/* 壁テクスチャ NO/SO/WE/EA */
	int			win_w;			/* ウィンドウ幅 */
	int			win_h;			/* ウィンドウ高さ */
}				t_gfx;

/* ゲーム全体の状態 */
typedef struct s_game
{
	t_config	config;		/* 設定データ */
	t_map		map;		/* マップデータ */
	t_player	player;		/* プレイヤー状態 */
	t_input		input;		/* 入力状態 */
	t_gfx		gfx;		/* グラフィック状態 */
	int			is_running;	/* ループ継続フラグ */
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
char			*skip_ws(char *s);

// map_parse.c
int				parse_id_line(t_game *g, char *line, int *in_map);

// read_map.c
int				parse_file(t_game *g, const char *path);

// gfx_init.c
int		gfx_init(t_game *g);

// draw_map.c
void	draw_map(t_game *g);

int	handle_key(int keycode, t_game *g);
int	handle_close(t_game *g);



#endif

