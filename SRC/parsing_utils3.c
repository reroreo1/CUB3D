/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:41:05 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/05 02:23:18 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	true_len(char *str)
{
	int	i;

	i = strlen(str) - 1;
	while (i && (str[i] == '\n' || str[i] == ' '))
		i--;
	return (i + 1);
}

void	free_par(t_par *par)
{
	free(par->e);
	free(par->w);
	free(par->s);
	free(par->n);
}

int	check_missing_token(t_mlx *m)
{
	if (!m->par.n || !m->par.s || !m->par.e || !m->par.w)
	{
		printf("Error\nmissing texture identifier");
		return (0);
	}
	if (m->par.c == -1 || m->par.f == -1)
	{
		printf("Error\nmissing color identifier");
		return (0);
	}
	return (1);
}

int	cf(char *n)
{
	int	f;

	f = open(n, O_RDONLY);
	if (f == -1)
	{
		printf("Error\nin opening %s", n);
		return (0);
	}
	close(f);
	return (1);
}

int	lcheck(t_mlx *m)
{
	if (!m->map->height || !m->map->width)
	{
		printf("Error\nmap is missing.");
		return (0);
	}
	if (!cf(m->par.e) || !cf(m->par.w)
		|| !cf(m->par.s) || !cf(m->par.n))
		return (0);
	return (1);
}
