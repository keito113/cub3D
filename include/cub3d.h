/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:16:11 by keitabe           #+#    #+#             */
/*   Updated: 2026/02/10 15:53:46 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H // インクルードガードを開始し、ヘッダ重複展開を防ぐ
# define CUB3D_H // CUB3D_Hマクロを定義する

# include "error.h" // "error.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
# include "keycode.h" // "keycode.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
# include "libft.h" // "libft.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
# include "mlx.h" // "mlx.h"を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <fcntl.h> // <fcntl.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <math.h> // <math.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stddef.h> // <stddef.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <stdlib.h> // <stdlib.h>を読み込み、必要な型・定数・関数宣言を参照可能にする
# include <unistd.h> // <unistd.h>を読み込み、必要な型・定数・関数宣言を参照可能にする

# define MOVE_SPEED 0.04 // MOVE_SPEEDマクロを定義する
# define ROT_SPEED 0.04 // ROT_SPEEDマクロを定義する

# define HIT_X_SIDE 0 // HIT_X_SIDEマクロを定義する
# define HIT_Y_SIDE 1 // HIT_Y_SIDEマクロを定義する

enum				e_tex // 式 `enum				e_tex` を評価して処理を進める
{ // ここからブロックスコープを開始する
	TEX_NO = 0, // 関数呼び出し引数をこの行で追加し、次行へ続ける
	TEX_SO, // 関数呼び出し引数をこの行で追加し、次行へ続ける
	TEX_WE, // 関数呼び出し引数をこの行で追加し、次行へ続ける
	TEX_EA, // 関数呼び出し引数をこの行で追加し、次行へ続ける
	TEX_MAX // 式 `TEX_MAX` を評価して処理を進める
}; // 文 `};` を実行する

/* MLX画像1枚分の情報 */
typedef struct s_img // 式 `typedef struct s_img` を評価して処理を進める
{ // ここからブロックスコープを開始する
	void *ptr;      /* MLXの画像ハンドル */
	char *addr;     /* ピクセルデータ先頭アドレス */
	int bpp;        /* 1ピクセルあたりのビット数 */
	int line_len;   /* 1行のバイト数 */
	int endian;     /* エンディアン指定 */
	int img_width;  /* 画像の幅 */
	int img_height; /* 画像の高さ */
}					t_img; // 変数 t_img（t_imgの作業用値） を宣言する

/* parse用のフラグ */
typedef struct s_parsed_flags // 式 `typedef struct s_parsed_flags` を評価して処理を進める
{ // ここからブロックスコープを開始する
	int				tex[TEX_MAX]; // 変数 tex（texの作業用値） を宣言する
	int				floor; // 変数 floor（floorの作業用値） を宣言する
	int				ceil; // 変数 ceil（ceilの作業用値） を宣言する
}					t_parsed_flags; // 変数 t_parsed_flags（t_parsed_flagsの作業用値） を宣言する

/* .cub設定（パスと色） */
typedef struct s_config // 式 `typedef struct s_config` を評価して処理を進める
{ // ここからブロックスコープを開始する
	char *tex_path[TEX_MAX]; /* テクスチャパス配列: NO, SO, WE, EA */
	int floor_color;         /* 床色 (0xRRGGBB) */
	int ceil_color;          /* 天井色 (0xRRGGBB) */
	t_parsed_flags	parsed; // 変数 parsed（parsedの作業用値） を宣言する
}					t_config; // 変数 t_config（t_configの作業用値） を宣言する

/* マップ情報 */
typedef struct s_map // 式 `typedef struct s_map` を評価して処理を進める
{ // ここからブロックスコープを開始する
	char **grid; /* マップの2次元配列 */
	int width;   /* マップの幅 */
	int height;  /* マップの高さ */
}					t_map; // 変数 t_map（t_mapの作業用値） を宣言する

/* プレイヤー状態 */
typedef struct s_player // 式 `typedef struct s_player` を評価して処理を進める
{ // ここからブロックスコープを開始する
	double x;       /* 位置X */
	double y;       /* 位置Y */
	double dir_x;   /* 向きベクトルX */
	double dir_y;   /* 向きベクトルY */
	double plane_x; /* カメラ平面ベクトルX */
	double plane_y; /* カメラ平面ベクトルY */
}					t_player; // 変数 t_player（t_playerの作業用値） を宣言する

/* キー入力状態 */
typedef struct s_input // 式 `typedef struct s_input` を評価して処理を進める
{ // ここからブロックスコープを開始する
	int key_w;     /* Wキー押下フラグ */
	int key_s;     /* Sキー押下フラグ */
	int key_a;     /* Aキー押下フラグ */
	int key_d;     /* Dキー押下フラグ */
	int key_left;  /* 左回転キー押下フラグ */
	int key_right; /* 右回転キー押下フラグ */
}					t_input; // 変数 t_input（t_inputの作業用値） を宣言する

/* 描画関連 */
typedef struct s_gfx // 式 `typedef struct s_gfx` を評価して処理を進める
{ // ここからブロックスコープを開始する
	void *mlx;          /* MLXインスタンス */
	void *win;          /* ウィンドウハンドル */
	t_img screen;       /* 画面バッファ */
	t_img tex[TEX_MAX]; /* 壁テクスチャ NO/SO/WE/EA */
	int win_w;          /* ウィンドウ幅 */
	int win_h;          /* ウィンドウ高さ */
}					t_gfx; // 変数 t_gfx（t_gfxの作業用値） を宣言する

typedef struct s_ray // 式 `typedef struct s_ray` を評価して処理を進める
{ // ここからブロックスコープを開始する
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
}					t_ray; // 変数 t_ray（t_rayの作業用値） を宣言する

typedef struct s_wall_slice // 式 `typedef struct s_wall_slice` を評価して処理を進める
{ // ここからブロックスコープを開始する
	int screen_x;     /* スクリーンx座標 */
	int screen_y;     /* スクリーンy座標 */
	int tex_x;        /* テクスチャx座標 */
	double tex_y_pos; /* テクスチャyの開始位置 */
	double tex_step;  /* 1ピクセルごとのテクスチャy増分 */
	double wall_hit;  /* 壁ヒット位置(0.0-1.0) */
	t_img *tex;       /* 使用する壁テクスチャ */
}					t_wall_slice; // 変数 t_wall_slice（t_wall_sliceの作業用値） を宣言する

/* ゲーム全体の状態 */
typedef struct s_game // 式 `typedef struct s_game` を評価して処理を進める
{ // ここからブロックスコープを開始する
	t_config config; /* 設定データ */
	t_map map;       /* マップデータ */
	t_player player; /* プレイヤー状態 */
	t_input input;   /* 入力状態 */
	t_gfx gfx;       /* グラフィック状態 */
	t_ray ray;       /* レイキャスティング */
	int is_running;  /* ループ継続フラグ */
}					t_game; // 変数 t_game（t_gameの作業用値） を宣言する

// error.c
int					fatal(t_game *g, t_errc code, const char *detail); // fatal() の関数宣言。目的: エラー内容を出力して失敗コードを返す

// args_validate.c
int					args_validate(t_game *game, int argc, char **argv); // args_validate() の関数宣言。目的: 起動引数の個数、拡張子が .cub かどうか、対象ファイルを開けるかを検証する

// cleanup.c
void				game_destroy(t_game *game); // game_destroy() の関数宣言。目的: 確保済み画像・ウィンドウ・マップ・設定メモリを解放する

// game_init
int					game_init(t_game *g, const char *path); // game_init() の関数宣言。目的: ゲーム状態を初期化する
void				init_gfx(t_gfx *gfx); // init_gfx() の関数宣言。目的: 描画コンテキストを初期化する

// parse_utils.c
void				free_split(char **vec); // free_split() の関数宣言。目的: splitを解放する
char				*skip_space(char *str); // skip_space() の関数宣言。目的: 文字列先頭の空白を読み飛ばした位置を返す

// map_parse.c
int					parse_config_line(t_game *game, char *line, int *in_map); // parse_config_line() の関数宣言。目的: 設定・lineを解析する

// read_map.c
int					read_map(t_game *game, const char *path); // read_map() の関数宣言。目的: マップファイルを読み込んで設定/マップ情報を構築する

// fill_gfx.c
int					fill_gfx(t_game *game); // fill_gfx() の関数宣言。目的: 描画コンテキストを埋めて設定する

// draw_map.c
void				draw_map(t_game *game); // draw_map() を呼び出して、マップ情報を描画する
void				put_pixel(t_img *img, int x, int y, int color); // put_pixel() の関数宣言。目的: 画像バッファの指定座標へ1ピクセル書き込む
void				draw_wall(t_game *game, t_wall_slice *slice); // draw_wall() の関数宣言。目的: 壁を描画する

int					handle_key(int keycode, t_game *game); // handle_key() を呼び出して、キーコードに応じて入力状態を更新する
int					handle_close(t_game *game); // handle_close() の関数宣言。目的: ウィンドウクローズ時に終了処理を実行する
int					fill_player_config(t_game *game); // fill_player_config() の関数宣言。目的: プレイヤー状態・設定を埋めて設定する

void				raycast_frame(t_game *game); // raycast_frame() の関数宣言。目的: 画面横方向を走査して各列のレイ計算と壁描画を行う
void				dda(t_game *game); // dda() の関数宣言。目的: レイが壁に当たるまで DDA でマップセルを1マスずつ進める
void				calculate_wall(t_game *game); // calculate_wall() の関数宣言。目的: 壁を計算する

int					load_textures(t_game *game); // load_textures() の関数宣言。目的: texturesを読み込む
void				draw_column(t_game *game, t_wall_slice *slice); // draw_column() の関数宣言。目的: columnを描画する
void				setup_wall_slice(t_game *game, t_wall_slice *slice); // setup_wall_slice() の関数宣言。目的: 壁・sliceを事前準備を行う

// hooks.c
int					handle_key_press(int keycode, t_game *g); // handle_key_press() の関数宣言。目的: キー押下イベントを受けて入力フラグを立てる
int					handle_key_release(int keycode, t_game *g); // handle_key_release() の関数宣言。目的: キー離上イベントを受けて入力フラグを下ろす
int					handle_close(t_game *g); // handle_close() の関数宣言。目的: ウィンドウクローズ時に終了処理を実行する

// update.c (もしくは hooks.c に入れてもOK)
int					game_update(t_game *game); // game_update() の関数宣言。目的: 1フレーム分の移動更新とレイキャスト描画を行って画面へ転送する

int					game_prepare(t_game *game, char **argv); // game_prepare() の関数宣言。目的: ゲーム開始前に初期化・マップ読み込み・描画リソース準備を順番に完了させる
void				game_run(t_game *game); // game_run() の関数宣言。目的: フック登録後にMLXメインループを開始する

void				set_player_dir(t_player *player, char c); // set_player_dir() の関数宣言。目的: プレイヤー状態・dirを設定する
void				handle_movement(t_game *game); // handle_movement() の関数宣言。目的: 入力フラグに応じて移動/回転を反映する
void				move_player(t_game *game, double dx, double dy); // move_player() の関数宣言。目的: プレイヤー状態を移動する
void				rotate_player(t_game *game, double rot); // rotate_player() の関数宣言。目的: プレイヤー状態を回転する

int					finalize_map(t_game *game, t_list *lst); // finalize_map() の関数宣言。目的: マップ情報を確定する

int					check_map_enclosed(t_game *game); // check_map_enclosed() の関数宣言。目的: マップ情報・enclosedを検証する

int					parse_floor_and_ceil(t_game *game, int key_len, char key, // 関数呼び出し引数をこの行で追加し、次行へ続ける
						char *rest); // 文 `char *rest);` を実行する

int					handle_texture(char *key, int key_len, t_game *game, // 関数呼び出し引数をこの行で追加し、次行へ続ける
						char *rest); // 文 `char *rest);` を実行する

#endif // インクルードガード/条件コンパイルを終了する
