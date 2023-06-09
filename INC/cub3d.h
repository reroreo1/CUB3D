/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:58:57 by rezzahra          #+#    #+#             */
/*   Updated: 2022/09/05 03:53:51 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include <string.h>
# include <ctype.h>
# include "struct.h"
# define N 4.71239
# define W 0
# define E 3.14159
# define S 1.5708
# define KEYUP 126
# define KEYDOWN 125
# define KEYRIGHT 124
# define KEYLEFT 123

int		quit(void);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
double	calculate_distance(double x1, double y1, double x2, double y2);
void	drawplayer(t_mlx *mlx);
t_point	dda_draw_line(t_mlx *mlx, double bx, double by);
int		update(t_mlx *w);
int		udrl(int k, t_mlx *w);
void	events(t_mlx *w);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int		check_player_pos(t_mlx mlx, double x, double y);
void	print_distance(t_mlx *mlx);
void	floor_ceiling(t_mlx *mlx);
void	raycasting(t_mlx *mlx);
void	draw_strip_wall(t_mlx *mlx);
double	calculate_distance(double x1, double y1, double x2, double y2);
int		get_pixel_color(t_mlx *data, int x, int y, int index);
int		velocity(int k, t_mlx *w);
void	events(t_mlx *w);
void	offset_check(t_point *p1);
void	rectify_stripes(t_mlx *mlx, t_point *p1);
void	right_left(t_mlx *w, int k);
int		ft_open(int *fd, char *file, int flag);
int		len(char *str);
int		nlen(char *str);
char	*dupjoin(char **s1, char *s2);
int		strnl(char *s);
int		shadowing(int color, int dis);
char	*get_next_line(int fd);
void	add_line(t_map *m, char *str);
int		valid_char_map(char *s);
void	free_map(t_map *m);
void	free_par(t_par *par);
void	print_map(t_map *m);
int		valid_0(t_map *m, int i, int j);
int		ppla(t_map *m, int i, int j, t_point *p);
t_mlx	*parsing(int ac, char **av, char **r);
int		true_len(char *str);
int		check_color_char(char *it);
void	get_color2(char *it, int *color, char rgb[3][5], t_var *v);
int		optimize_map(t_map *m);
int		f_check(t_map *m);
int		s_check(t_map *m, t_point *p);
int		tex(char *it, t_mlx *m);
int		flocei(char *it, t_mlx *m);
int		check_missing_token(t_mlx *m);
int		lcheck(t_mlx *m);
#endif