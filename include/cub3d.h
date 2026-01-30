/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:16:11 by keitabe           #+#    #+#             */
/*   Updated: 2026/01/30 19:10:10 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error.h"
# include "libft.h"
# include "mlx.h"
# include "keycode.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.1

# define HIT_X_SIDE 0
# define HIT_Y_SIDE 1


enum				e_tex
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
	void *ptr;      /* MLXの画像ハンドル */
	char *addr;     /* ピクセルデータ先頭アドレス */
	int bpp;        /* 1ピクセルあたりのビット数 */
	int line_len;   /* 1行のバイト数 */
	int endian;     /* エンディアン指定 */
	int img_width;  /* 画像の幅 */
	int img_height; /* 画像の高さ */
}					t_img;

/* parse用のフラグ */
typedef struct s_parsed_flags
{
	int				tex[TEX_MAX];
	int				floor;
	int				ceil;
}					t_parsed_flags;

/* .cub設定（パスと色） */
typedef struct s_config
{
	char *tex_path[TEX_MAX]; /* テクスチャパス配列: NO, SO, WE, EA */
	int floor_color;         /* 床色 (0xRRGGBB) */
	int ceil_color;          /* 天井色 (0xRRGGBB) */
	t_parsed_flags	parsed;
}					t_config;

/* マップ情報 */
typedef struct s_map
{
	char **grid; /* マップの2次元配列 */
	int width;   /* マップの幅 */
	int height;  /* マップの高さ */
}					t_map;

/* プレイヤー状態 */
typedef struct s_player
{
	double x;       /* 位置X */
	double y;       /* 位置Y */
	double dir_x;   /* 向きベクトルX */
	double dir_y;   /* 向きベクトルY */
	double plane_x; /* カメラ平面ベクトルX */
	double plane_y; /* カメラ平面ベクトルY */
}					t_player;

/* キー入力状態 */
typedef struct s_input
{
	int key_w;     /* Wキー押下フラグ */
	int key_s;     /* Sキー押下フラグ */
	int key_a;     /* Aキー押下フラグ */
	int key_d;     /* Dキー押下フラグ */
	int key_left;  /* 左回転キー押下フラグ */
	int key_right; /* 右回転キー押下フラグ */
}					t_input;

/* 描画関連 */
typedef struct s_gfx
{
	void *mlx;          /* MLXインスタンス */
	void *win;          /* ウィンドウハンドル */
	t_img screen;       /* 画面バッファ */
	t_img tex[TEX_MAX]; /* 壁テクスチャ NO/SO/WE/EA */
	int win_w;          /* ウィンドウ幅 */
	int win_h;          /* ウィンドウ高さ */
}					t_gfx;

typedef struct s_ray
{
	double camera_x;       /* カメラ空間の正規化x座標 */
	double dir_x;          /* レイ方向ベクトルx成分 */
	double dir_y;          /* レイ方向ベクトルy成分 */
	int map_x;             /* 現在いるマップセルx */
	int map_y;             /* 現在いるマップセルy */
	double side_dist_x;    /* 次のx面までの距離 */
	double side_dist_y;    /* 次のy面までの距離 */
	double delta_dist_x;   /* x面間の距離 */
	double delta_dist_y;   /* y面間の距離 */
	double perp_wall_dist; /* 壁までの垂直距離 */
	int step_x;            /* x方向の進行方向(-1 or 1) */
	int step_y;            /* y方向の進行方向(-1 or 1) */
	int hit;               /* 壁ヒットフラグ */
	int side;              /* ヒットした壁面(0:x面, 1:y面) */
	int wall_height;       /* スクリーン上の壁高さ */
	int draw_start;        /* 壁スライス描画開始y */
	int draw_end;          /* 壁スライス描画終了y */
}					t_ray;

typedef struct s_wall_slice
{
	int screen_x;     /* スクリーンx座標 */
	int screen_y;     /* スクリーンy座標 */
	int tex_x;        /* テクスチャx座標 */
	double tex_y_pos; /* テクスチャyの開始位置 */
	double tex_step;  /* 1ピクセルごとのテクスチャy増分 */
	double wall_hit;  /* 壁ヒット位置(0.0-1.0) */
	t_img *tex;       /* 使用する壁テクスチャ */
}					t_wall_slice;

/* ゲーム全体の状態 */
typedef struct s_game
{
	t_config config; /* 設定データ */
	t_map map;       /* マップデータ */
	t_player player; /* プレイヤー状態 */
	t_input input;   /* 入力状態 */
	t_gfx gfx;       /* グラフィック状態 */
	t_ray ray;       /* レイキャスティング */
	int is_running;  /* ループ継続フラグ */
}					t_game;

// error.c
int					fatal(t_game *g, t_errc code, const char *detail);

// args_validate.c
int					args_validate(t_game *game, int argc, char **argv);

// cleanup.c
void				game_destroy(t_game *game);

// game_init
int					game_init(t_game *g, const char *path);
void				init_gfx(t_gfx *gfx);

// parse_utils.c
void				free_split(char **vec);
char				*skip_space(char *str);

// map_parse.c
int					parse_config_line(t_game *game, char *line, int *in_map);

// read_map.c
int					read_map(t_game *game, const char *path);

// fill_gfx.c
int					fill_gfx(t_game *game);

// draw_map.c
void				draw_map(t_game *game);
void				put_pixel(t_img *img, int x, int y, int color);
void				draw_wall(t_game *game, t_wall_slice *slice);

int					handle_key(int keycode, t_game *game);
int					handle_close(t_game *game);
int					fill_player_config(t_game *game);

void				raycast_frame(t_game *game);
void				dda(t_game *game);
void				calculate_wall(t_game *game);

int					load_textures(t_game *game);
void				draw_column(t_game *game, t_wall_slice *slice);
void				setup_wall_slice(t_game *game, t_wall_slice *slice);

// hooks.c
int					handle_key_press(int keycode, t_game *g);
int					handle_key_release(int keycode, t_game *g);
int					handle_close(t_game *g);

// update.c (もしくは hooks.c に入れてもOK)
int					game_update(t_game *game);

int					game_prepare(t_game *game, char **argv);
void				game_run(t_game *game);

void				set_player_dir(t_player *player, char c);
void				handle_movement(t_game *game);
void				move_player(t_game *game, double dx, double dy);
void				rotate_player(t_game *game, double rot);

int					finalize_map(t_game *game, t_list *lst);

int					check_map_enclosed(t_game *game);

int					parse_floor_and_ceil(t_game *game, int key_len, char key,
						char *rest);

int					handle_texture(char *key, int key_len, t_game *game,
						char *rest);

#endif
