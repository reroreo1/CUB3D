/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:48:53 by rezzahra          #+#    #+#             */
/*   Updated: 2022/09/04 08:17:55 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/cub3d.h"

void	raycasting(t_mlx *mlx)
{
	int		raycount;
	t_point	p1;
	double	rayangle;

	raycount = 0;
	rayangle = mlx->player->pov - 0.5236;
	while (raycount < mlx->rays->n_rays)
	{
		p1 = dda_draw_line(mlx, mlx->player->x + cos(rayangle),
				mlx->player->y + sin(rayangle));
		offset_check(&p1);
		mlx->rays->pts[raycount] = p1;
		mlx->rays->pts[raycount].distance = calculate_distance(mlx->player->x,
				mlx->player->y, p1.x, p1.y) * cos(mlx->player->pov - rayangle);
		rayangle += mlx->rays->teta;
		raycount++;
	}
	draw_strip_wall(mlx);
}

void	rectify_stripes(t_mlx *mlx, t_point *p1)
{
	if (p1->x < 0)
		p1->x = 0;
	if (p1->y < 0)
		p1->y = 0;
	if (p1->x >= mlx->l)
		p1->x = mlx->l - 1;
	if (p1->y >= mlx->t)
		p1->y = mlx->t - 1;
}

void	right_left(t_mlx *w, int k)
{
	int	speed;

	speed = 10;
	if (w->player->pov <= 0)
		w->player->pov = (w->player->pov + N + S);
	if (k == 0)
	{
		if (!check_player_pos(*w, w->player->x - cos(w->player->pov + S)
				* speed * 2, w->player->y
				- sin(w->player->pov + S) * speed * 2))
		{
			w->player->x -= cos(w->player->pov + S) * speed;
			w->player->y -= sin(w->player->pov + S) * speed;
		}		
	}
	if (k == 2)
	{
		if (!check_player_pos(*w, w->player->x + cos(w->player->pov + S)
				* speed * 2, w->player->y
				+ sin(w->player->pov + S) * speed * 2))
		{
			w->player->x += cos(w->player->pov + S) * speed;
			w->player->y += sin(w->player->pov + S) * speed;
		}		
	}
}
