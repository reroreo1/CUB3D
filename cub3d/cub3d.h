/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:58:57 by rezzahra          #+#    #+#             */
/*   Updated: 2022/07/30 05:39:28 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>

#define N 1.5708
#define W 3.14159
#define E 0
#define S 4.71239

typedef struct s_map{
	int height;
	int width;
	char map[8][8];
} t_map;

typedef struct s_point{
	int x;
	int y;
	double pof;
} t_point;

typedef struct s_mlx{
	void *mlx_ptr;
	void *win_ptr;
	int L;
	int l;
	t_map *map;
	t_point *player;
} t_mlx;