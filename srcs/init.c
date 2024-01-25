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

void	init_map(t_map *map, char *filename)
{
	map->length = 0;
	map->width = 0;
	map->filename = filename;
	map->coord_array = NULL;
	map->iso_array = NULL;
	map->scale = 1;
	map->max = 0;
	map->min = 0;
}

void	change_to_iso(t_map *map, t_point *coord)
{
	int		i;
	float left_x = FLT_MAX;
    float right_x = -FLT_MAX;
    float min_y = FLT_MAX;
    float max_y = -FLT_MAX;

	map->iso_array = (t_iso *)malloc(sizeof(t_iso) * map->size);
	if (!map->iso_array)
		return ;
	map->iso_array->x = 0;
	map->iso_array->y = 0;
	// map->iso_array->left_x = FLT_MIN;
	// map->iso_array->right_x = FLT_MAX;
	// map->iso_array->min_y = FLT_MIN;
	// map->iso_array->max_y = -FLT_MAX;
	// // i = 0;
	// while (i < map->size)
	// {
	// 	map->iso_array[i].y = get_iso_y(coord[i].x, coord[i].y, coord[i].z);
	// 	map->iso_array[i].x = get_iso_x(coord[i].x, coord[i].y);
	// 	if (map->iso_array[i].y < map->iso_array->min_y)
	// 		map->iso_array->min_y = map->iso_array[i].y;
	// 	if (map->iso_array[i].y > map->iso_array->max_y)
	// 		map->iso_array->max_y = map->iso_array[i].y;
	// 	if (map->iso_array[i].x < map->iso_array->left_x)
	// 		map->iso_array->left_x = map->iso_array[i].x;
	// 	if (map->iso_array[i].x > map->iso_array->right_x)
	// 		map->iso_array->right_x = map->iso_array[i].x;
	// 	i++;
	// }
	    for (i = 0; i < map->size; i++) {
        map->iso_array[i].x = get_iso_x(coord[i].x, coord[i].y);
        map->iso_array[i].y = get_iso_y(coord[i].x, coord[i].y, coord[i].z);

        if (map->iso_array[i].x < left_x) left_x = map->iso_array[i].x;
        if (map->iso_array[i].x > right_x) right_x = map->iso_array[i].x;
        if (map->iso_array[i].y < min_y) min_y = map->iso_array[i].y;
        if (map->iso_array[i].y > max_y) max_y = map->iso_array[i].y;
    }
    map->iso_array->left_x = left_x;
    map->iso_array->right_x = right_x;
    map->iso_array->min_y = min_y;
    map->iso_array->max_y = max_y;
}

// void scale_iso(t_map *map) {
//     // Ensure that right_x, left_x, max_y, and min_y are correctly calculated 
//     // and stored in the map structure prior to calling this function

//     float map_width = fabs(map->iso_array->right_x - map->iso_array->left_x);
//     float map_height = fabs(map->iso_array->max_y - map->iso_array->min_y);

//     float scale_width = (float)WIDTH / map_width;
//     float scale_height = (float)LEN / map_height;

//     map->scale = fmin(scale_width, scale_height);

//     for (int i = 0; i < map->size; i++) {
//         map->iso_array[i].x *= map->scale;
//         map->iso_array[i].y *= map->scale;
//     }
// }


void	scale_iso(t_map *map)
{
	float	scale_width;
	float	scale_length;
	float	map_width;
	float	map_len;
	int		i;

	map_len = map->iso_array->max_y - map->iso_array->min_y;
	map_width = map->iso_array->left_x - map->iso_array->right_x;
	scale_width = (float)WIDTH / map_width;
	scale_length = (float)LEN / map_len;

	if (scale_width < scale_length)
		map->scale = scale_width;
	else if (scale_length < scale_width)
		map->scale = scale_length;
	i = 0;
	while (i < map->size)
	{
		map->iso_array[i].x *= map->scale;
		map->coord_array[i].y *= map->scale;
		i++;
	}
}