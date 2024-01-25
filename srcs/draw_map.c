/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:12:20 by atudor            #+#    #+#             */
/*   Updated: 2024/01/14 20:12:23 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

// int	rendering(t_data img)

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void fill_image(t_data *img, t_point *coord, int i, t_map *map) {
    int iso_x = (int)((WIDTH / 2) + map->iso_array[i].x);
    int iso_y = (int)((LEN / 2) + map->iso_array[i].y);
    
    if (iso_x >= 0 && iso_x < WIDTH && iso_y >= 0 && iso_y < LEN) {
        my_mlx_pixel_put(img, iso_x, iso_y, coord[i].color);
    }
}

// void fill_image(t_data *img, t_point *coord, int i, t_map *map)
// {
// 	// change_to_iso(map, coord);
// 	// scale_iso(map);
// 	if ((WIDTH/2) + map->iso_array[i].x < WIDTH && (LEN/4) + map->iso_array[i].y < LEN)
// 		my_mlx_pixel_put(img, (int)((WIDTH/2) + map->iso_array->x), (int)((LEN/4) + map->iso_array->y), coord[i].color);
// }

// void draw_map(void *mlx, void *win, t_map *map)
// {
//     t_data img;
//     int	i;

//     img.img = mlx_new_image(mlx, WIDTH, LEN);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//     ///scale_coord(map);
//     i = 0;
//     while (i < map->size)
//     {
//     	fill_image(&img, map->coord_array, i, map);
//     	i++;
//     }
//     mlx_put_image_to_window(mlx, win, img.img, 0, 0);
// }

void draw_map(void *mlx, void *win, t_map *map) {
    t_data img;
    int i;

    // Convert to isometric and scale outside of the drawing loop
    change_to_iso(map, map->coord_array);
    scale_iso(map);

    img.img = mlx_new_image(mlx, WIDTH, LEN);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    for (i = 0; i < map->size; i++) {
        fill_image(&img, map->coord_array, i, map);
    }

    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
}
