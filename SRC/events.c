/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:21:20 by rezzahra          #+#    #+#             */
/*   Updated: 2022/09/05 02:00:48 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	udrl(int k, t_mlx *w)
{
	if (k == 53)
	{
		quit();
		return (0);
	}
	if (k == KEYUP || k == 13)
		w->v = 1;
	if (k == KEYDOWN || k == 1)
		w->v = -1;
	if (k == KEYRIGHT)
		w->player->pov += 0.2;
	if (k == KEYLEFT)
		w->player->pov -= 0.2;
	right_left(w, k);
	update(w);
	return (0);
}

int	check_player_pos(t_mlx mlx, double x, double y)
{
	if (mlx.map->map[(int)(x / mlx.tile_length)][(int)(y
		/mlx.tile_height)] == '1')
		return (1);
	return (0);
}

int	velocity(int k, t_mlx *w)
{
	static int	i;

	if (k == KEYUP || k == 13)
		w->v = 0;
	if (k == KEYDOWN || k == 1)
		w->v = 0;
	if (k == 2 || k == 0)
		w->v = 0;
	if (!i)
		update(w);
	i++;
	i = i % 1000000000000;
	return (0);
}

void	events(t_mlx *w)
{
	mlx_hook(w->win_ptr, 3, 0, velocity, w);
	mlx_hook(w->win_ptr, 2, 0, udrl, w);
	mlx_hook(w->win_ptr, 17, 0, quit, 0);
}

t_point	dda_draw_line(t_mlx *mlx, double bx, double by)
{
	double	dx;
	double	dy;
	double	s;
	t_point	p2;

	p2.x = mlx->player->x;
	p2.y = mlx->player->y;
	dx = bx - p2.x;
	dy = by - p2.y;
	if (fabs(dx) > fabs(dy))
		s = fabs(dx);
	else
		s = fabs(dy);
	while (1)
	{
		if (!(!check_player_pos(*mlx, p2.x, p2.y)
				&& !check_player_pos(*mlx, p2.x + dx / s, p2.y)
				&& !check_player_pos(*mlx, p2.x, p2.y + dy / s)))
			break ;
		p2.x += dx / s;
		p2.y += dy / s;
	}
	return (p2);
}
