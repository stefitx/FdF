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
# include <float.h>
# include <stdlib.h>


# define WIDTH 800
# define LEN 600

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
	float	left_x;
	float	right_x;
	float	min_y;
	float	max_y;
}	t_iso;

typedef struct	s_map
{
	int		length;
	int		width;
	int		size;
	char	*filename;
	t_point *coord_array;
	t_iso	*iso_array;
	float	scale;
	int		max;
	int		min;
}	t_map;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point *map;
}				t_data;

typedef struct s_input {
    float rotx;
    float roty;
    float rotz;
} t_input;

 void malloc_map(t_map *map_len);
void	map_fill(char *filename, t_map *map_len);
void	draw_map(void	*mlx, void	*win, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	get_width(char *filename);
int	get_iso_x(float x, float z);
int	get_iso_y(float x, float y, float z);
t_point rotateAroundPivot(t_point point, t_point pivot, t_point euler);
void fill_map(char	*filename, t_point *map, t_map *map_len);
void read_and_fill_map(char *filename, t_map *map_len);
int ft_atoi_base(const char *str, int str_base);
int get_color(char *line);


void	parse_map(t_map *map, t_point **coord_array);
void	get_map_dimensions(t_map *map);
void	add_point(t_map *map, t_point *coord_array, char *line, int i);
void init_map(t_map *map, char *filename);
//void draw_map(void *mlx, void *win, t_map *map, t_input input);
void	rotation(t_point *coord, t_input input);
void	scale_iso(t_map *map);
void	change_to_iso(t_map *map, t_point *coord);



#endif
