/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:32:01 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/04 23:14:15 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	optimize(char **s)
{
	char	*news;
	int		news_len;
	int		i;

	i = -1;
	if (!(*s[0]) && *s)
	{
		free(s[0]);
		s[0] = NULL;
		return (0);
	}
	news = NULL;
	news_len = len(s[0]) - nlen(s[0]);
	if (news_len)
	{
		news = malloc(sizeof(char ) * (news_len + 1));
		if (!news)
			return (0);
		while (++i < news_len)
			news[i] = (s[0])[nlen(s[0]) + i];
		news[i] = '\0';
	}
	free(s[0]);
	s[0] = news;
	return (1);
}

static char	*extract_line(char *s)
{
	char	*rtn;
	int		i;

	if (!s || !(*s))
		return (NULL);
	i = -1;
	rtn = malloc(sizeof(char ) * (nlen(s) + 1));
	if (!rtn)
		return (NULL);
	while (++i < nlen(s))
		rtn[i] = s[i];
	rtn[i] = '\0';
	return (rtn);
}

void	get_next_line2(char **buff, char **rtn, char **str)
{
	free(*buff);
	*buff = NULL;
	*rtn = extract_line(*str);
	if (!optimize(str))
	{
		free(*rtn);
		*rtn = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	char		*rtn;
	int			readrtn;

	readrtn = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!strnl(str) && readrtn != 0)
	{
		readrtn = read(fd, buff, BUFFER_SIZE);
		if (readrtn == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readrtn] = '\0';
		str = dupjoin(&str, buff);
	}
	get_next_line2(&buff, &rtn, &str);
	return (rtn);
}

// int main(int ac, char **av)
// {
// 	int fd;
// 	char *str;

// 	if ((fd = open("get_next_line.c", O_RDONLY)) == -1)
// 	{
// 		printf("k");
// 		return (1);
// 	}
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("str: %s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// }