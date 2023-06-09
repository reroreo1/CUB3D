/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:37:23 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/05 04:05:44 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_ex(char *n)
{
	int	i;

	i = strlen(n);
	if (i < 4 || strncmp(&n[i - 4], ".cub", 4))
		return (0);
	return (1);
}

int	ft_open(int *fd, char *file, int flag)
{
	if (!file)
	{
		printf("Error\nplease enter the map as parameter");
		return (0);
	}
	if (!check_ex(file))
	{
		printf("Error\ninvalid map extension");
		return (0);
	}
	*fd = open(file, flag);
	if (*fd == -1)
	{
		printf("Error\nin opening mapfile: %s", file);
		return (0);
	}
	return (1);
}

void	free_map(t_map *m)
{
	int	i;

	i = -1;
	while (++i < m->height)
	{
		free(m->map[i]);
	}
	free(m->map);
	m->map = NULL;
}

int	valid_char_map(char *s)
{
	static int	dup;

	if (*s == '\n' && printf("Error\ninvalid map."))
		return (0);
	while (*s && *s != '\n')
	{
		if (*s != '0' && *s != '1' && *s != ' '
			&& *s != 'N' && *s != 'S' && *s != 'E'
			&& *s != 'W')
		{
			printf("Error\ninvalid map character.\n");
			return (0);
		}
		if (*s == 'N' || *s == 'S' || *s == 'E' || *s == 'W')
		{
			if (dup)
			{
				printf("Error\nduplicate player position.\n");
				return (0);
			}
			dup = 1;
		}
		s++;
	}
	return (1);
}

void	print_map(t_map *m)
{
	int	i;

	i = -1;
	while (++i < m->height)
	{
		printf("%s|\n", m->map[i]);
	}
}
