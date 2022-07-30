/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:16:15 by rezzahra          #+#    #+#             */
/*   Updated: 2022/07/30 05:46:25 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drawtile(t_mlx *mlx, int x, int y, int color){
	int i;
	int j;

	i = x * mlx->L / mlx->map->width;
	j = y * mlx->l / mlx->map->height;			 	
	while (i < (x + 1)* mlx->L / mlx->map->width - 1){
		j = y * mlx->l / mlx->map->height;
		while (j < (y + 1) * mlx->l / mlx->map->height - 1){
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, color);
			j++;
		}
		i++;
	}
}
void drawmap(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			if (mlx->map->map[i][j] == '1')
				drawtile(mlx, i, j, 0x00FF00);
			j++;
		}
		i++;
	}
}

void drawplayer(t_mlx *mlx){
	double o = 0;
	double r = 0;
	double x = 0;
	double y = 0;
	while(r < 20)
	{
		o = 0;
		while(o < 360){
			x = r * cos(o) + mlx->player->x;
			y = r * sin(o) + mlx->player->y;
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFFFFFF);
			o+=0.01;
		}
		r++;
	} 
}

void dda_draw_line(t_mlx mlx,double bx, double by)
{
	double dx;
	double dy, s;
	double i = -1;

	dx = bx - mlx.player->x;
	dy = by - mlx.player->y;

	if (fabs(dx) > fabs(dy))
		s = fabs(dx);
	else
		s = fabs(dy);
	while (++i < s)
	{
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, mlx.player->x, mlx.player->y, 0Xffffff);
		mlx.player->x += dx / s;
		mlx.player->y += dy / s;
	}
}
void drawpof(t_mlx *mlx){
	if (mlx->player->pof == N)
		dda_draw_line(*mlx, mlx->player->x, mlx->player->y - 1);
	else if (mlx->player->pof == W)
		drawplayer(mlx);
	else if (mlx->player->pof == E)
		drawplayer(mlx);
	else if (mlx->player->pof == S)
		drawplayer(mlx);
}
int main(){
	void *mlx_ptr;
	void *win_ptr;
	int i = 0;
	int j = 0;
	char map[8][8] = {
		{"11111111"},
		{"10010001"},
		{"10001001"},
		{"10010001"},
		{"10010001"},
		{"10010001"},
		{"10010001"},
		{"11111111"}
	};
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx window");
	t_map *map1 = malloc(sizeof(t_map));
	map1->height = 8;
	map1->width = 8;
	while(i < 8)
	{
		j = 0;
		while(j < 8)
		{
			map1->map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	t_mlx *mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_ptr;
	mlx->win_ptr = win_ptr;
	mlx->l = 1000;
	mlx->L = 1000;
	t_point *player = malloc(sizeof(t_point));
	player->x = 600;
	player->y = 600;
	player->pof = N;
	mlx->player = player;
	mlx->map = map1;
	drawmap(mlx);
	drawplayer(mlx);
	mlx_loop(mlx_ptr);
}
