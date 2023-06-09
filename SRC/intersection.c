/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:47:36 by rezzahra          #+#    #+#             */
/*   Updated: 2022/09/04 10:20:46 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color(t_mlx *lata, int x, int y, int index)
{
	char	*dst;
	int		color;

	dst = lata->data[index].addr + (y * lata->data[index].line_length
			+ x * (lata->data[index].bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

double	calculate_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->li + x * (data->b / 8));
	*(unsigned int *)dst = color;
}

void	drawplayer(t_mlx *mlx)
{
	int	speed;

	speed = 10;
	if (!check_player_pos(*mlx, mlx->player->x + cos(mlx->player->pov)
			* speed * 2 * mlx->v, mlx->player->y
			+ sin(mlx->player->pov) * 2 * speed * mlx-> v))
	{
		mlx->player->y += sin(mlx->player->pov) * speed * mlx->v;
		mlx->player->x += cos(mlx->player->pov) * speed * mlx->v;
	}
}

int	quit(void)
{
	exit(0);
}
