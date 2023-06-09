/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:16:15 by rezzahra          #+#    #+#             */
/*   Updated: 2022/09/05 03:15:01 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(t_mlx *w)
{
	mlx_destroy_image(w->mlx_ptr, w->img);
	w->img = mlx_new_image(w->mlx_ptr, w->l, w->t);
	w->addr = mlx_get_data_addr(w->img, &w->b, &w->li, &w->e);
	floor_ceiling(w);
	drawplayer(w);
	raycasting(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img, 0, 0);
	return (1);
}

void	get_textures_addr(t_mlx *m, char **r)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		m->data[i].img_height = 64;
		m->data[i].img_width = 64;
		m->data[i].img = mlx_xpm_file_to_image(m->mlx_ptr, r[i],
				&(m->data[i].img_width),
				&(m->data[i].img_height));
		m->data[i].addr = mlx_get_data_addr(m->data[i].img,
				&(m->data[i].bits_per_pixel),
				&(m->data[i].line_length), &(m->data[i].endian));
	}
}

t_mlx	*init(int ac, char **av, char **r)
{
	t_mlx	*m;

	m = parsing(ac, av, r);
	if (!m)
		return (NULL);
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, 2000, 1000, "mlx window");
	m->data = malloc(4 * sizeof(t_data));
	get_textures_addr(m, r);
	m->l = 2000;
	m->t = 1000;
	m->img = mlx_new_image(m->mlx_ptr, m->l, m->t);
	m->addr = mlx_get_data_addr(m->img, &m->b, &m->li, &m->e);
	m->rays = malloc(sizeof(t_rays));
	m->rays->n_rays = 2000;
	m->rays->teta = m->player->fov / m->rays->n_rays;
	m->rays->pts = malloc(m->rays->n_rays * sizeof(t_point));
	m->rays->thickness = 1;
	m->tile_length = 64;
	m->tile_height = 64;
	m->max_h = 64 * m->map->height;
	m->max_w = 64 * m->map->width;
	m->v = 0;
	return (m);
}

int	main(int ac, char **av)
{
	char	*relative_path[4];
	t_mlx	*mlx;

	if (ac > 2)
	{
		printf("Error\nthe program takes only the map as parameter");
	}
	mlx = init(ac, av, relative_path);
	if (!mlx)
		return (0);
	floor_ceiling(mlx);
	drawplayer(mlx);
	raycasting(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	events(mlx);
	mlx_loop(mlx->mlx_ptr);
}
