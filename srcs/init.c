/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:48:24 by atudor            #+#    #+#             */
/*   Updated: 2024/01/19 13:48:33 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	init_map(t_map *map, char *filename, void *mlx, void *win)
{
	map->length = 0;
	map->width = 0;
	map->filename = filename;
	map->coord_array = NULL;
	map->iso_array = NULL;
	map->scale = 1;
	map->offset_x = 0;
	map->offset_y = 0;
	map->min_iso_x = FLT_MAX;
	map->min_iso_y = FLT_MAX;
	map->max_iso_x = -FLT_MAX;
	map->max_iso_y = -FLT_MAX;
	map->mlx = mlx;
    map->win = win;
}

void	change_to_iso(t_map *map, t_point *coord)
{
	int	i;

	map->iso_array = (t_iso *)malloc(sizeof(t_iso) * map->size);
	if (!map->iso_array)
		return ;
	i = 0;
	while (i < map->size)
	{
		map->iso_array[i].x = get_iso_x(coord[i].x, coord[i].y, coord[i].z);
		map->iso_array[i].y = get_iso_y(coord[i].x, coord[i].y, coord[i].z);
		map->iso_array[i].color = map->coord_array[i].color;
		if (map->iso_array[i].x < map->min_iso_x)
            map->min_iso_x = map->iso_array[i].x;
        if (map->iso_array[i].x > map->max_iso_x)
            map->max_iso_x = map->iso_array[i].x;
        if (map->iso_array[i].y < map->min_iso_y)
            map->min_iso_y = map->iso_array[i].y;
        if (map->iso_array[i].y > map->max_iso_y)
            map->max_iso_y = map->iso_array[i].y;
	i++;
	}
}

void scale_iso(t_map *map)
{
	float	map_w; 
	float	map_h;
	int		i;


	map_w = map->max_iso_x - map->min_iso_x;
	map_h = map->max_iso_y - map->min_iso_y;
	map->scale = fmin((float)WIDTH / (map_w + 10), (float)LEN / (map_h + 10));
	i = 0;
	while (i < map->size)
	{
		map->iso_array[i].x = (map->iso_array[i].x - map->min_iso_x) * map->scale;
		map->iso_array[i].y = (map->iso_array[i].y - map->min_iso_y) * map->scale;
		i++;
	}
	map->offset_x = (WIDTH / 2) - ((map_w * map->scale) / 2);
	map->offset_y = (LEN / 2) - ((map_h * map->scale) / 2);
}
