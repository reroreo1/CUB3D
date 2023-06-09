/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheiri <hkheiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:59:31 by hkheiri           #+#    #+#             */
/*   Updated: 2022/09/04 05:36:26 by hkheiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_var
{
	int	i;
	int	j;
	int	k;
}				t_var;

typedef struct s_par
{
	int		f;
	int		c;
	char	*n;
	char	*s;
	char	*e;
	char	*w;
}				t_par;

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
}			t_map;

typedef struct s_point
{
	double	x;
	double	y;
	double	pov;
	double	fov;
	double	rayangle;
	double	distance;
	double	offset;
	int		tex_index;
}			t_point;

typedef struct s_rays
{
	t_point	*pts;
	int		n_rays;
	double	teta;
	double	thickness;
}			t_rays;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}				t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		t;
	int		l;
	t_map	*map;
	t_point	*player;
	void	*img;
	t_par	par;
	char	*addr;
	int		b;
	int		li;
	int		e;
	double	tile_length;
	double	tile_height;
	t_rays	*rays;
	int		v;
	t_data	*data;
	double	max_h;
	double	max_w;
}				t_mlx;
#endif