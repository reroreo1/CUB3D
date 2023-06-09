/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:13:35 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/05 03:15:09 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing_map(char *it, t_mlx *m, int fd)
{
	if (!check_missing_token(m) || !valid_char_map(it))
		return (0);
	if (!*it)
	{
		printf("Error\nunfound map");
		return (0);
	}
	add_line(m->map, it);
	it = get_next_line(fd);
	while (it)
	{
		if (!valid_char_map(it))
		{
			free(it);
			return (0);
		}
		add_line(m->map, it);
		free(it);
		it = get_next_line(fd);
	}
	optimize_map(m->map);
	if (!f_check(m->map) || !s_check(m->map, m->player))
		return (0);
	return (1);
}

int	start_parsing3(t_mlx *m, char *it, t_var *r)
{
	r->i = tex(it, m);
	r->j = flocei(it, m);
	if (!r->i || !r->j)
		return (0);
	return (1);
}

int	start_parsing(t_mlx *m, char fd, t_var r, char *buff)
{
	char	*it;

	buff = get_next_line(fd);
	while (buff)
	{
		r = (t_var){0, 0, 0};
		it = buff;
		if (!strcmp(it, "\n"))
			;
		else if (!start_parsing3(m, it, &r))
		{
			free(buff);
			return (0);
		}
		else if (r.i == 1 || r.j == 1)
			;
		else if (!parsing_map(it, m, fd))
		{
			free(buff);
			return (0);
		}
		free(buff);
		buff = get_next_line(fd);
	}
	return (1);
}

void	free_mlx(t_mlx *m)
{
	free_map(m->map);
	free_par(&m->par);
}

t_mlx	*parsing(int ac, char **av, char **r)
{
	int		fd;
	t_mlx	*m;
	char	*buff;

	buff = NULL;
	if (!ft_open(&fd, av[1], O_RDONLY) || ac > 2)
		return (NULL);
	m = malloc(sizeof(t_mlx));
	m->par = (t_par){-1, -1, NULL, NULL, NULL, NULL};
	m->map = malloc(sizeof(t_map));
	*m->map = (t_map){0, 0, NULL};
	m->player = malloc(sizeof(t_point));
	*m->player = (t_point){0, 0, 0, 0, 0, 0, 0, 0};
	if (!start_parsing(m, fd, (t_var){0, 0, 0}, buff) || !lcheck(m))
	{
		free_mlx(m);
		return (NULL);
	}
	close(fd);
	r[0] = m->par.n;
	r[1] = m->par.w;
	r[2] = m->par.s;
	r[3] = m->par.e;
	m->player->fov = 1.047;
	return (m);
}

// printf("n:%s\ns:%s\nw:%s\ne:%s\n", m->par.n, m->par.s, m->par.w, m->par.e);
// printf("av[1]:%s\nfd:%d\n", av[1], fd);
// printf("f: %d, %d, %d\n", m->par.f & 0Xff,
// (m->par.f & 0Xff00) >> 8, (m->par.f & 0Xff0000) >> 16);
// printf("c: %d, %d, %d\n", m->par.c & 0Xff,
// (m->par.c & 0Xff00) >> 8, (m->par.c & 0Xff0000) >> 16);
// printf("map_height:%d\nmap_width:%d\n\n", m->map->height, m->map->width);
// printf("p.x:%f\tp.y:%f\tp.p:%f\t\n",
// m->player->x, m->player->y, m->player->pov);
// print_map(m->map);
