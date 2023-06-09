/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:42:55 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/05 02:16:40 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_path(char *it, char **dest)
{
	int	pathl;

	pathl = 0;
	if (*dest)
	{
		printf("Error\nduplicate texture:: %s", it - 2);
		return (0);
	}
	if (nlen(it) <= 2)
	{
		printf("Error\nin texture near:: %s", it - 2);
		return (0);
	}
	it++;
	while (it[pathl] && it[pathl] != '\n')
		pathl++;
	*dest = malloc(sizeof(char) * (pathl + 1));
	pathl = -1;
	while (*it && *it != '\n')
	{
		(*dest)[++pathl] = *it;
		it++;
	}
	(*dest)[++pathl] = 0;
	return (1);
}

int	tex(char *it, t_mlx *m)
{
	if (!strncmp(it, "NO ", 3))
	{
		if (!get_path(it + 2, &m->par.n))
			return (0);
		return (1);
	}
	if (!strncmp(it, "SO ", 3))
	{
		if (!get_path(it + 2, &m->par.s))
			return (0);
		return (1);
	}
	if (!strncmp(it, "WE ", 3))
	{
		if (!get_path(it + 2, &m->par.w))
			return (0);
		return (1);
	}
	if (!strncmp(it, "EA ", 3))
	{
		if (!get_path(it + 2, &m->par.e))
			return (0);
		return (1);
	}
	return (2);
}

int	check_color_char2(char *it, t_var *v)
{
	if (!isdigit(it[v->i]) && !(it[v->i] == ','))
		return (0);
	if (it[v->i] == ',')
	{
		if (it[v->i + 1] == ',' || !it[v->i + 1]
			|| it[v->i + 1] == '\n')
			return (0);
		v->j++;
		v->k = 0;
	}
	else
	{
		v->k++;
		if (v->k > 3)
			return (0);
	}
	return (1);
}

int	check_color_char(char *it)
{
	t_var	v;

	v = (t_var){-1, 0, 0};
	if (!*it || *it == '\n' || *it != ' ')
		return (0);
	it++;
	while (it[++v.i] && it[v.i] != '\n')
	{
		if (!check_color_char2(it, &v))
			return (0);
	}
	if (v.j != 2)
		return (0);
	return (1);
}

void	get_color2(char *it, int *color, char rgb[3][5], t_var *v)
{
	while (it[v->i] && it[++v->i] && it[v->i] != '\n')
	{
		v->k = 0;
		if (it[v->i] == ',')
			v->i++;
		while (it[v->i] && it[v->i] != ',')
		{
			rgb[v->j][v->k] = it[v->i++];
			v->k++;
		}
		rgb[v->j][v->k] = 0;
		v->j++;
	}
	*color = 0;
	v->i = -1;
}
