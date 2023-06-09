/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:36:47 by hkheiri           #+#    #+#             */
/*   Updated: 2021/11/20 19:46:24 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strnl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

int	len(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		i++;
	}
	return (i);
}

int	nlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}

char	*dupjoin(char **s1, char *s2)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char ) * (len(*s1) + len(s2) + 1));
	if (!str)
		return (NULL);
	if (s1[0])
	{
		while (s1[0][++i])
			str[i] = s1[0][i];
	}
	i = -1;
	while (s2[++i])
		str[len(*s1) + i] = s2[i];
	str[len(*s1) + i] = '\0';
	if (s1[0])
	{
		free(s1[0]);
		s1[0] = NULL;
	}
	return (str);
}
