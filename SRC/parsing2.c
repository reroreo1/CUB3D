/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:12:12 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/05 00:38:41 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(char *it, int *color)
{
	char	rgb[3][5];
	t_var	v;

	v.j = 0;
	if (!check_color_char(it))
	{
		printf("Error \nin color :%s", it - 1);
		return (0);
	}
	v.i = -1;
	if (*it != ' ')
		v.i = 0;
	get_color2(it, color, rgb, &v);
	while (++v.i < 3)
	{
		if (atoi(rgb[v.i]) > 255 || atoi(rgb[v.i]) < 0)
		{
			printf("Error \ninvalid color: %d ", atoi(rgb[v.i]));
			return (0);
		}
		*color += atoi(rgb[v.i]) << (16 - v.i * 8);
	}
	return (1);
}

int	flocei(char *it, t_mlx *m)
{
	if (!strncmp(it, "F ", 2))
	{
		if (m->par.f != -1)
		{
			printf("Error\nduplicate floor identifier");
			return (0);
		}
		if (!get_color(it + 1, &m->par.f))
			return (0);
		return (1);
	}
	if (!strncmp(it, "C ", 2))
	{
		if (m->par.c != -1)
		{
			printf("Error\nduplicate ceilling identifier");
			return (0);
		}
		if (!get_color(it + 1, &m->par.c))
			return (0);
		return (1);
	}
	return (2);
}

int	optimize_map(t_map *m)
{
	char	*nm;
	int		i;
	int		j;

	i = -1;
	while (++i < m->height)
	{
		if (m->map[i][strlen(m->map[i]) - 1] == '\n')
			m->map[i][strlen(m->map[i]) - 1] = 0;
		if (strlen(m->map[i]) < (unsigned )m->width)
		{
			nm = malloc(sizeof(char ) * m->width + 1);
			strcpy(nm, m->map[i]);
			j = strlen(nm);
			while (j < m->width)
			{
				nm[j] = ' ';
				j++;
			}
			nm[j] = 0;
			free(m->map[i]);
			m->map[i] = nm;
		}
	}
	return (1);
}

int	f_check(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->height)
	{
		if (!i || (i == m->height - 1))
		{
			j = -1;
			while (++j < m->width)
			{
				if ((m->map[i][j] != '1') && (m->map[i][j] != ' '))
					return (0);
			}
		}
		if ((m->map[i][0] != '1') && (m->map[i][0] != ' '))
			return (0);
		if ((m->map[i][m->width -1] != '1')
			&& (m->map[i][m->width - 1] != ' '))
			return (0);
	}
	return (1);
}

int	s_check(t_map *m, t_point *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
		{
			if (ppla(m, i, j, p))
			{
				if (!valid_0(m, i, j))
					return (0);
			}
			if (m->map[i][j] == '0' )
			{
				if (!valid_0(m, i, j))
					return (0);
			}
		}
	}
	return (1);
}
