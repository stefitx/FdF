/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:05:29 by atudor            #+#    #+#             */
/*   Updated: 2024/01/15 19:05:32 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

int	get_iso_x(float x, float y)
{
	int	iso_x;
	double angle = 30 * M_PI / 180;

	iso_x = (x - y) * cos(angle);
	return(iso_x);
}

int	get_iso_y(float x, float y, float z)
{
	int	iso_y;
	double angle = 30 * M_PI / 180;

	iso_y = (x + y) * sin(angle) - z;
	return(iso_y);
}

// void	change_to_iso(t_map *map, t_point *coord)
// {
// 	int		i;
// 	float left_x = FLT_MAX;
//     float right_x = -FLT_MAX;
//     float min_y = FLT_MAX;
//     float max_y = -FLT_MAX;

// 	map->iso_array = (t_iso *)malloc(sizeof(t_iso) * map->size);
// 	if (!map->iso_array)
// 		return ;
// 	map->iso_array->x = 0;
// 	map->iso_array->y = 0;
// 	i = 0;
// 	while (i < map->size)
// 	{
// 		map->iso_array[i].y = get_iso_y(coord[i].x, coord[i].y, coord[i].z);
// 		map->iso_array[i].x = get_iso_x(coord[i].x, coord[i].y);
// 		if (map->iso_array[i].y < min_y)
// 			min_y = map->iso_array[i].y;
// 		if (map->iso_array[i].y > max_y)
// 			max_y = map->iso_array[i].y;
// 		if (map->iso_array[i].x < left_x)
// 			left_x = map->iso_array[i].x;
// 		if (map->iso_array[i].x > right_x)
// 			right_x = map->iso_array[i].x;
// 		i++;
// 	}
//     map->iso_array->left_x = left_x;
//     map->iso_array->right_x = right_x;
//     map->iso_array->min_y = min_y;
//     map->iso_array->max_y = max_y;
// }

