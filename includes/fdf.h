/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:13:38 by atudor            #+#    #+#             */
/*   Updated: 2024/01/14 16:14:13 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>

# define WIDTH 1000
# define LEN 800

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	long	color;
}	t_point;

typedef struct s_iso
{
	float	x;
	float	y;
	long	color;
}	t_iso;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		len;
	int		endian;
	t_point	*map;
}	t_data;

typedef struct s_map
{
	int		length;
	int		width;
	int		size;
	char	*filename;
	t_point	*coord_array;
	t_iso	*iso;
	float	offset_x;
	float	offset_y;
	float	max_iso_x;
	float	min_iso_x;
	float	max_iso_y;
	float	min_iso_y;
	float	scale;
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_map;

typedef struct s_math
{
	int	iso_x0;
	int	iso_x1;
	int	iso_y1;
	int	iso_y0;
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	e2;
	int	err;
}	t_math;

void	parse_map(t_map *map, t_point **coord_array);
void	get_map_dimensions(t_map *map);
void	add_point(t_map *map, t_point *coord_array, char *line, int i);
void	init_map(t_map *map, char *filename, void *mlx, void *win);
void	scale_iso(t_map *map);
void	change_to_iso(t_map *map, t_point *coord);
float	get_iso_x(float x, float y, float z);
float	get_iso_y(float x, float y, float z);
void	draw_line(t_data *img, t_math *math, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_map(void *mlx, void *win, t_map *map);
void	draw_map_cont(t_map *map, t_data *img);
void	draw_line_between_points(t_data *img, t_map *map, int idx1, int idx2);
void	fill_image(t_data *img, t_point *coord, int i, t_map *map);
void	draw_line(t_data *img, t_math *math, int color);
void	draw_line_cont(t_data *img, t_math *math, int color);
int		ft_atoi_base(const char *str, int str_base);

#endif