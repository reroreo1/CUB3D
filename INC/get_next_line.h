/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:14:00 by hkheiri           #+#    #+#             */
/*   Updated: 2022/03/17 20:00:07 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2
# include <sys/uio.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>

int		len(char *str);
int		nlen(char *str);
char	*dupjoin(char **s1, char *s2);
int		strnl(char *s);
char	*get_next_line(int fd);

#endif
