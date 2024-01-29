/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:12:20 by atudor            #+#    #+#             */
/*   Updated: 2024/01/29 17:18:36 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	draw_line_cont(t_data *img, t_math *math, int color)
{
	while (1)
	{
		my_mlx_pixel_put(img, math->iso_x0, math->iso_y0, color);
		if (math->iso_x0 == math->iso_x1 && math->iso_y0 == math->iso_y1)
			break ;
		math->e2 = 2 * math->err;
		if (math->e2 >= math->dy)
		{
			math->err += math->dy;
			math->iso_x0 += math->sx;
		}
		if (math->e2 <= math->dx)
		{
			math->err += math->dx;
			math->iso_y0 += math->sy;
		}
	}
}

void	draw_line(t_data *img, t_math *math, int color)
{
	math->dx = abs(math->iso_x1 - math->iso_x0);
	math->dy = -abs(math->iso_y1 - math->iso_y0);
	if (math->iso_x0 < math->iso_x1)
		math->sx = 1;
	else
		math->sx = -1;
	if (math->iso_y0 < math->iso_y1)
		math->sy = 1;
	else
		math->sy = -1;
	math->err = math->dx + math->dy;
	draw_line_cont(img, math, color);
}

void	fill_image(t_data *img, t_point *coord, int i, t_map *map)
{
	int	iso_x;
	int	iso_y;

	iso_x = (int)(map->offset_x + map->iso[i].x);
	iso_y = (int)(map->offset_y + map->iso[i].y);
	if (iso_x >= 0 && iso_x < WIDTH && iso_y >= 0 && iso_y < LEN)
		my_mlx_pixel_put(img, iso_x, iso_y, coord[i].color);
}

void	draw_line_between_points(t_data *img, t_map *map, int idx1, int idx2)
{
	t_math	math;

	math.iso_x0 = (int)(map->offset_x + map->iso[idx1].x);
	math.iso_y0 = (int)(map->offset_y + map->iso[idx1].y);
	math.iso_x1 = (int)(map->offset_x + map->iso[idx2].x);
	math.iso_y1 = (int)(map->offset_y + map->iso[idx2].y);
	draw_line(img, &math, map->iso[idx1].color);
}

void	draw_map_cont(t_map *map, t_data *img)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		if ((i + 1) % map->width != 0)
		{
			if (map->iso[i].color == 0)
				map->iso[i].color = 0x00FFFF;
			draw_line_between_points(img, map, i, i + 1);
		}
		if (i < map->size - map->width)
		{
			if (map->iso[i + 1].color == 0)
				map->iso[i].color = 0xFF00FF;
			draw_line_between_points(img, map, i, i + map->width);
		}
		i++;
	}
}
