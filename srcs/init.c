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

void init_map(t_map *map, char *filename)
{
	map->length = 0;
	map->width = 0;
	map->filename = filename;
	map->coord_array = NULL;
	map->scale = 1;
	map->bounce = 1;
	map->max = 0;
	map->min = 0;
}
