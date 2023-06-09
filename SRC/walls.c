/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:58:39 by rezzahra          #+#    #+#             */
/*   Updated: 2022/09/05 04:06:29 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceiling(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->l)
	{
		j = 0;
		while (j < mlx->t / 2)
		{
			my_mlx_pixel_put(mlx, i, j, shadowing(mlx->par.f, j * 3));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < mlx->l)
	{
		j = mlx->t / 2;
		while (j < mlx->t)
		{
			my_mlx_pixel_put(mlx, i, j, shadowing(mlx->par.c, 500 - j * 3));
			j++;
		}
		i++;
	}
}

int	shadowing(int color, int dis)
{
	int		r;
	int		g;
	int		b;
	int		mdis;
	float	fac;

	mdis = 64 * 30;
	fac = 1 - (float)dis / mdis;
	if (dis > mdis)
		return (0);
	r = (color & 0Xff) * fac;
	g = (int)(((color & 0Xff00) >> 8) * fac);
	b = (int)(((color & 0Xff0000) >> 16) * fac);
	return (r | (g << 8) | (b << 16));
}

void	draw_line(t_mlx *mlx, t_point *p1, double height, t_point p)
{
	double	tex_y;
	double	bx;
	double	by;
	double	dis;

	dis = 0;
	bx = p1->x;
	by = p1->y + height;
	rectify_stripes(mlx, p1);
	while (p1->y < by)
	{
		dis = p1->y + (height / 2) - (mlx->t / 2);
		tex_y = dis *((float)64 / height);
		if (p1->x < mlx->l && p1->y < mlx->t)
		{
			if (p.offset > 0)
				my_mlx_pixel_put(mlx, p1->x, p1->y,
					shadowing(get_pixel_color(mlx, p.offset, tex_y,
							p.tex_index), calculate_distance(mlx->player->x,
							mlx->player->y, p.x, p.y)));
			else
				my_mlx_pixel_put(mlx, p1->x, p1->y, 0);
		}
		p1->y += 1;
	}
}

void	draw_strip_wall(t_mlx *mlx)
{
	int		raycount;
	double	wallheight;
	t_point	p;

	p.x = 0;
	raycount = 0;
	wallheight = 0;
	while (raycount < mlx->rays->n_rays)
	{
		wallheight = 1500 * (mlx->tile_height
				/ mlx->rays->pts[raycount].distance);
		p.y = mlx->t / 2 - wallheight / 2;
		draw_line(mlx, &p, wallheight, mlx->rays->pts[raycount]);
		(p.x)++;
		raycount++;
	}
}

void	offset_check(t_point *p1)
{
	if (((int)p1->x % 64 == 63 && (int)p1->y % 64 == 63)
		|| ((int)p1->x % 64 == 63 && (int)p1->y % 64 == 0)
		|| ((int)p1->x % 64 == 0 && (int)p1->y % 64 == 63))
			p1->offset = -1;
	else if ((int)p1->x % 64 == 0)
	{
		p1->offset = (int)p1->y % 64;
		p1->tex_index = 0;
	}
	else if ((int)p1->x % 64 == 63)
	{
		p1->offset = (int)p1->y % 64;
		p1->tex_index = 1;
	}
	else if ((int)p1->y % 64 == 0)
	{
		p1->offset = (int)p1->x % 64;
		p1->tex_index = 2;
	}
	else if ((int)p1->y % 64 == 63)
	{
		p1->offset = (int)p1->x % 64;
		p1->tex_index = 3;
	}
}
