/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:58:39 by rezzahra          #+#    #+#             */
/*   Updated: 2022/08/02 13:58:40 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void floor_ceiling(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->l)
	{
		j = 0;
		while (j < mlx->L / 2)
		{
			my_mlx_pixel_put(mlx, i, j, 0x00abff);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < mlx->l)
	{
		j = mlx->L / 2;
		while (j < mlx->L)
		{
			my_mlx_pixel_put(mlx, i, j, 0xababff);
			j++;
		}
		i++;
	}
}
void draw_line(t_mlx *mlx,double ax, double ay,double height)
{
	double dx,bx,by;
	double dy, s;
	double i = -1;
	
	bx = ax;
	by = ay + height;
	dx = bx - ax;
	dy = by - ay;
	if (fabs(dx) > fabs(dy))
		s = fabs(dx);
	else
		s = fabs(dy);
	ax = ax < 0 ? 0 : ax;
	ax = ax >= mlx->l ? (mlx->l - 1) : ax;
	ay = ay < 0 ? 0 : ay;
	ay = ay >= mlx->L ? (mlx->L - 1) : ay;
	while (++i < s)
	{
		if (ax < mlx->l && ay < mlx->L)
			my_mlx_pixel_put(mlx, (int)ax, (int)ay, 0xdba507);
		ax += dx / s;
		ay += dy / s;
	}
	
}
void draw_strip_wall(t_mlx *mlx){
	int i = 0;
	int j = 0;
	int raycount = 0;
	double wallheight = 0; 
	while(raycount < mlx->rays->n_rays - 1){
		wallheight = floor(866 * (mlx->tile_height / mlx->rays->distance[raycount]));
		j = 0;
		while(j < mlx->rays->thickness){
			draw_line(mlx,i,mlx->L / 2 - wallheight/ 2,wallheight);
			j++;
			i++;
		}
		if(i == mlx->l - 1)
			break;
		raycount++;
	}
}
void raycasting(t_mlx *mlx){
	int raycount = 0;
	t_point p1;
	double rayangle = mlx->player->pov - mlx->player->fov / 2;
	while(raycount < 199){
		p1 = dda_draw_line(mlx,mlx->player->x + cos(rayangle), mlx->player->y + sin(rayangle));
		rayangle += mlx->rays->teta;
		mlx->rays->distance[raycount] = calculate_distance(mlx->player->x,mlx->player->y,p1.x,p1.y) * cos(mlx->player->pov - rayangle);	
		raycount++;
	}
	draw_strip_wall(mlx);
}