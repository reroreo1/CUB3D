/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:16:15 by rezzahra          #+#    #+#             */
/*   Updated: 2022/08/02 12:42:56 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double calculate_distance(double x1,double y1,double x2,double y2){
	return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
};

void    my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
    char    *dst;
	color = color+ 1 - 1;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void drawplayer(t_mlx *mlx){

	int speed = 10;
	if(!check_player_pos(*mlx,mlx->player->x + cos(mlx->player->pov) * speed * mlx->v,mlx->player->y + sin(mlx->player->pov) * speed * mlx-> v)){
        mlx->player->y += sin(mlx->player->pov) * speed * mlx->v;
		mlx->player->x += cos(mlx->player->pov) * speed * mlx->v;
	}
}
int quit(void){
	exit(0);
}

int udrl(int k,t_mlx *w)
{
    if(k == 53)
	{
		quit();
        return (0);
	}
	if (k == UP)
		w->v = 1;
	if (k == DOWN)
		w->v = -1;
    if(k == RIGHT){
		w->player->pov += 0.2;
	}
    if(k == LEFT){
		w->player->pov -= 0.2;
	} 
    return 0;
}
int check_player_pos(t_mlx mlx,double x,double y){
	if(mlx.map->map[(int)(x / mlx.tile_length)][(int)(y/ mlx.tile_height)] == '1')
		return 1;
	return 0;
}
int velocity(int k,t_mlx *w){
	if (k == UP)
		w->v = 0;
	if (k == DOWN)
		w->v = 0;
	return 0;
}
void events(t_mlx *w)
{
	mlx_hook(w->win_ptr, 3, 0, velocity, w);
    mlx_hook(w->win_ptr, 2, 0, udrl, w);
    mlx_hook(w->win_ptr, 17, 0, quit, 0);
}
t_point dda_draw_line(t_mlx *mlx,double bx, double by)
{
	double dx;
	double dy, s;
	t_point p1;
	double ax = mlx->player->x;
	double ay = mlx->player->y;
	dx = bx - ax;
	dy = by - ay;

	if (fabs(dx) > fabs(dy))
		s = fabs(dx);
	else
		s = fabs(dy);
	while (1)
	{
		if (!(!check_player_pos(*mlx,ax,ay) && !check_player_pos(*mlx,ax + dx / s,ay) && !check_player_pos(*mlx,ax,ay + dy / s)))
			break;
		ax += dx / s;
		ay += dy / s;
	}
	p1.x = ax;
	p1.y = ay;
	return (p1);
}

int update(t_mlx *w)
{
	mlx_destroy_image(w->mlx_ptr,w->img);
	//w->img = NULL;
	w->img = mlx_new_image(w->mlx_ptr,w->l,w->L);
	w->addr = mlx_get_data_addr(w->img, &w->bits_per_pixel,&w->line_length,&w->endian);
	floor_ceiling(w);
	drawplayer(w);
	raycasting(w);
	mlx_put_image_to_window(w->mlx_ptr,w->win_ptr,w->img,0,0);
    return 1;
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
		{"10000001"},
		{"10000001"},
		{"10000001"},
		{"10000001"},
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
	mlx->img = mlx_new_image(mlx_ptr, mlx->l, mlx->L);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,&mlx->line_length,&mlx->endian);
	t_point *player = malloc(sizeof(t_point));
	t_rays *rays = malloc(sizeof(t_rays));
	player->x = 600;
	player->y = 600;
	player->fov = 1.047;
	player->pov = S;
	rays->teta = 0.005236;
	rays->n_rays = (int)(player->fov / rays->teta);
	rays->distance = malloc(rays->n_rays * sizeof(double));
	rays->thickness = floor(mlx->l / rays->n_rays);
	mlx->player = player;
	mlx->map = map1;
	mlx->tile_length = mlx->l / mlx->map->height;
	mlx->tile_height = mlx->L / mlx->map->width;
	mlx->rays = rays;
	mlx->v = 0;
	floor_ceiling(mlx);
	drawplayer(mlx);
	raycasting(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr,mlx->win_ptr,mlx->img,0,0);
	events(mlx);
    mlx_loop_hook(mlx->mlx_ptr,&update, mlx);
    mlx_loop(mlx->mlx_ptr);
}
