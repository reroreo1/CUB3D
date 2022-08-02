/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:58:57 by rezzahra          #+#    #+#             */
/*   Updated: 2022/08/02 12:27:40 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define N 4.71239
#define W 0
#define E 3.14159
#define S 1.5708
#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123

typedef struct s_map{
	int height;
	int width;
	char map[8][8];
} t_map;

typedef struct s_point{
	double x;
	double y;
	double pov;
	double fov;
} t_point;
typedef struct s_rays{
	double *distance;
	int n_rays;
	double teta;//angle between rays
	t_point pointofdistance;
	int thickness;
} t_rays;

typedef struct s_mlx{
	void *mlx_ptr;
	void *win_ptr;
	int L;
	int l;
	t_map *map;
	t_point *player;
	void *img;
	char *addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	double tile_length;
	double tile_height;
	t_rays *rays;
	int v;
} t_mlx;


void drawtile(t_mlx *mlx, int x, int y, int color);
void drawmap(t_mlx *mlx);
void drawplayer(t_mlx *mlx);
t_point dda_draw_line(t_mlx *mlx,double bx, double by);
// void drawpov(t_mlx *mlx);
void my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int update(t_mlx *w);
int udrl(int k,t_mlx *w);
void events(t_mlx *w);
void my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int check_player_pos(t_mlx mlx,double x,double y);
void print_distance(t_mlx *mlx);
void floor_ceiling(t_mlx *mlx);
void raycasting(t_mlx *mlx);
void draw_strip_wall(t_mlx *mlx);
double calculate_distance(double x1,double y1,double x2,double y2);
