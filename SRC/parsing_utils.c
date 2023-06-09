/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:25:01 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/04 01:40:41 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_line(t_map *m, char *str)
{
	char	**nm;
	int		i;

	i = -1;
	nm = malloc(sizeof(char *) * (m->height + 1));
	while (++i < m->height)
		nm[i] = m->map[i];
	nm[m->height] = strdup(str);
	if (true_len(str) > m->width)
		m->width = true_len(str);
	free(m->map);
	m->height++;
	m->map = nm;
}

int	is_1(char c)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	assign_p_value(t_point *p, int i, int j, float di)
{
	p->x = i * 64 + 20;
	p->y = j * 64 + 20;
	p->pov = di;
	return (1);
}

int	ppla(t_map *m, int i, int j, t_point *p)
{
	if (m->map[i][j] == 'N')
	{
		assign_p_value(p, i, j, N);
		m->map[i][j] = '0';
		return (1);
	}
	if (m->map[i][j] == 'S')
	{
		assign_p_value(p, i, j, S);
		m->map[i][j] = '0';
		return (1);
	}
	if (m->map[i][j] == 'E')
	{
		assign_p_value(p, i, j, E);
		m->map[i][j] = '0';
		return (1);
	}
	if (m->map[i][j] == 'W')
	{
		assign_p_value(p, i, j, W);
		m->map[i][j] = '0';
		return (1);
	}
	return (0);
}

int	valid_0(t_map *m, int i, int j)
{
	if (!is_1(m->map[i - 1][j - 1]) || !is_1(m->map[i - 1][j])
		|| !is_1(m->map[i -1][j + 1]))
	{
		printf("Error\nin map near:: %d, %d", i, j);
		return (0);
	}
	if (!is_1(m->map[i][j - 1]) || !is_1(m->map[i][j])
		|| !is_1(m->map[i][j + 1]))
	{
		printf("Error\nin map near:: %d, %d", i, j);
		return (0);
	}
	if (!is_1(m->map[i + 1][j - 1]) || !is_1(m->map[i + 1][j])
		|| !is_1(m->map[i + 1][j + 1]))
	{
		printf("Error\nin map near:: %d, %d", i, j);
		return (0);
	}
	return (1);
}
